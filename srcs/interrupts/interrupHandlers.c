#include "interrupts.h"
#include "libk.h"
#include "io.h"
#include "config.h"

extern t_interrupt_handler  handlers[MAX_HANDLERS];


char * exception_messages[] = {
"Interdit to Division By Zero\n", 
"Debug\n",
"Non Maskable Interrupt Exception\n", 
"Breakpoint Exception\n",
"Overflow\n", 
"Bound Range Exceeded\n", 
"Invalid Opcode\n",
"Coprocessor not available\n",
"Double Fault\n", 
"Coprocessor Segment Overrun\n",
"Invalid TSS\n", 
"Segment Not Present\n",
"Stack Fault",
"General Protection Fault\n", 
"Page Fault\n",  
"Reserved\n", 
"Floating Point Error\n",  
"Alignment Check\n",  
"Machine Check\n",  
"SIMD Floating-Point Exception\n"};

/*******************************************
 * @brief: This function is the handler of the interrupt
 * @param: t_interrupt_frame *frame
 * @return : void
 ******************************************/

void isr_handler(t_interrupt_frame frame)
{
	// ft_putstr("Recived exception\n");
	// char *str = itoa_base(registers.int_no, 10);
	// uint8 size_exception_messages = sizeof(exception_messages);
	//char *p = itoa_base(frame.int_no, 10);
	// ft_putstr(p);
	// ft_putchar('\n');
	if ( frame.int_no < NB_EXCEPTION)
	{
		char *msg_ptr = exception_messages[frame.int_no];
		ft_putstr(msg_ptr);
		kpanic();
		// KPANIC("");
	}
	return ;
}

/************************************************
 * @brief:  This function acknowledging interrupts generated by the PIC 
 * @param:  t_interrupt_frame *frame
 * @return : void
 ***********************************************/

void acknowledge(unsigned int interrupt)
{

	 if (interrupt >= 40)	
    {
        /* reset signal to slave */
        outb(0xA0, 0x20);
    }
    /* reset signal to master */
    outb(0x20, 0x20);
}


/**********************************************
 * @brief:  handle the exceptions (sofware interrupt )
 * @param:  t_interrupt_frame *frame
 * @return : void
 ***********************************************/
void irq_handler( t_interrupt_frame frame)
{
	acknowledge(frame.int_no);
	if (get_interrupt_handler(frame.int_no) != 0)
    {
        t_interrupt_handler handler = get_interrupt_handler(frame.int_no);
        handler(frame);
    }


}