#ifndef IO_H
#define IO_H
#include <stdint.h>


// unsigned char insb(unsigned short port);
// unsigned short insw(unsigned short port);

// void outb(unsigned short port, unsigned char val);
// void outw(unsigned short port, unsigned short val);



uint8_t inb(uint16_t port);




void outb(uint16_t port, uint8_t value);

void outw(uint16_t port, uint16_t value);

#endif