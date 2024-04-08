#include "io.h"
#include "interrupts.h"
#include "config.h"




void pic_map(void)
{
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);

	enable_interrupts();

}

void pic_remap(uint8 offset1, uint8 offset2)
{
	outb(PIC_1_COMMAND, PIC_ICW1_INIT + PIC_ICW1_ICW4);
	outb(PIC_2_COMMAND, PIC_ICW1_INIT + PIC_ICW1_ICW4);
	
	outb(PIC_1_DATA, OFFSET1);
	outb(PIC_2_DATA, OFFSET2);
	
	outb(PIC_1_DATA, 4);
	outb(PIC_2_DATA, 2);

	outb(PIC_1_DATA, PIC_ICW4_8086);
	outb(PIC_2_DATA, PIC_ICW4_8086);

	outb(PIC_1_DATA, INTERRUPT_MASK_KEYBOARD);
	outb(PIC_2_DATA, INTERRUPT_MASK_RESERVED);

	//asm volatile("sti");
	enable_interrupts();
	(void)offset1;
	(void)offset2;
}

