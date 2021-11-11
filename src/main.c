/*******************************************************************************
 * Ben Baker 2020
 *
 * A sound effects demo for Sinclair ZX Spectrum Next.
 ******************************************************************************/

#include <input.h>
#include <z80.h>
#include <intrinsic.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "ayfx.h"

#pragma output CRT_ORG_CODE = 0x8184
#pragma output CLIB_MALLOC_HEAP_SIZE = 0
#pragma printf = "%c %s"

#define printCls() printf("%c", 12)
#define printAt(col, row, str) printf("\x16%c%c%s", (col), (row), (str))

extern uint8_t sfx[];

static void isr_init(void)
{
    // Set up IM2 interrupt service routine:
    // Put Z80 in IM2 mode with a 257-byte interrupt vector table located
    // at 0x8000 (before CRT_ORG_CODE) filled with 0x81 bytes. Install the
    // vt_play_isr() interrupt service routine at the interrupt service routine
    // entry at address 0x8181.

    intrinsic_di();
    im2_init((void *) 0x8000);
    memset((void *) 0x8000, 0x81, 257);
    z80_bpoke(0x8181, 0xC3);
    z80_wpoke(0x8182, (uint16_t) afx_play_isr);
    intrinsic_ei();
}

int main(void)
{
    int effect_index = 0;
	
    afx_init(sfx);
    isr_init();

    printCls();
    printAt(8, 10, "Enjoy the sound!\n");
    printAt(3, 12, "Press any key to cycle sfx\n");

    while (true)
    {
        if (in_inkey() != 0)
        {
            in_wait_nokey();

            afx_play(effect_index);

            if (++effect_index == 6)
                effect_index = 0;
        }
    }
}
