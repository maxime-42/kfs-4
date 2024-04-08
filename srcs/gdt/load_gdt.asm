
global gdt_flush

gdt_flush:

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

; DATA_SEGMENT_OFFSET equ 0x10
; CODE_SEGMENT_OFFSET equ 0x08
; KERNEL_STACK_OFFSET equ 0x18

; section .text
; global gdt_flush							; Allows the C code to link to this
; gdt_flush:
; 	mov eax, [esp + 4]						; Load the gdt parameter
; 	lgdt [eax]         			    		; Load the GDT with our 'gp' which is a special pointer | LGDT -> Load GDT
	
; 	mov ax, DATA_SEGMENT_OFFSET     		; 0x10 is the offset in the GDT to our data segment
; 	mov ds, ax             		   			; Data segment
; 	mov es, ax             		   			; Extra segment
; 	mov fs, ax             		   			; Pointer to more extra data
; 	mov gs, ax             		   			; Pointer to still more extra data
; 	mov ss, ax             		   			; Stack Segment

; 	; Protected mode
; 	cli
; 	mov eax, cr0
; 	or eax, 0x1
; 	mov cr0, eax

; 	jmp CODE_SEGMENT_OFFSET:.code_selector 	; 0x08 is the offset to our code segment: Far jump!
; .code_selector:
; 	ret  