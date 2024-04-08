#include "keyboard.h"
#include "libk.h"
#include "io.h"

t_keyboard_buffer keyb_buf;
/*this function  will be called when a keyboard interrupt is triggered  */
void	init_keyboard_buffer()
{
	kmemset(&keyb_buf, 0, sizeof(keyb_buf.buffer));
}

int get_tail_index()
{
	return keyb_buf.head % sizeof(keyb_buf.buffer);
}

int get_head_index()
{
	return keyb_buf.head % sizeof(keyb_buf.buffer);
}



/*****************************
 * @brief: add data to buffer
 * @param data : the char you want to push into buffer
 * @Return:  1-success ,0-fail
 * ****************************/
int put_char_to_buffer(unsigned char data)
{
	if(data == 0)
        return  0;
	if (keyb_buf.head >= KEYB_BUFLEN )
	{
		keyb_buf.head = 0;
	}
	else
	{
        // outb(KEYBOARD_DATA_PORT, 0);

		// store new char to buffer and increase head index
		keyb_buf.buffer[keyb_buf.head++] = data;
		// {
			ft_putstr(keyb_buf.buffer);
		// }
		ft_putchar('\n');
			outb(KEYBOARD_DATA_PORT, 0);

	}
	return  1;
}