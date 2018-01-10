
#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"



void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */   
    LATA = 0x00;    
    LATB = 0x00;    
    LATC = 0x00;    

    /**
    TRISx registers
    */    
    TRISA = 0x30;
    TRISB = 0x70;
    TRISC = 0xFF;

    /**
    ANSELx registers
    */   
    ANSEL=0X10;
    ANSELH=0X00;

    /**
    WPUx registers
    */ 
    WPUB = 0x70;
    WPUA = 0x37;

}       

void PIN_MANAGER_IOC(void)
{   

}

/**
 End of File
*/