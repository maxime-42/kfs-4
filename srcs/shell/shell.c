#include "libk.h"
#include "kernel.h"
#include "keyboard.h"
#include "shell.h"
#include "commands.h"
#include "interrupts.h"

/*
*	check_new_line
*		check if the last char is a new line
*		return 1 if it is a new line
*		return 0 if it is not a new line
*/
static uint32		check_new_line()
{

		// ft_putstr("keyb_buf.buffer");
		if (get_last_char() == '\n')
		{
			
			// init_keyboard_buffer();
			// kmemest(keyb_buf.buffer, 0, sizeof(keyb_buf.buffer));
			// clear_buffer();
			return NEW_LINE;

		}
	return NO_NEW_LINE;
}

/*****************************
 * @brief: exec command from keyboard buffer
 * @return: void
 *
 * ****************************/
void		exec_command(void)
{

	char *ptr_buf =  get_keyboard_buffer();

	if (strcmp(ptr_buf, "azerty\n")  == 0)
	{
		set_keyboard_layout(AZERTY);
	}
	else if (strcmp(ptr_buf, "qwerty\n")  == 0)
	{
		set_keyboard_layout(QWERTY);
	}
	else if (strcmp(ptr_buf, "shutdown\n")  == 0)
	{
		qemu_shutdown();
	}
	else if (strcmp(ptr_buf, "stack\n")  == 0)
	{
		    // uint32	esp, ebp;
			// GET_ESP(esp);
			// GET_EBP(ebp);
			uint32 addr = 0X000007C0 - 32;
			print_stack(&addr, 10);
			// print_stack(ebp,  10);
	}
	else if (strcmp(ptr_buf, "panic\n")  == 0)
	{
		uint32 addr = 0X000007C0 - 32;
		print_stack(&addr, 10);
		kpanic();

	}


	clear_buffer();
}

void		shell(void)
{
	uint8	ret = 0;
	while (1)
	{
		if (ret == NEW_LINE)
		{
			exec_command();
			ft_putstr("$> ");
		}

		ret = check_new_line();
	}
	
}