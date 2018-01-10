#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <string.h>
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/adc.h"
#include <xc.h>

void main(void){
    int adc;
    int temp;
    // initialize the device
	SYSTEM_Initialize();
	uint8_t data;
				
	// Enable the Global Interrupts
	INTERRUPT_GlobalInterruptEnable();
				
	//Enable the Peripheral Interrupts
	INTERRUPT_PeripheralInterruptEnable();
	while(1){
        ADC_StartConversion();
        adc=ADC_GetConversion(4);
        printf("El valor del adc es: %d\r",adc);
        temp=(int)adc*0.48828125;
        printf("El valor de temp es: %d\r",temp);
        __delay_ms(500);
    }				
	/*printf("\t\tTEST CODE\n\r");		//Enable redirect STDIO to USART before using printf statements
	printf("\t\t---- ----\n\r");
	printf("\t\tECHO TEST\n\r");
	printf("\t\t---- ----\n\n\r");
	printf("Enter any string: ");
                              
	do{
		data = EUSART_Read();		// Read data received
		EUSART_Write(data);			// Echo back the data received
	}while(!EUSART_DataReady);		//check if any data is received
    */
}
