/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.16
        Device            :  PIC16F18855
        Version           :  1.01
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


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set PLAYER1 aliases
#define PLAYER1_TRIS               TRISA0
#define PLAYER1_LAT                LATA0
#define PLAYER1_PORT               RA0
#define PLAYER1_WPU                WPUA0
#define PLAYER1_ANS                ANSA0
#define PLAYER1_SetHigh()    do { LATA0 = 1; } while(0)
#define PLAYER1_SetLow()   do { LATA0 = 0; } while(0)
#define PLAYER1_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define PLAYER1_GetValue()         PORTAbits.RA0
#define PLAYER1_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define PLAYER1_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define PLAYER1_SetPullup()    do { WPUA0 = 1; } while(0)
#define PLAYER1_ResetPullup()   do { WPUA0 = 0; } while(0)
#define PLAYER1_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define PLAYER1_SetDigitalMode()   do { ANSA0 = 0; } while(0)


// get/set PLAYER2 aliases
#define PLAYER2_TRIS               TRISA1
#define PLAYER2_LAT                LATA1
#define PLAYER2_PORT               RA1
#define PLAYER2_WPU                WPUA1
#define PLAYER2_ANS                ANSA1
#define PLAYER2_SetHigh()    do { LATA1 = 1; } while(0)
#define PLAYER2_SetLow()   do { LATA1 = 0; } while(0)
#define PLAYER2_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define PLAYER2_GetValue()         PORTAbits.RA1
#define PLAYER2_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define PLAYER2_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define PLAYER2_SetPullup()    do { WPUA1 = 1; } while(0)
#define PLAYER2_ResetPullup()   do { WPUA1 = 0; } while(0)
#define PLAYER2_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define PLAYER2_SetDigitalMode()   do { ANSA1 = 0; } while(0)


// get/set SWITCH aliases
#define SWITCH_TRIS               TRISA2
#define SWITCH_LAT                LATA2
#define SWITCH_PORT               RA2
#define SWITCH_WPU                WPUA2
#define SWITCH_ANS                ANSA2
#define SWITCH_SetHigh()    do { LATA2 = 1; } while(0)
#define SWITCH_SetLow()   do { LATA2 = 0; } while(0)
#define SWITCH_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define SWITCH_GetValue()         PORTAbits.RA2
#define SWITCH_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define SWITCH_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define SWITCH_SetPullup()    do { WPUA2 = 1; } while(0)
#define SWITCH_ResetPullup()   do { WPUA2 = 0; } while(0)
#define SWITCH_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define SWITCH_SetDigitalMode()   do { ANSA2 = 0; } while(0)


// get/set SWITCH aliases
#define SWITCH_TRIS               TRISA2
#define SWITCH_LAT                LATA2
#define SWITCH_PORT               RA2
#define SWITCH_WPU                WPUA2
#define SWITCH_ANS                ANSA2
#define SWITCH_SetHigh()    do { LATA2 = 1; } while(0)
#define SWITCH_SetLow()   do { LATA2 = 0; } while(0)
#define SWITCH_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define SWITCH_GetValue()         PORTAbits.RA2
#define SWITCH_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define SWITCH_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define SWITCH_SetPullup()    do { WPUA2 = 1; } while(0)
#define SWITCH_ResetPullup()   do { WPUA2 = 0; } while(0)
#define SWITCH_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define SWITCH_SetDigitalMode()   do { ANSA2 = 0; } while(0)


// get/set BUTTON1LED aliases
#define BUTTON1LED_TRIS               TRISB0
#define BUTTON1LED_LAT                LATB0
#define BUTTON1LED_PORT               RB0
#define BUTTON1LED_WPU                WPUB0
#define BUTTON1LED_ANS                ANSB0
#define BUTTON1LED_SetHigh()    do { LATB0 = 1; } while(0)
#define BUTTON1LED_SetLow()   do { LATB0 = 0; } while(0)
#define BUTTON1LED_Toggle()   do { LATB0 = ~LATB0; } while(0)
#define BUTTON1LED_GetValue()         PORTBbits.RB0
#define BUTTON1LED_SetDigitalInput()    do { TRISB0 = 1; } while(0)
#define BUTTON1LED_SetDigitalOutput()   do { TRISB0 = 0; } while(0)

