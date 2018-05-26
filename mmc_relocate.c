#include "mmc_relocate.h"

void copy_code_to_dram(void)
{
	unsigned long ch;
	unsigned int ret;
	void (*BL2)(void);

	ch = *(volatile unsigned int *)(SDRAM_CHANNEL_BASE);
	copy_sd_mmc_to_mem copy_bl2 = (copy_sd_mmc_to_mem) (*(unsigned int *) (MASKROM_MMC_COPY_BASE));
	if (ch == 0xEB000000)
	{

		ret = copy_bl2(0, UBOOT_LOAD_BASE, 2048,(unsigned int *)NEXT_FIRMWARE_LDS_BASE, 0);
	}

	else if (ch == 0xEB200000)
	{
		ret = copy_bl2(2, UBOOT_LOAD_BASE, 2048,(unsigned int *)NEXT_FIRMWARE_LDS_BASE, 0);
	}
	else
		return;

    BL2 = (void *)NEXT_FIRMWARE_LDS_BASE;
    (*BL2)();
}
