#ifndef _DEVICE_MEMORY_MAP_H_
#define _DEVICE_MEMORY_MAP_H_

#include <Library/ArmLib.h>

#define MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT 64

/* Below flag is used for system memory */
#define SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES                               \
  EFI_RESOURCE_ATTRIBUTE_PRESENT | EFI_RESOURCE_ATTRIBUTE_INITIALIZED |        \
      EFI_RESOURCE_ATTRIBUTE_TESTED | EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |     \
      EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE |                               \
      EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE |                         \
      EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE |                            \
      EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTABLE

typedef enum { NoHob, AddMem, AddDev, HobOnlyNoCacheSetting, MaxMem } DeviceMemoryAddHob;

#define MEMORY_REGION_NAME_MAX_LENGTH 32

typedef struct {
  EFI_PHYSICAL_ADDRESS         Address;
  UINT64                       Length;
  CHAR8                        Name[MEMORY_REGION_NAME_MAX_LENGTH];
  DeviceMemoryAddHob           HobOption;
  EFI_RESOURCE_TYPE            ResourceType;
  EFI_RESOURCE_ATTRIBUTE_TYPE  ResourceAttribute;
  EFI_MEMORY_TYPE              MemoryType;
  ARM_MEMORY_REGION_ATTRIBUTES ArmAttributes;
} ARM_MEMORY_REGION_DESCRIPTOR_EX, *PARM_MEMORY_REGION_DESCRIPTOR_EX;

#define MEM_RES EFI_RESOURCE_MEMORY_RESERVED
#define MMAP_IO EFI_RESOURCE_MEMORY_MAPPED_IO
#define SYS_MEM EFI_RESOURCE_SYSTEM_MEMORY

#define SYS_MEM_CAP SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES
#define INITIALIZED EFI_RESOURCE_ATTRIBUTE_INITIALIZED
#define WRITE_COMBINEABLE EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE
#define UNCACHEABLE EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE

#define Reserv EfiReservedMemoryType
#define Conv EfiConventionalMemory
#define BsData EfiBootServicesData
#define RtData EfiRuntimeServicesData
#define LdData EfiLoaderData
#define MmIO EfiMemoryMappedIO
#define MaxMem EfiMaxMemoryType
#define BsCode EfiBootServicesCode
#define RtCode EfiRuntimeServicesCode

#define DEVICE ARM_MEMORY_REGION_ATTRIBUTE_DEVICE
#define WRITE_THROUGH ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH
#define WRITE_THROUGH_XN ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH
#define WRITE_BACK ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK
#define WRITE_BACK_XN ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK
#define UNCACHED_UNBUFFERED ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED
#define UNCACHED_UNBUFFERED_XN ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
//                                                    EFI_RESOURCE_ EFI_RESOURCE_ATTRIBUTE_        ARM_REGION_ATTRIBUTE_
//MemBase,   MemSize,   MemLabel(32 Char.), BuildHob, ResourceType, ResourceAttribute, MemoryType, CacheAttributes
//------------- DDR ------},
{0x80000000, 0x00010000, "HLOS 0",           AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
{0x80C00000, 0x00040000, "UEFI Stack",       AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
{0x80C40000, 0x00010000, "CPU Vectors",      AddMem, SYS_MEM, SYS_MEM_CAP, BsCode, WRITE_BACK},
{0x80024000, 0x001DC000, "HLOS 1",           AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
{0x80200000, 0x00200000, "UEFI FD",          AddMem, SYS_MEM, SYS_MEM_CAP, BsCode, WRITE_BACK},
{0x9eef4000, 0x00708000, "Display Reserved", AddMem, MEM_RES, WRITE_THROUGH, MaxMem, WRITE_THROUGH},
{0x80D00000, 0x0F3B0000, "HLOS 2",           AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
{0x87800000, 0x00240000, "SMEM",             AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED},

//------------- Register Regions ----------
{0x12001000, 0x00001000, "GIC Distributor",  AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
{0x12002000, 0x00001000, "GIC Redistributors",  AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
{0xf536a000, 0x00001000, "I2C 0",  			 AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
{0xf536c000, 0x00001000, "I2C 1",  			 AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
{0xf5370000, 0x00001000, "I2C 2",  			 AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
{0xf5372000, 0x00001000, "I2C 3",  			 AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
{0xf5224000, 0x00001000, "PinCtrl",          AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},

//------------- Terminator for MMU ----------
{0, 0, "Terminator", 0, 0, 0, 0, 0}

};

#endif

