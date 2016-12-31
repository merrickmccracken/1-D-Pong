/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.16
        Device            :  PIC16F18855
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/

#include <xc.h>
#include "pin_manager.h"
#include <stdbool.h>
#include "tmr4.h"
#include "eusart.h"
extern volatile uint8_t buttonPushed;

void PIN_MANAGER_Initialize(void)
{
    LATB = 0x0;
    WPUE = 0x0;
    LATA = 0x0;
    LATC = 0x0;
    WPUA = 0x0;
    WPUB = 0x0;
    WPUC = 0x0;
    ANSELA = 0xD8;
    ANSELB = 0x9C;
    ANSELC = 0x8F;
    TRISB = 0xDC;
    TRISC = 0x9F;
    TRISA = 0xDF;

    

    // interrupt on change for group IOCAF - flag
    IOCAFbits.IOCAF0 = 0; // Pin : RA0
    IOCAFbits.IOCAF1 = 0; // Pin : RA1

    // interrupt on change for group IOCAN - negative
    IOCANbits.IOCAN0 = 0; // Pin : RA0
    IOCANbits.IOCAN1 = 0; // Pin : RA1

    // interrupt on change for group IOCAP - positive
    IOCAPbits.IOCAP0 = 1; // Pin : RA0
    IOCAPbits.IOCAP1 = 1; // Pin : RA1

    PIE0bits.IOCIE = 1; // Enable IOCI interrupt 

    bool state = GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    T4AINPPSbits.T4AINPPS = 0x0E;   //RB6->TMR4:T4IN;
    CLCIN1PPSbits.CLCIN1PPS = 0x14;   //RC4->CLC1:CLCIN1;
    SSP1DATPPSbits.SSP1DATPPS = 0x14;   //RC4->MSSP1:SDI1;
    CLCIN0PPSbits.CLCIN0PPS = 0x14;   //RC4->CLC1:CLCIN0;
    CLCIN2PPSbits.CLCIN2PPS = 0x14;   //RC4->CLC1:CLCIN2;
    CLCIN3PPSbits.CLCIN3PPS = 0x14;   //RC4->CLC1:CLCIN3;
    RB5PPS = 0x14;   //RB5->MSSP1:SCK1;
    RA5PPS = 0x01;   //RA5->CLC1:CLC1OUT;
    RC5PPS = 0x15;   //RC5->MSSP1:SDO1;
    RC6PPS = 0x10;   //RC6->EUSART:TX;

    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS

    IOCAP0_SetInterruptHandler(IOCAP0_DefaultInterruptHandler);
    IOCAP1_SetInterruptHandler(IOCAP1_DefaultInterruptHandler);
    
    GIE = state;

}

void PIN_MANAGER_IOC(void)
{    
   //printf("PIN_MANAGER_IOC Start ");
    // interrupt on change for group IOCAP
    if(IOCAFbits.IOCAF0 == 1)
    {
        IOCAP0_ISR();            
    }
    if(IOCAFbits.IOCAF1 == 1)
    {
        IOCAP1_ISR();            
    }
   //printf("PIN_MANAGER_IOC End ");
}

/**
   IOCAP0 Interrupt Service Routine
*/
void IOCAP0_ISR(void) {
   //printf("IOCAP0_ISR Start ");
    // Add custom IOCAP0 code
    if(IOCAP0_InterruptHandler)
    {
        IOCAP0_InterruptHandler();
    }
    IOCAFbits.IOCAF0 = 0;
    buttonPushed |= 0x01 << 2;
    //printf("\n%d %X\n",__LINE__,buttonPushed);
    //printf("IOCAP0_ISR End ");
}

/**
  Allows selecting an interrupt handler for IOCAP0 at application runtime
*/
void IOCAP0_SetInterruptHandler(void* InterruptHandler){
    IOCAP0_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAP0
*/
void IOCAP0_DefaultInterruptHandler(void){
    // add your IOCAP0 interrupt custom code
    // or set custom function using IOCAP0_SetInterruptHandler()
   //printf("IOCAP0_DIH Start ");
   TMR4_Start();
   //printf("IOCAP0_DIH End ");
}
/**
   IOCAP1 Interrupt Service Routine
*/
void IOCAP1_ISR(void) {
   //printf("IOCAP1_ISR Start ");
    // Add custom IOCAP1 code
    if(IOCAP1_InterruptHandler)
    {
        IOCAP1_InterruptHandler();
    }
    IOCAFbits.IOCAF1 = 0;
    buttonPushed |= 0x01 << 3;
    //printf("\n%d %X\n",__LINE__,buttonPushed);
    //printf("IOCAP1_ISR End ");
}

/**
  Allows selecting an interrupt handler for IOCAP1 at application runtime
*/
void IOCAP1_SetInterruptHandler(void* InterruptHandler){
    IOCAP1_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAP1
*/
void IOCAP1_DefaultInterruptHandler(void){
    // add your IOCAP1 interrupt custom code
    // or set custom function using IOCAP1_SetInterruptHandler()
   //printf("IOCAP1_DIH Start ");
   TMR4_Start();
   //printf("IOCAP1_DIH End ");
}

/**
 End of File
*/
