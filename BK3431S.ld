ENTRY(_mainCRTStartup)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K
  SRAM (rwx) : ORIGIN = 0x00400000, LENGTH = 24K
}

SECTIONS
{
  .text :
  {
    KEEP(*(.isr_vector))
    . = ALIGN(4);
    *(.init)
    *(.fini)
    *(.text)
    *(.text.*)
    *(fastcall)
    *(i.*)
    . = ALIGN(4);
    *(.rodata)
    *(.rodata.*)
    *(.constdata)
    . = ALIGN(4);
    _etext = .;
  } > FLASH

  .data :
  {
    _sdata = .;
    *(.data)
    *(.data.*)
    *(.init_array)
    *(.init_array.*)
    *(.fini_array)
    *(.data__*)
    . = ALIGN(4);
    _edata = .;
  } > SRAM AT> FLASH

  .bss :
  {
    _sbss = .;
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss.*)
    . = ALIGN(4);
    _ebss = .;
    __bss_end__ = _ebss;
     . = ALIGN(4);
    end = .;
    __end__ = .;
  } > SRAM

  .stack :
  {
    _past_eosram = ORIGIN(SRAM) + LENGTH(SRAM);
    _irq_stack_top = _past_eosram - 4;
    _fiq_stack_top = _irq_stack_top - 512;
    _svc_stack_top = _fiq_stack_top - 1024;
    _sys_stack_top = _svc_stack_top - 2048;
  } > SRAM
}