#define BUTTON1LED_SetPullup()    do { WPUB0 = 1; } while(0)
#define BUTTON1LED_ResetPullup()   do { WPUB0 = 0; } while(0)
#define BUTTON1LED_SetAnalogMode()   do { ANSB0 = 1; } while(0)
#define BUTTON1LED_SetDigitalMode()   do { ANSB0 = 0; } while(0)


// get/set BUTTON2LED aliases
#define BUTTON2LED_TRIS               TRISB1
#define BUTTON2LED_LAT                LATB1
#define BUTTON2LED_PORT               RB1
#define BUTTON2LED_WPU                WPUB1
#define BUTTON2LED_ANS                ANSB1
#define BUTTON2LED_SetHigh()    do { LATB1 = 1; } while(0)
#define BUTTON2LED_SetLow()   do { LATB1 = 0; } while(0)
#define BUTTON2LED_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define BUTTON2LED_GetValue()         PORTBbits.RB1
#define BUTTON2LED_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define BUTTON2LED_SetPullup()    do { WPUB1 = 1; } while(0)
#define BUTTON2LED_ResetPullup()   do { WPUB1 = 0; } while(0)
#define BUTTON2LED_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalMode()   do { ANSB1 = 0; } while(0)


// get/set BUTTON2LED aliases
#define BUTTON2LED_TRIS               TRISB1
#define BUTTON2LED_LAT                LATB1
#define BUTTON2LED_PORT               RB1
#define BUTTON2LED_WPU                WPUB1
#define BUTTON2LED_ANS                ANSB1
#define BUTTON2LED_SetHigh()    do { LATB1 = 1; } while(0)
#define BUTTON2LED_SetLow()   do { LATB1 = 0; } while(0)
#define BUTTON2LED_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define BUTTON2LED_GetValue()         PORTBbits.RB1
#define BUTTON2LED_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define BUTTON2LED_SetPullup()    do { WPUB1 = 1; } while(0)
#define BUTTON2LED_ResetPullup()   do { WPUB1 = 0; } while(0)
#define BUTTON2LED_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalMode()   do { ANSB1 = 0; } while(0)


// get/set BUTTON2LED aliases
#define BUTTON2LED_TRIS               TRISB1
#define BUTTON2LED_LAT                LATB1
#define BUTTON2LED_PORT               RB1
#define BUTTON2LED_WPU                WPUB1
#define BUTTON2LED_ANS                ANSB1
#define BUTTON2LED_SetHigh()    do { LATB1 = 1; } while(0)
#define BUTTON2LED_SetLow()   do { LATB1 = 0; } while(0)
#define BUTTON2LED_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define BUTTON2LED_GetValue()         PORTBbits.RB1
#define BUTTON2LED_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define BUTTON2LED_SetPullup()    do { WPUB1 = 1; } while(0)
#define BUTTON2LED_ResetPullup()   do { WPUB1 = 0; } while(0)
#define BUTTON2LED_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalMode()   do { ANSB1 = 0; } while(0)


// get/set BUTTON2LED aliases
#define BUTTON2LED_TRIS               TRISB1
#define BUTTON2LED_LAT                LATB1
#define BUTTON2LED_PORT               RB1
#define BUTTON2LED_WPU                WPUB1
#define BUTTON2LED_ANS                ANSB1
#define BUTTON2LED_SetHigh()    do { LATB1 = 1; } while(0)
#define BUTTON2LED_SetLow()   do { LATB1 = 0; } while(0)
#define BUTTON2LED_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define BUTTON2LED_GetValue()         PORTBbits.RB1
#define BUTTON2LED_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define BUTTON2LED_SetPullup()    do { WPUB1 = 1; } while(0)
#define BUTTON2LED_ResetPullup()   do { WPUB1 = 0; } while(0)
#define BUTTON2LED_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalMode()   do { ANSB1 = 0; } while(0)


