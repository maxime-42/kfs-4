#include "config.h"
#include "io.h"

/***************************************************************/
/* This function close qemu window  and exit the program       */
/*                                                             */
/***************************************************************/

void qemu_shutdown(void)
{
    CLEAN_REGISTERS();
    outw(0x604, 0x2000);
}
