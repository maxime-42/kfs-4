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


void isr_handler(t_interrupt_frame frame)
{
	// ft_putstr("Recived exception\n");
	// char *str = itoa_base(registers.int_no, 10);
	// uint8 size_exception_messages = sizeof(exception_messages);
	char *p = itoa_base(frame.int_no, 10);
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


void acknowledge(unsigned int interrupt)
{
	// if (interrupt >= PIC_1_OFFSET && interrupt <= PIC_2_END)
	// {
	// 	if (interrupt < PIC_2_OFFSET)
	// 		outb(PIC_1_COMMAND, PIC_ACKNOWLEDGE);
	// 	else
	// 		outb(PIC_2_COMMAND, PIC_ACKNOWLEDGE);
	// }

	 if (interrupt >= 40)	
    {
        /* reset signal to slave */
        outb(0xA0, 0x20);
    }
    /* reset signal to master */
    outb(0x20, 0x20);
}

void irq_handler( t_interrupt_frame frame)
{
	// panic();
		acknowledge(frame.int_no);

	if (get_interrupt_handler(frame.int_no) != 0)
    {
		// ft_putstr("IRQ Handler declencher\n");
        t_interrupt_handler handler = get_interrupt_handler(frame.int_no);
        handler(frame);
    // outb(0x20, 0x20);        outb(0xA0, 0x20);

    }


}