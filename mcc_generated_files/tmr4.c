/**
  TMR4 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr4.c

  @Summary
    This is the generated driver implementation file for the TMR4 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for TMR4.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.16
        Device            :  PIC16F18855
        Driver Version    :  1.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

/**
  Section: Included Files
 */

#include <xc.h>
#include "tmr4.h"
#include "pin_manager.h"
#include "eusart.h"
extern volatile uint8_t buttonPushed;
/**
  Section: TMR4 APIs
 */

void TMR4_Initialize(void)
{
   // Set TMR4 to the options selected in the User Interface

    // T4CKPS 1:2; T4OUTPS 1:1; TMR4ON off; 
    T4CON = 0x10;

    // T4CS MFINTOSC 31.25khz; 
    T4CLKCON = 0x05;

   // T4PSYNC Not Synchronized; T4MODE Software control One shot; T4CKPOL Rising Edge; T4CKSYNC Not Synchronized; 
   T4HLT = 0x08;

   // T4RSEL T4CKIPPS pin; 
   T4RST = 0x00;

    // PR4 155; 
    T4PR = 0x9B;

   // TMR4 0; 
   T4TMR = 0x00;

   // Clearing IF flag before enabling the interrupt.
   PIR4bits.TMR4IF = 0;

   // Enabling TMR4 interrupt.
   PIE4bits.TMR4IE = 1;

   // Set Default Interrupt Handler
   TMR4_SetInterruptHandler(TMR4_DefaultInterruptHandler);

   // Start TMR4
   //TMR4_Start();
}

void TMR4_ModeSet(TMR4_HLT_MODE mode)
{
   // Configure different types HLT mode
   T4HLTbits.MODE = mode;
}

void TMR4_ExtResetSourceSet(TMR4_HLT_EXT_RESET_SOURCE reset)
{
   //Configure different types of HLT external reset source
   T4RSTbits.RSEL = reset;
}

void TMR4_Start(void)
{
   // Start the Timer by writing to TMRxON bit
   T4CONbits.TMR4ON = 1;
}

void TMR4_StartTimer(void)
{
   TMR4_Start();
}

void TMR4_Stop(void)
{
   // Stop the Timer by writing to TMRxON bit
   T4CONbits.TMR4ON = 0;
}

void TMR4_StopTimer(void)
{
   TMR4_Stop();
}

uint8_t TMR4_Counter8BitGet(void)
{
   uint8_t readVal;

   readVal = TMR4;

   return readVal;
}

uint8_t TMR4_ReadTimer(void)
{
   return TMR4_Counter8BitGet();
}

void TMR4_Counter8BitSet(uint8_t timerVal)
{
   // Write to the Timer4 register
   TMR4 = timerVal;
}

void TMR4_WriteTimer(uint8_t timerVal)
{
   TMR4_Counter8BitSet(timerVal);
}

void TMR4_Period8BitSet(uint8_t periodVal)
{
   PR4 = periodVal;
}

void TMR4_LoadPeriodRegister(uint8_t periodVal)
{
   TMR4_Period8BitSet(periodVal);
}

void TMR4_ISR(void)
{
   //printf("TMR4_ISR Start ");
   // clear the TMR4 interrupt flag
   PIR4bits.TMR4IF = 0;

   if (TMR4_InterruptHandler) {
      TMR4_InterruptHandler();
   }
   //printf("TMR4_ISR End ");
}

void TMR4_SetInterruptHandler(void* InterruptHandler)
{
   TMR4_InterruptHandler = InterruptHandler;
}

void TMR4_DefaultInterruptHandler(void)
{
   //printf("TMR4_DIH Start ");
   // add your TMR4 interrupt custom code
   // or set custom function using TMR4_SetInterruptHandler()
   //printf("\n%d %X\n",__LINE__,buttonPushed);
   if (PLAYER2_GetValue() == 1 && (buttonPushed & 0x01 << 3)) {
      //BUTTON2LED_Toggle();
      buttonPushed |= 0x02;
      //printf("\n%d %X\n",__LINE__,buttonPushed);
   }
   //if (PLAYER1_GetValue() == 1 && IOCAFbits.IOCAF0 == 1) {
   //printf("\n%d %X\n",__LINE__,buttonPushed);
   if (PLAYER1_GetValue() == 1 && (buttonPushed & 0x01 << 2)) {
      //BUTTON1LED_Toggle();
      buttonPushed |= 0x01;
      //printf("\n%d %X\n",__LINE__,buttonPushed);
   }
   buttonPushed &= ~(0x0C); // clear edge flags
   //printf("\n%d %X\n",__LINE__,buttonPushed);
   //IOCAF = 0;
   // buttonPushed = 0; needs to be called elsewhere.
   // by doing this, buttonPushed lets me know if the button was pushed
   // since I last checked. Then I clear it when I'm done checking.
   //printf("TMR4_DIH End ");
}

/**
  End of File
 */