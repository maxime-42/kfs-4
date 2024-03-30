#include "kernel.h"
#include "idt.h"
#include "keyboard.h"

uint32_t multi_two(uint32_t n)
{
	return n * 2;
}

void	set_string()
{

	void *ptr = (void *)STRING_ADDRESS;
	char str[] = "hello world lenoxko";    	
	kmemcpy(ptr, str, sizeof(str));


}

void	set_function()
{

	uint32_t eip;
	GET_EIP( eip); 
	void (*ptrFunction)() = (void (*)())MULTI_ADDRESS ;
	//void (*ptrFunction)() = (void (*)())eip;
	copyFunction((void *)multi_two, (void *)ptrFunction, sizeof(multi_two));

}

extern void test_();
extern int getkey();

void	kmain()
{

	terminal_initialize();

	init_gdt();


	// test_div();
	init_idt();	
	// test_div();

	// ft_putstr("\nhello world\n");s
	//test_();
	// init_pit(100);
	// init_rtc();
	init_keyboard();
	while(42){
		// ft_putstr("hello");


	}

}
