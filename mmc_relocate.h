#ifndef __MMC_RELOCATE_H_
#define __MMC_RELOCATE_H_

typedef unsigned int (*copy_sd_mmc_to_mem) (unsigned int  channel, unsigned int  start_block, unsigned char block_size, unsigned int  *trg, unsigned int  init);

#define SDRAM_CHANNEL_BASE           0xD0037488
#define MASKROM_MMC_COPY_BASE        0xD0037F98
#define NEXT_FIRMWARE_LDS_BASE       0x24000000
#define UBOOT_LOAD_BASE              8193
#define UBOOT_LOAD_SIZE              2048

#endif
