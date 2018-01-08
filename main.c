#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/eusart.h"
void main(void){
    SYSTEM_Initialize();        // initialize the device
    INTERRUPT_GlobalInterruptEnable();      // Enable the Global Interrupts
    INTERRUPT_PeripheralInterruptEnable();      // Enable the Peripheral Interrupts
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    while (1){
        // Add your application code
        putch("T");
        EUSART_Transmit_ISR();
        __delay_ms(500);
        putch("AMO");
        EUSART_Transmit_ISR();
        
    }
}
