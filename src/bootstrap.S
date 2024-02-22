.section .isr_vector

.global _stack_init

_isr_vectors:
    B _mainCRTStartup
    B _isr_invalid
    B _isr_invalid
    B _isr_invalid
    B _isr_invalid
    NOP
    B SYSirq_IRQ_Handler
    B SYSirq_FIQ_Handler

_isr_invalid:
    B _isr_invalid

.equ MODE_FIQ, 0xD1
.equ MODE_IRQ, 0xD2
.equ MODE_SVC, 0xD3
.equ MODE_SYS, 0xDF

_stack_init:
    LDR R4, =0xDEADBEEF @todo: init stacks elsewhere

    MOV R0, #MODE_IRQ
    MSR CPSR_c, R0
    LDR SP, =_irq_stack_top
    STR R4, [SP]

    MOV R0, #MODE_FIQ
    MSR CPSR_c, R0
    LDR SP, =_fiq_stack_top
    STR R4, [SP]

    MOV R0, #MODE_SVC
    MSR CPSR_c, R0
    LDR SP, =_svc_stack_top
    STR R4, [SP]

    MOV R0, #MODE_SYS
    MSR CPSR_c, R0
    LDR SP, =_sys_stack_top
    STR R4, [SP]

    BX LR

.end