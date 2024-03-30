#include "libk.h"

void hex_to_str(uint32_t addr, char *result) {
    // Define the hexadecimal characters
    const char hex_chars[] = "0123456789ABCDEF";

    // Iterate through each nibble (4 bits) of the address
    for (int i = 7; i >= 0; --i) {
        // Extract the current nibble
        uint8_t nibble = (addr >> (i * 4)) & 0xF;

        // Convert the nibble to its corresponding hexadecimal character
        result[7 - i] = hex_chars[nibble];
    }

    // Null-terminate the string
    result[8] = '\0';
}
