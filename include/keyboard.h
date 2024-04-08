#ifndef _KEYBOARD_H
#define _KEYBOARD_H 
#include "config.h"

void init_keyboard();
#define KEYB_BUFLEN	1024
# define IS_RELEASED(keycode) keycode & 0x80


typedef struct	keyboard_buffer
{
	char		buffer[KEYB_BUFLEN];
	uint16		tail; //incrmente during push*
	uint16		head; //incremente during decrementaton*
}	t_keyboard_buffer;


void	init_keyboard_buffer();
int		put_char_to_buffer(unsigned char data);


#endif // !_KEYBOARD_H
