/* Linker script to configure memory regions. */

SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x1b000, LENGTH = 0x25000
  RAM (rwx) :  ORIGIN = 0x20001fe8, LENGTH = 0x2018
}

SECTIONS
{
  .fs_data :
  {
    PROVIDE(__start_fs_data = .);
    KEEP(*(.fs_data))
    PROVIDE(__stop_fs_data = .);
  } > RAM
  .pwr_mgmt_data :
  {
    PROVIDE(__start_pwr_mgmt_data = .);
    KEEP(*(.pwr_mgmt_data))
    PROVIDE(__stop_pwr_mgmt_data = .);
  } > RAM
} INSERT AFTER .data;

SECTIONS
{
  .ram_retetion 0x20002000 (NOLOAD) : {
    PROVIDE(__start_ram_retention = .);
    KEEP(*(.ram_retetion))
    PROVIDE(__stop_ram_retention = .);
    . = ALIGN(4);
  } > RAM
}

INCLUDE "nrf5x_common.ld"
