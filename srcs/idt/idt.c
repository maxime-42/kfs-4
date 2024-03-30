#include "idt.h"
#include "config.h"
#include "libk.h"
#include "interrupts.h"

struct idt_entry idt_entries[TOTAL_INTERRUPTS];
struct idtr_desc idtr_descriptor;

	extern	void	panic();

// static void idt_set(int index, void *address)
static void idt_set(int index, uint32_t address)
{
	idt_entries[index].offset_1 = (uint32_t) address & 0x0000ffff;
	idt_entries[index].selector = CODE_SELECTOR;
	idt_entries[index].zero = 0;
	idt_entries[index].flags = 0x8E;
	// idt_entries[index].offset_2 = (uint32_t) address >> 16;
	idt_entries[index].offset_2 = (address >> 16) & 0xFFFF;
}




void	init_idt()
{
	kmemset(idt_entries, 0, sizeof(idt_entries) );
	// kmemset(idt_entries, 0, sizeof(struct idt_desc) * TOTAL_INTERRUPTS - 1);
	idtr_descriptor.limit = sizeof(idt_entries) -1;
	idtr_descriptor.base = (uint32_t) idt_entries;

	init_handlers();
	pic_map();


	/* Set up the system call interrupt */
	/*idt_set(SYSCALL_INDEX, syscall_handler);*/
	idt_set(0, (uint32_t)isr0);
    idt_set(1, (uint32_t)isr1);
    idt_set(2, (uint32_t)isr2);
    idt_set(3, (uint32_t)isr3);
    idt_set(4, (uint32_t)isr4);
    idt_set(5, (uint32_t)isr5);
    idt_set(6, (uint32_t)isr6);
    idt_set(7, (uint32_t)isr7);
    idt_set(8, (uint32_t)isr8);
    idt_set(9, (uint32_t)isr9);
    idt_set(10, (uint32_t)isr10);
    idt_set(11, (uint32_t)isr11);
    idt_set(12, (uint32_t)isr12);
    idt_set(13, (uint32_t)isr13);
    idt_set(14, (uint32_t)isr14);
    idt_set(15, (uint32_t)isr15);
    idt_set(16, (uint32_t)isr16);
    idt_set(17, (uint32_t)isr17);
    idt_set(18, (uint32_t)isr18);
    idt_set(19, (uint32_t)isr19);
    idt_set(20, (uint32_t)isr20);
    idt_set(21, (uint32_t)isr21);
    idt_set(22, (uint32_t)isr22);
    idt_set(23, (uint32_t)isr23);
    idt_set(24, (uint32_t)isr24);
    idt_set(25, (uint32_t)isr25);
    idt_set(26, (uint32_t)isr26);
    idt_set(27, (uint32_t)isr27);
    idt_set(28, (uint32_t)isr28);
    idt_set(29, (uint32_t)isr29);
    idt_set(30, (uint32_t)isr30);
    idt_set(31, (uint32_t)isr31);

    idt_set(32, (uint32_t)irq0);
    idt_set(33, (uint32_t)irq1);
    idt_set(34, (uint32_t)irq2);
    idt_set(35, (uint32_t)irq3);
    idt_set(36, (uint32_t)irq4);
    idt_set(37, (uint32_t)irq5);
    idt_set(38, (uint32_t)irq6);
    idt_set(39, (uint32_t)irq7);
    idt_set(40, (uint32_t)irq8);
    idt_set(41, (uint32_t)irq9);
    idt_set(42, (uint32_t)irq10);
    idt_set(43, (uint32_t)irq11);
    idt_set(44, (uint32_t)irq12);
    idt_set(45, (uint32_t)irq13);
    idt_set(46, (uint32_t)irq14);
    idt_set(47, (uint32_t)irq15);

	// idt_set(1, idt_48);/

		
	load_idt((uint32_t)&idtr_descriptor);
	// load_idt((uint32_t)&idtr_descriptor);
	// enable_interrupts();

	// load_idt(&idtr_descriptor);

}