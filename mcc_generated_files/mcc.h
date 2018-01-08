#ifndef MCC_H
#define	MCC_H
#include <xc.h>
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include "interrupt_manager.h"
#include "adc.h"
#include "eusart.h"
#define _XTAL_FREQ  32000000

void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);

#endif