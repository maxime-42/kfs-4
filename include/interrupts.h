#ifndef _INTERRUPTS_H
#define _INTERRUPTS_H
#include <stdint.h>

/* ************************************************************************** */
/* 			Structs                                               */
/* ************************************************************************** */

/*
	this ructure provides a convenient way to access the CPU register 
	values and other relevant information during interrupt or exception 
	handling 
*/
typedef struct __attribute__((packed)) registers
{
    uint32_t ds; 
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
    uint32_t int_no;
    uint32_t err_code; 
    uint32_t eip;
    uint32_t cs;
    uint32_t eflags;
    uint32_t useresp;
    uint32_t ss; 
} t_registers; 




/* ************************************************************************** */
/* 			Prototy                                               */
/* ************************************************************************** */


typedef  void (*t_interrupt_handler)(t_registers);
void			irq_handler(t_registers regs);
void			pic_map(void);
extern	void	panic();
void			init_handlers(void);
int				add_handler(uint32_t n, t_interrupt_handler handler);
t_interrupt_handler get_interrupt_handler(uint32_t n);


/* ************************************************************************** */
/* 			Prototy isr                                               */
/* ************************************************************************** */

extern void isr0(void);
extern void isr1(void);
extern void isr2(void);
extern void isr3(void);
extern void isr4(void);
extern void isr5(void);
extern void isr6(void);
extern void isr7(void);
extern void isr8(void);
extern void isr9(void);
extern void isr10(void);
extern void isr11(void);
extern void isr12(void);
extern void isr13(void);
extern void isr14(void);
extern void isr15(void);
extern void isr16(void);
extern void isr17(void);
extern void isr18(void);
extern void isr19(void);
extern void isr20(void);
extern void isr21(void);
extern void isr22(void);
extern void isr23(void);
extern void isr24(void);
extern void isr25(void);
extern void isr26(void);
extern void isr27(void);
extern void isr28(void);
extern void isr29(void);
extern void isr30(void);
extern void isr31(void);
// extern void isr32(void);


/* ************************************************************************** */
/* 			Prototy irq                                               */
/* ************************************************************************** */
extern void irq0(void);
extern void irq1(void);
extern void irq2(void);
extern void irq3(void);
extern void irq4(void);
extern void irq5(void);
extern void irq6(void);
extern void irq7(void);
extern void irq8(void);
extern void irq9(void);
extern void irq10(void);
extern void irq11(void);
extern void irq12(void);
extern void irq13(void);
extern void irq14(void);
extern void irq15(void);
#endif // !_INTERRUPTS_H
