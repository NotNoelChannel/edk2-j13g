#ifndef __CLOCK_MANAGEMENT_PROTOCOL_H__
#define __CLOCK_MANAGEMENT_PROTOCOL_H__

#define SPRD_CLOCK_MANAGEMENT_PROTOCOL_GUID \
    { 0xb2c7cf0b, 0xf42d, 0x42d2, { 0x84, 0x03, 0x86, 0x12, 0x28, 0xdb, 0xc7, 0x6e } }

typedef struct _SPRD_CLOCK_MGMT_PROTOCOL SPRD_CLOCK_MGMT_PROTOCOL;

typedef BOOLEAN    (EFIAPI *clk_sdmmc_query_clk_not_reset_and_enabled_t)(UINT32 Index);
typedef EFI_STATUS (EFIAPI *clk_sdmmc_get_params_t)(UINT32 *pOut, UINT16 *pDivisor, UINT32 Type);
typedef EFI_STATUS (EFIAPI *clk_sdmmc_enable_t)(UINT32 Index, UINT32 Clock);
typedef EFI_STATUS (EFIAPI *clk_sdmmc_disable_t)(UINT32 Index);
typedef EFI_STATUS (EFIAPI *clk_sdmmc_sel_clk_src_t)(UINT32 *pOut, UINT32 Index, UINT32 Value);

struct _SPRD_CLOCK_MGMT_PROTOCOL {
	clk_sdmmc_query_clk_not_reset_and_enabled_t QuerySdMmcClkNotResetAndEnabled;
    clk_sdmmc_get_params_t  QuerySdMmcClkParams;
    clk_sdmmc_enable_t      EnableSdMmcClk;
    clk_sdmmc_sel_clk_src_t SelectSdMmcClkSource;
    clk_sdmmc_disable_t     DisableSdMmcClk;
};

extern EFI_GUID gSprdClockProtocolGuid;

#endif