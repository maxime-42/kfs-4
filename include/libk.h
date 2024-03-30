#ifndef _LIBK_H
#define _LIBK_H

#include <stdint.h>
#include <stddef.h>

void	*kmemset(void *b, int c, size_t len);
void	ft_putstr(const char* str);
void	ft_putchar(char c );
char	*itoa_base(int num, int base);

void	*kmemcpy(void *dest, const void *src, size_t n);

size_t	strlen(const char* str);

void	ft_putchar(char c );

void	print_register();

void	print_ascii(char c);

void hex_to_str(uint32_t addr, char *result);

#endif // !_LIBK_H