// get/set BUTTON2LED aliases
#define BUTTON2LED_TRIS               TRISB1
#define BUTTON2LED_LAT                LATB1
#define BUTTON2LED_PORT               RB1
#define BUTTON2LED_WPU                WPUB1
#define BUTTON2LED_ANS                ANSB1
#define BUTTON2LED_SetHigh()    do { LATB1 = 1; } while(0)
#define BUTTON2LED_SetLow()   do { LATB1 = 0; } while(0)
#define BUTTON2LED_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define BUTTON2LED_GetValue()         PORTBbits.RB1
#define BUTTON2LED_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define BUTTON2LED_SetPullup()    do { WPUB1 = 1; } while(0)
#define BUTTON2LED_ResetPullup()   do { WPUB1 = 0; } while(0)
#define BUTTON2LED_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalMode()   do { ANSB1 = 0; } while(0)


// get/set BUTTON2LED aliases
#define BUTTON2LED_TRIS               TRISB1
#define BUTTON2LED_LAT                LATB1
#define BUTTON2LED_PORT               RB1
#define BUTTON2LED_WPU                WPUB1
#define BUTTON2LED_ANS                ANSB1
#define BUTTON2LED_SetHigh()    do { LATB1 = 1; } while(0)
#define BUTTON2LED_SetLow()   do { LATB1 = 0; } while(0)
#define BUTTON2LED_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define BUTTON2LED_GetValue()         PORTBbits.RB1
#define BUTTON2LED_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define BUTTON2LED_SetPullup()    do { WPUB1 = 1; } while(0)
#define BUTTON2LED_ResetPullup()   do { WPUB1 = 0; } while(0)
#define BUTTON2LED_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalMode()   do { ANSB1 = 0; } while(0)


// get/set BUTTON2LED aliases
#define BUTTON2LED_TRIS               TRISB1
#define BUTTON2LED_LAT                LATB1
#define BUTTON2LED_PORT               RB1
#define BUTTON2LED_WPU                WPUB1
#define BUTTON2LED_ANS                ANSB1
#define BUTTON2LED_SetHigh()    do { LATB1 = 1; } while(0)
#define BUTTON2LED_SetLow()   do { LATB1 = 0; } while(0)
#define BUTTON2LED_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define BUTTON2LED_GetValue()         PORTBbits.RB1
#define BUTTON2LED_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define BUTTON2LED_SetPullup()    do { WPUB1 = 1; } while(0)
#define BUTTON2LED_ResetPullup()   do { WPUB1 = 0; } while(0)
#define BUTTON2LED_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalMode()   do { ANSB1 = 0; } while(0)


// get/set BUTTON2LED aliases
#define BUTTON2LED_TRIS               TRISB1
#define BUTTON2LED_LAT                LATB1
#define BUTTON2LED_PORT               RB1
#define BUTTON2LED_WPU                WPUB1
#define BUTTON2LED_ANS                ANSB1
#define BUTTON2LED_SetHigh()    do { LATB1 = 1; } while(0)
#define BUTTON2LED_SetLow()   do { LATB1 = 0; } while(0)
#define BUTTON2LED_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define BUTTON2LED_GetValue()         PORTBbits.RB1
#define BUTTON2LED_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define BUTTON2LED_SetPullup()    do { WPUB1 = 1; } while(0)
#define BUTTON2LED_ResetPullup()   do { WPUB1 = 0; } while(0)
#define BUTTON2LED_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define BUTTON2LED_SetDigitalMode()   do { ANSB1 = 0; } while(0)



