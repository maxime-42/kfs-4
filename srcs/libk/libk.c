#include "kernel.h"
#include "libk.h"

// #define VGA_WIDTH 80
// #define VGA_HEIGHT 80 
// uint16_t* video_mem = 0;
// uint16_t terminal_row = 0;
// uint16_t terminal_col = 0;
static uint32_t color = VGA_COLOR_WHITE;

void copyFunction(void *srcFunction, void *destFunction, size_t size) {
    // Assuming destFunction is the address where you want to copy the source function
    // This is a simplified example, and it might not work on all platforms

    // Copy the bytes of the function from source to destination
    uint8_t* src = (uint8_t*)srcFunction;
    uint8_t* dest = (uint8_t*)destFunction;

    // Assuming the function size is fixed, adjust this accordingly

    for (size_t i = 0; i < size ; ++i) {
        dest[i] = src[i];
    }
}


 void	ft_print_hex(char c, int i)
 {
	const char base[16] = "0123456789abcdef";
 
	 if (i < 16)
	 {
		ft_putchar(*(base + c / 16));
		ft_putchar(*(base + c % 16));
		ft_putchar(' ');
	 }
	//else 
		//ft_putchar('0');
		//ft_putstr("00 ");
	 if ((i + 1) % 8 == 0)
		ft_putchar(' ');
 }


void				print_name(uint32_t addr)
{

	if (addr == STRING_ADDRESS)
	{	
		ft_putstr("string   ");
	}
	else if (addr == MULTI_ADDRESS)
	{
		ft_putstr("multi    ");
	}
	else if (addr == GDT_ADDRESS)
	{
		ft_putstr("GDT      ");
	}
	else
	{
		ft_putstr(".......  ");
	}
}

void				set_color(uint32_t addr)
{

	if (addr == MULTI_ADDRESS ||  addr == STRING_ADDRESS || addr == GDT_ADDRESS)
	{	
		color = VGA_COLOR_GREEN;
	}
	else
	{
		color = VGA_COLOR_WHITE;
	}
}

void			read_to_stack(void *mem_addr, uint32_t size)
{
	uint32_t		j = 0;
	uint32_t		*ptrAddr = (uint32_t *)mem_addr;	
	uint32_t 		addr = *ptrAddr;
	char			*str = (char *)addr;
	char 			addr_str[9];

	while (j < size)
	{
		set_color(addr);
		hex_to_str(addr, addr_str);
		//ptr = itoa_base(addr, 16);
		ft_putstr(addr_str);
		//ft_putchar(' ');
		ft_putstr("   ");

	    //print_name(addr);
		for (uint32_t i = 0 ; i < 32; i++)
			ft_print_hex(str[i], i);
		// return; 
		//ft_putchar('|');
	       	for (uint32_t i = 0 ; i < 16; i++)
				print_ascii(str[i]);
		//ft_putchar('|');
		ft_putchar('\n');
		j++;
		addr += 16;
		str = (char *)addr;
	}
}

