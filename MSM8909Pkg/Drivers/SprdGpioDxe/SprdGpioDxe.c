/*
 * Copyright (c) 2024, Dodo viC <vicenteicc2008@gmail.com>
 * Based on the open source driver from edk2-tensor and the key reading code from the uniLoader fork by BotchedRPR
 */

#include <Uefi.h>

#include <Library/BaseLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/BaseMemoryLib.h>
#include <Protocol/SprdGpio.h>

UINT32 GpioBase = FixedPcdGet32(GpioBase);

UINT32
gpio_get(UINT32 gpioNumber)
{
    UINT32 val = -1;

    val = (MmioRead32(GpioBase) >> gpioNumber) & 0x1;

    if(val == -1) DEBUG((EFI_D_ERROR, "Error Reading GPIO\n"));

    return val;
}

SPRD_GPIO  gSprdGpio = {
  gpio_get
};

EFI_STATUS
EFIAPI
SprdGpioDxeInitialize(
	IN EFI_HANDLE         ImageHandle,
	IN EFI_SYSTEM_TABLE   *SystemTable
)
{
  EFI_STATUS  Status = EFI_SUCCESS;
  EFI_HANDLE  Handle = NULL;

  //
  // Make sure the Spreadtrum Gpio protocol has not been installed in the system yet.
  //
  ASSERT_PROTOCOL_ALREADY_INSTALLED (NULL, &gSprdGpioProtocolGuid);

  // Install the GPIO Protocol onto a new handle
  Status = gBS->InstallMultipleProtocolInterfaces (
                  &Handle,
                  &gSprdGpioProtocolGuid,
                  &gSprdGpio,
                  NULL
                  );
  if (EFI_ERROR (Status)) {
    Status = EFI_OUT_OF_RESOURCES;
  }

	return Status;
}