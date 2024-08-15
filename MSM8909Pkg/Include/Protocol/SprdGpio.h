#ifndef __SPRD_GPIO_H__
#define __SPRD_GPIO_H__

#define SPRD_GPIO_GUID                                             \
  {                                                                            \
    0xfac1b8a5, 0x8ce6, 0x4cbc,                                                \
    {                                                                          \
      0xad, 0x09, 0xa3, 0xb8, 0x2a, 0x82, 0x45, 0xe9                           \
    }                                                                          \
  }

//
// Protocol interface structure
//
typedef struct _SPRD_GPIO SPRD_GPIO;

typedef
UINT32
(*GPIO_GET)(
  UINT32 gpioNumber
  );

struct _SPRD_GPIO {
  GPIO_GET         Get;
};

extern EFI_GUID  gSprdGpioProtocolGuid;

#endif