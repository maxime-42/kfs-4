#include "interrupts.h"
#include "libk.h"
#include "config.h"



char * exception_messages[] = {
"Division By Zero\n", 
"Debug\n", 
"Non Maskable Interrupt Exception", 
"Breakpoint Exception\n","Overflow\n", 
"Bound Range Exceeded\n", 
"Invalid Opcode\n",  
"Device Not Available\n", 
"Double Fault\n", 
"Invalid TSS\n", 
"Segment Not Present\n",
"Stack-Segment Fault\n", 
"General Protection Fault\n",  
"Page Fault\n" };
void isr_handler(t_registers registers)
{
	ft_putstr("Recived exception\n");
	// char *str = itoa_base(registers.int_no, 10);
	char *msg_ptr = exception_messages[registers.int_no];
	ft_putstr(msg_ptr);
	(void)registers;
	panic();

	return ;
}			