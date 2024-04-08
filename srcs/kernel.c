#include "kernel.h"
#include "idt.h"
#include "gdt.h"
#include "keyboard.h"
#include "interrupts.h"

uint32 multi_two(uint32 n)
{
	return n * 2;
}

void	set_string()
{

	void *ptr = (void *)STRING_ADDRESS;
	char str[] = "hello world lenoxko";    	
	kmemcpy(ptr, str, sizeof(str));


}

// void	set_function()
// {

// 	uint32 eip;
// 	GET_EIP( eip); 
// 	void (*ptrFunction)() = (void (*)())MULTI_ADDRESS ;
// 	//void (*ptrFunction)() = (void (*)())eip;
// 	kmemcpy((void *)multi_two, (void *)ptrFunction, sizeof(multi_two));

// }

// extern void problem();
// extern int getkey();

void	kmain()
{

	terminal_initialize();

	init_gdt();


	// test_div();
	init_idt();	
	// test_div();

	// ft_putstr("\nhello world\n");
	// init_pit(100);
	// init_rtc();
	init_keyboard();
	// uint16 n = 12/0;
	// problem();
	while(42){
		// ft_putstr("hello");


	}

}
