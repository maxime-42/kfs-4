// #include "libk.h"

// void printk(char *str, ...)
// {
//     int     *args;
//     char    *format;
//     int     i;
//     char    tmp_addr[9];
//     uint8_t   zero_padding;

//     args = (int *)(&str);
//     format = (char *)(*args++);
//     i = 0;
//     while (format[i]) {
//         zero_padding = 0;
//         if (format[i] == '%') {
//             i++;
//             /* padding with zeros - max 9 */
//             if (format[i] == '0') {
//                 i++;
//                 zero_padding = format[i] - '0';
//                 i++;
//             }
//             if (format[i] == 'c') {
//                 ft_putchar(*args++);
//             }
//             else if (format[i] == 's') {
//                 ft_putstr(*((char **)args++));
//             }
//             else if (format[i] == 'x') {
//                 kmemset(tmp_addr, 0, sizeof(tmp_addr));
//                 hex_to_str(*args++, tmp_addr);
//                 ft_putstr(tmp_addr);
//             }
//             else if (format[i] == 'p') {
//                 memset(tmp_addr, 0, sizeof(tmp_addr));
//                 hex_to_str(*args++, tmp_addr);
//                 ft_putstr("0x");
//                 ft_putstr(tmp_addr);
//             }
//             else if (format[i] == 'd') {
//                 if (zero_padding > 0) {
//                     while (zero_padding - intlen(*args)) {
//                         ft_putchar('0');
//                         zero_padding--;
//                     }
//                 }
//                 kputnbr(*args++);
//             }
//             else {
//                 ft_putchar('%');
//                 ft_putchar(format[i]);
//             }
//         }
//         else {
//             ft_putchar(format[i]);
//         }
//         i++;
//     }
// }
