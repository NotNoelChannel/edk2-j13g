[Defines]
  PLATFORM_NAME                  = MSM8909Pkg
  PLATFORM_GUID                  = 28f1a3bf-193a-47e3-a7b9-5a435eaab2ee
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010019
  OUTPUT_DIRECTORY               = Build/$(PLATFORM_NAME)
  SUPPORTED_ARCHITECTURES        = ARM
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = MSM8909Pkg/MSM8909Pkg.fdf

!include MSM8909Pkg/MSM8909Pkg.dsc

[PcdsFixedAtBuild.common]
  # System Memory (512MB)
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x80000000
  gArmTokenSpaceGuid.PcdSystemMemorySize|0x20000000          # 512MB = 0x20000000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x80C00000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00040000       # 256K stack
  gMSM8909PkgTokenSpaceGuid.PcdUefiMemPoolBase|0x80D00000    # DXE Heap base address
  gMSM8909PkgTokenSpaceGuid.PcdUefiMemPoolSize|0x073B0000    # UefiMemorySize, DXE heap size (adjusted if needed)
  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0x80C40000

  # Framebuffer (1024x600)
  gMSM8909PkgTokenSpaceGuid.PcdMipiFrameBufferAddress|0x9eef4000
  gMSM8909PkgTokenSpaceGuid.PcdMipiFrameBufferWidth|480
  gMSM8909PkgTokenSpaceGuid.PcdMipiFrameBufferHeight|800
  gMSM8909PkgTokenSpaceGuid.PcdMipiFrameBufferVisibleWidth|480
  gMSM8909PkgTokenSpaceGuid.PcdMipiFrameBufferVisibleHeight|800
  gMSM8909PkgTokenSpaceGuid.PcdMipiFrameBufferPixelBpp|16

  gMSM8909PkgTokenSpaceGuid.GpioBase|0xf5224000