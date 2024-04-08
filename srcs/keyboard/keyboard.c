#include "interrupts.h"
#include "config.h"
#include "libk.h"
#include "io.h"
#include "idt.h"
#include "keyboard.h"

static char azerty_kb_table[128] = {
	0, 0, '&', 0, '"', '\'', '(', 0, 0, '!', 0, 0, ')', '-', '\b', 0, 'a', 'z',
    'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '^', '$', '\n', 0, 'q', 's', 'd',
    'f', 'g', 'h', 'j', 'k', 'l', 'm', 0, '<', 0, '`', 'w', 'x', 'c', 'v', 'b',
    'n', ',', ';', ':', '=', 0, '*', 0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, '7', '8', '9', '-', '4', '5', '6', '+', '1', '2', '3', '0', '.', '6',
	0, 0, 0, 0, 0
};



/*****************************
 * @brief:This function is called when a key has been pressed on the keyboard. 
 * @param:frame  - A pointer to the frame of the interrupt stack
 */
static void keyboard_handler(t_interrupt_frame frame)
{
	uint16    scan_code = inb(KEYBOARD_DATA_PORT) & 0x7F;/********** Get the data from the port **********/
	char      character = azerty_kb_table[scan_code]; /******* Translate to ASCII if possible *******/

	inb(KEYBOARD_DATA_PORT) ;
	uint16    pressRelease = inb(KEYBOARD_DATA_PORT) & 0X80;
    
	if (pressRelease)//If it's a release we don't care about it for now
        return;
	else
	{
		outb(KEYBOARD_DATA_PORT, 0);
		put_char_to_buffer(character);

	}
	(void)frame;	
}


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