#include "io.h"
#include "interrupts.h"
#include "libk.h"
#include "config.h"


void irq_handler(t_registers regs)
{
	ft_putstr("IRQ Handler declencher\n");
	if (regs.int_no >= 40)	
    {
        /* reset signal to slave */
        outb(0xA0, 0x20);
    }
    /* reset signal to master */
    outb(0x20, 0x20);
	// panic();

	if (get_interrupt_handler(regs.int_no) != 0)
    {
        t_interrupt_handler handler = get_interrupt_handler(regs.int_no);
        handler(regs);
    }
	(void)regs;
}