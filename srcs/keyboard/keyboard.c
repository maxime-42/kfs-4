#include "interrupts.h"
#include "config.h"
#include "libk.h"
#include "io.h"
#include "idt.h"

static void keyboard_handler(t_registers regs)
{
	ft_putstr("Key board interrupt triggered\n");
	(void)regs;
}
// extern void enable_interrupts();



void init_keyboard()
{
	// enable_interrupts();

	// outb(0x64, 0xAE);// active le port PS2

    add_handler(33, &keyboard_handler);
	// enable_interrupts();
	
 	// ft_putstr("wshh\n");

}