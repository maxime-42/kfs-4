#ifndef _IDT_H
#define _IDT_H

#include <stdint.h>
#include <stddef.h>

/* ************************************************************************** */
/* 			Structs                                               */
/* ************************************************************************** */

struct idt_entry
{
	uint16_t offset_1; // Offset bits 0 - 15
	uint16_t selector; // Selector thats in our GDT
	uint8_t zero; // Does nothing, unused set to zero
	uint8_t flags; // Descriptor type and attributes
	uint16_t offset_2; // Offset bits 16-31
} __attribute__((packed));


struct idtr_desc
{
	uint16_t limit; // Size of descriptor table -1
	uint32_t base; // Base address of the start of the interrupt descriptor table
} __attribute__((packed));







/* ************************************************************************** */
/*				Prototype                                     */
/* ************************************************************************** */


void		init_idt();
extern void	load_idt(uint32_t ptr);
// extern void load_idt(uint32_t idt_ptr);
#endif // !
