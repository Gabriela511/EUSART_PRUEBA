/** ADC Generated Driver File
**/

#include <xc.h>
#include "adc.h"
#include "mcc.h"

#define ACQ_US_DELAY 5

void ADC_Initialize(void){
    // set the ADC to the options selected in the User Interface
    // GO_nDONE stop; ADON enabled; CHS AN0; 
    ADCON0 = 0x01;      //chanel selection
    // ADFM right; ADPREF VDD; ADCS Frc; 
    ADCON1 = 0x00;          //adc voltage reference
    // TRIGSEL no_auto_trigger; 
    ADCON2 = 0x87;
    // ADRESL 0; 
    ADRESL = 0x00;   //A/D RESULT REGISTER LOW BYTE
    // ADRESH 0;     //A/D RESULT REGISTER HIGH BYTE
    ADRESH = 0x00;
    // Enabling ADC interrupt.
    PIE1bits.ADIE = 1;
}

void ADC_SelectChannel(adc_channel_t channel){
    // select the A/D channel
    ADCON0bits.CHS = channel;    
    // Turn on the ADC module
    ADCON0bits.ADON = 1;  
}

void ADC_StartConversion() {
    // Start the conversion
    ADCON0bits.GO_nDONE = 1;
}


bool ADC_IsConversionDone()
{
    // Start the conversion
    return ((bool)(!ADCON0bits.GO_nDONE));
}

adc_result_t ADC_GetConversionResult(void)
{
    // Conversion finished, return the result
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}

adc_result_t ADC_GetConversion(adc_channel_t channel)
{
    // select the A/D channel
    ADCON0bits.CHS = channel;    

    // Turn on the ADC module
    ADCON0bits.ADON = 1;
    // Acquisition time delay
    __delay_us(ACQ_US_DELAY);

    // Start the conversion
    ADCON0bits.GO_nDONE = 1;

    // Wait for the conversion to finish
    while (ADCON0bits.GO_nDONE)
    {
    }

    // Conversion finished, return the result
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}


void ADC_ISR(void)
{
    // Clear the ADC interrupt flag
    PIR1bits.ADIF = 0;
}
/**
 End of File
*/