/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF0 pin functionality
 * @Example
    IOCAF0_ISR();
 */
void IOCAF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF0_SetInterruptHandler(void* InterruptHandler);

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF0_SetInterruptHandler() method.
    This handler is called every time the IOCAF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(IOCAF0_InterruptHandler);

*/
void (*IOCAF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF0_SetInterruptHandler() method.
    This handler is called every time the IOCAF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(IOCAF0_DefaultInterruptHandler);

*/
void IOCAF0_DefaultInterruptHandler(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF1 pin functionality
 * @Example
    IOCAF1_ISR();
 */
void IOCAF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF1_SetInterruptHandler(void* InterruptHandler);

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF1_SetInterruptHandler() method.
    This handler is called every time the IOCAF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(IOCAF1_InterruptHandler);

*/
void (*IOCAF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF1_SetInterruptHandler() method.
    This handler is called every time the IOCAF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(IOCAF1_DefaultInterruptHandler);

*/
void IOCAF1_DefaultInterruptHandler(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAN0 pin functionality
 * @Example
    IOCAN0_ISR();
 */
void IOCAN0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAN0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAN0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAN0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAN0_SetInterruptHandler(void* InterruptHandler);

/**
  @Summary
    Dynamic Interrupt Handler for IOCAN0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAN0_SetInterruptHandler() method.
    This handler is called every time the IOCAN0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAN0_SetInterruptHandler(IOCAN0_InterruptHandler);

*/
void (*IOCAN0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAN0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAN0_SetInterruptHandler() method.
    This handler is called every time the IOCAN0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAN0_SetInterruptHandler(IOCAN0_DefaultInterruptHandler);

*/
void IOCAN0_DefaultInterruptHandler(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAN1 pin functionality
 * @Example
    IOCAN1_ISR();
 */
void IOCAN1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAN1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAN1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAN1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAN1_SetInterruptHandler(void* InterruptHandler);

/**
  @Summary
    Dynamic Interrupt Handler for IOCAN1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAN1_SetInterruptHandler() method.
    This handler is called every time the IOCAN1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAN1_SetInterruptHandler(IOCAN1_InterruptHandler);

*/
void (*IOCAN1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAN1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAN1_SetInterruptHandler() method.
    This handler is called every time the IOCAN1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAN1_SetInterruptHandler(IOCAN1_DefaultInterruptHandler);

*/
void IOCAN1_DefaultInterruptHandler(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAP0 pin functionality
 * @Example
    IOCAP0_ISR();
 */
void IOCAP0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAP0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAP0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAP0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAP0_SetInterruptHandler(void* InterruptHandler);

/**
  @Summary
    Dynamic Interrupt Handler for IOCAP0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAP0_SetInterruptHandler() method.
    This handler is called every time the IOCAP0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAP0_SetInterruptHandler(IOCAP0_InterruptHandler);

*/
void (*IOCAP0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAP0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAP0_SetInterruptHandler() method.
    This handler is called every time the IOCAP0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAP0_SetInterruptHandler(IOCAP0_DefaultInterruptHandler);

*/
void IOCAP0_DefaultInterruptHandler(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAP1 pin functionality
 * @Example
    IOCAP1_ISR();
 */
void IOCAP1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAP1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAP1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAP1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAP1_SetInterruptHandler(void* InterruptHandler);

/**
  @Summary
    Dynamic Interrupt Handler for IOCAP1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAP1_SetInterruptHandler() method.
    This handler is called every time the IOCAP1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAP1_SetInterruptHandler(IOCAP1_InterruptHandler);

*/
void (*IOCAP1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAP1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAP1_SetInterruptHandler() method.
    This handler is called every time the IOCAP1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAP1_SetInterruptHandler(IOCAP1_DefaultInterruptHandler);

*/
void IOCAP1_DefaultInterruptHandler(void);





#endif // PIN_MANAGER_H
/**
 End of File
*/