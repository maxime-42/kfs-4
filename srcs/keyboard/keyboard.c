#include "interrupts.h"
#include "config.h"
#include "libk.h"
#include "io.h"
#include "idt.h"

static char azerty_kb_table[128] = {
	0, 0, '&', 0, '"', '\'', '(', 0, 0, '!', 0, 0, ')', '-', '\b', 0, 'a', 'z',
    'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '^', '$', '\n', 0, 'q', 's', 'd',
    'f', 'g', 'h', 'j', 'k', 'l', 'm', 0, '<', 0, '`', 'w', 'x', 'c', 'v', 'b',
    'n', ',', ';', ':', '=', 0, '*', 0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, '7', '8', '9', '-', '4', '5', '6', '+', '1', '2', '3', '0', '.', '6',
	0, 0, 0, 0, 0
};

static void keyboard_handler(t_interrupt_frame frame)
{
	// ft_putstr("Key board interrupt triggered\n");
	uint16    scan_code = inb(KEYBOARD_DATA_PORT) & 0x7F;;
	uint16    pressRelease = inb(KEYBOARD_DATA_PORT) & 0X80;
    char *tab = azerty_kb_table;
	//  outb(KEYBOARD_DATA_PORT, 0);
	// char *str = itoa_base(scan_code, 10);
	ft_putchar(tab[scan_code]);
	ft_putchar('\n');

	(void)frame;
	(void)pressRelease;
	
}
// extern void enable_interrupts();



void init_keyboard()
{
	// enable_interrupts();

	// outb(0x64, 0xAE);// active le port PS2

    int ret = add_handler(33, &keyboard_handler);
	// enable_interrupts();
	// if (ret == -1)
 	// 	ft_putstr("Echec add handler\n");
	// else{
 	// 	ft_putstr("handler has been add in tab\n");
	// 	// enable_interrupts();

	// }
	(void)ret;
}