#ifndef _AYFX_H
#define _AYFX_H

#include <stdint.h>
#include <stdbool.h>

// Initialization
extern void afx_init(const void *bank_address) __z88dk_fastcall;

// Start the effect
extern void afx_play(uint8_t effect) __z88dk_fastcall;

// In the interrupt handler
extern void afx_frame(void);

extern void afx_play_isr(void);

#endif
