section .multiboot
	dd 0x1BADB002	; Magic number
	dd 0x0			; Flags
	dd - (0x1BADB002 + 0x0)	; Checksum

extern kmain

global load_gdt
global load_idt
global _start
global test_div
; global idt_f

global enable_interrupts

global getkey



load_gdt:

	mov eax, [esp + 4]
	lgdt [eax]

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov ss, ax

	mov ax, 0x18
	mov gs, ax

	ret



enable_interrupts:
	cli
	sti
	ret


	
load_idt:
	mov edx, [esp + 4]
	lidt [edx]
	ret



_start:
	call kmain
	hlt

global test_


getkey:
    push ebp
    mov ebp, esp
    mov eax, 2 ; Command getkey
    int 33
    pop ebp
    ret

test_:
	int 1
global panic
panic :
	cli
	hlt

section .bss
resb 8192			; 8KB for stack
stack_space:

