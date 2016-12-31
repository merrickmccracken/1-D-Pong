/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.16
        Device            :  PIC16F18855
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#define GREEN 0
#define RED 1
#define BLUE 2
#define NLEDS 60
#define MINBRIGHT 1

#define SLOWEST 35
#define SLOW 25
#define MEDIUM 17
#define FAST 12
#define FASTEST 8

#define TURNBLINKTIMES 6
#define TURNBLINKDELAYMS 500
#define SCOREBLINKTIMES 6
#define SCOREBLINKDELAYMS 500
#define RAINBOWDELAYMS 2 // Go through the rainbow in ~4 seconds. (2.6ms)
#define RAINBOW_INCREMENT 2

// Modify in "secret" mode?
// If so, store in EEPROM
// For now, const.
const uint8_t PLAYTO = 10;
const uint8_t WINBY = 2;
const uint8_t MAXSCORE = NLEDS >> 1;
// If I do include a secret mode, there should be a "factory reset".

volatile bool isPlayer1Turn = true;
volatile uint8_t buttonPushed = 0;
volatile uint8_t puckPosition = 0;
volatile uint8_t frameDelay = MEDIUM;
volatile uint8_t player1Score = 0;
volatile uint8_t player2Score = 0;

//const uint8_t gamma8[] = {
//   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
//   1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2,
//   2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5,
//   5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10,
//   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
//   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
//   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
//   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
//   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
//   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
//   90, 92, 93, 95, 96, 98, 99, 101, 102, 104, 105, 107, 109, 110, 112, 114,
//   115, 117, 119, 120, 122, 124, 126, 127, 129, 131, 133, 135, 137, 138, 140, 142,
//   144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 167, 169, 171, 173, 175,
//   177, 180, 182, 184, 186, 189, 191, 193, 196, 198, 200, 203, 205, 208, 210, 213,
//   215, 218, 220, 223, 225, 228, 231, 233, 236, 239, 241, 244, 247, 249, 252, 255
//};

uint8_t getADCClipped(void);
void writePlayerPuck(uint8_t puckPos, bool play1);
void restartPong(void);
void playPong(void);
void playTugOfWar(void);
void writeTugPuck(uint8_t puckPos, uint8_t line1, uint8_t line2);
void showScore(bool blinkOn, bool gameDone, bool isP1Turn, uint8_t line);
void writeRainbow(void);
void getNextRainbowColor(uint8_t* red, uint8_t* green, uint8_t* blue);
void delay_ms(uint16_t ms);
void delay_us(uint16_t us);
void scoreBlinks(bool isP1Turn);

/*
                         Main application
 */
void main(void)
{
   // initialize the device
   SYSTEM_Initialize();
   ADCC_StartConversion(POT1); // Stop first if you want to read any other channel
   // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
   // Use the following macros to:
   
   // Enable the Global Interrupts
   INTERRUPT_GlobalInterruptEnable();

   // Enable the Peripheral Interrupts
   INTERRUPT_PeripheralInterruptEnable();
   // Disable the Global Interrupts
   //INTERRUPT_GlobalInterruptDisable();

   // Disable the Peripheral Interrupts
   //INTERRUPT_PeripheralInterruptDisable();
   delay_ms(500);
   while (1) {
      writeRainbow();
      if (SWITCH_GetValue() == 0) {
         playPong();
      }
      else {
         playTugOfWar();
      }
   }
}

uint8_t getADCClipped(void)
{
   uint8_t adc = ADRESH;
   if (adc < MINBRIGHT)
      adc = MINBRIGHT;
   return adc;
}

void writePlayerPuck(uint8_t puckPos, bool play1)
{
   uint8_t brightness = getADCClipped();
   INTERRUPT_GlobalInterruptDisable();
   for (int i = 0; i < NLEDS; i++) {
      if (i == puckPos) {
         if (play1) {
            SPI1_Exchange8bit(0);
            SPI1_Exchange8bit(brightness);
            SPI1_Exchange8bit(0);
         }
         else {
            SPI1_Exchange8bit(0);
            SPI1_Exchange8bit(0);
            SPI1_Exchange8bit(brightness);
         }
      }
      else {
         SPI1_Exchange8bit(0);
         SPI1_Exchange8bit(0);
         SPI1_Exchange8bit(0);
      }
   }
   INTERRUPT_GlobalInterruptEnable();
   delay_us(75); // Maybe not needed?
}

void restartPong(void)
{
   uint8_t brightness = ADRESL>>6; 
   // The bottom bit of the 10-bit ADC will approximate a random value
   if (brightness & 0x01) {
      // player 1 starts
      isPlayer1Turn = true;
      puckPosition = 0;
      writePlayerPuck(puckPosition, isPlayer1Turn);
   }
   else {
      // player 2 starts
      isPlayer1Turn = false;
      puckPosition = NLEDS - 1;
      writePlayerPuck(puckPosition, isPlayer1Turn);
   }
   player1Score = 0;
   player2Score = 0;
}

// Whenever a button is pushed, start the 10ms timer.
// When the timer is done, read button values into buttonPushed.
// I'll try software start one-shot mode (29.5.5).
// The IOC interrupt will set the timer ON bit.
// This will happen on rising and falling button pushes because of bouncing.
// The timer interrupt will read the pin levels.
// Pin levels will be high only if the button is pushed.
// The timer interrupt will read the IOC flags.
// The flags that are set will only be high if there was a change.
// The timer interrupt will clear the IOC flags.
// Then it will compare flag and levels to set buttonPushed.

// Press and hold will have a high level but low flag.
// Letting go will have a low level and a high flag.
// So I want: if(level && flag) set_buttonPushed
// Press and hold shouldn't block the other user or cheat in tug-of-war.
// I think this will do that.

// I could make this simple using a Timer 4 pin and a Timer 6 pin
// But I want to try to do this using as few resources as possible.

// TMR2 used for LED output generation
// debounced button comes from TMR4
// TMR4 interrupt will find out which button was pushed

void playPong(void)
{
   restartPong(); // resets score, "randomly" chooses player to start
   buttonPushed = 0;
   bool gameDone = false;
   uint8_t line = PLAYTO;
   while (!gameDone) // Game loop
   {
      if (isPlayer1Turn) {
         BUTTON1LED_SetHigh();
         // writePlayerPuck while we wait so brightness can visibly adjust
         while (((buttonPushed & 0x01) != 0x01) && (SWITCH_GetValue() != 1)) {
            writePlayerPuck(puckPosition, isPlayer1Turn);
         }
         BUTTON1LED_SetLow();
      }
      else {
         BUTTON2LED_SetHigh();
         while (((buttonPushed & 0x02) != 0x02) && (SWITCH_GetValue() != 1)) {
            writePlayerPuck(puckPosition, isPlayer1Turn);
         }
         BUTTON2LED_SetLow();
      }
      buttonPushed &= ~(0x03);
      //printf("\n%d %X\n",__LINE__,buttonPushed);
      if (SWITCH_GetValue() == 1) {
         writePlayerPuck(NLEDS, isPlayer1Turn);
         return; // Switch to tug-of-war.
      }
      delay_ms(frameDelay); // so the LED doesn't instantly move
      bool pointDone = false;
      while (!pointDone) // Game point loop
      {
         // Check the button press while the light is lit (at the end of the delay)
         // If the button was pressed, change turns.
         // If the button was not pressed, increment the light and display it.
         // Clear the button press tracker after writing out a light.

         // 1.85 ms to write out the new frame.
         // Check button buffer
         // Clear button buffer
         // User sees new light
         // frameDelay
         // increment or end turn
         // 1.85 ms to write out the new frame.
         // new light

         // As it is written, the wrong light may appear for 2ms or so.
         // But it gives the person the full LED lit time to push the button.

         if (isPlayer1Turn) {
            // Write where the puck is going to be
            if (puckPosition < NLEDS) {
               writePlayerPuck(puckPosition + 1, isPlayer1Turn);
            }
            else {
               writePlayerPuck(NLEDS, isPlayer1Turn); // All off
            }
            // At this point the lit LED is different than puckPosition	 
            // Check if the button was pressed wile puckPosition was lit
            //printf("\n%d %X\n",__LINE__,buttonPushed);
            if (puckPosition > NLEDS - 5 && ((buttonPushed & 0x02) == 0x02)) {
               switch (puckPosition) {
               case NLEDS - 4:
                  frameDelay = SLOWEST;
                  break;
               case NLEDS - 3:
                  frameDelay = SLOW;
                  break;
               case NLEDS - 2:
                  frameDelay = MEDIUM;
                  break;
               case NLEDS - 1:
                  frameDelay = FAST;
                  break;
               case NLEDS:
                  frameDelay = FASTEST;
                  break;
               default:
                  return; // should never happen
                  break;
               }
               //printf("\n%d %X\n",__LINE__,buttonPushed);
               buttonPushed &= ~(0x03);
               isPlayer1Turn = false;
               continue;
            }
            else if (puckPosition == NLEDS) {
               // Failed to push the button in time.
               player1Score++;
               pointDone = true;
               continue; // out of the while loop
            }
            //printf("\n%d %X\n",__LINE__,buttonPushed);
            buttonPushed &= ~(0x03); // clear button buffer after checking
            puckPosition++;
            // At this point the lit LED is the same as puckPosition
            delay_ms(frameDelay);

         }
         else // player 2 turn
         {
            // Write where the puck is going to be
            if (puckPosition > 0) {
               writePlayerPuck(puckPosition - 1, isPlayer1Turn);
            }
            else {
               writePlayerPuck(NLEDS, isPlayer1Turn); // All off
            }
            // At this point the lit LED is different than puckPosition	 
            // Check if the button was pressed wile puckPosition was lit
            //printf("\n%d %X\n",__LINE__,buttonPushed);
            if (puckPosition < 5 && ((buttonPushed & 0x01) == 0x01)) {
               switch (puckPosition) {
               case 4:
                  frameDelay = SLOWEST;
                  break;
               case 3:
                  frameDelay = SLOW;
                  break;
               case 2:
                  frameDelay = MEDIUM;
                  break;
               case 1:
                  frameDelay = FAST;
                  break;
               case 0:
                  frameDelay = FASTEST;
                  break;
               default:
                  return;
                  break;
               }
               //printf("\n%d %X\n",__LINE__,buttonPushed);
               buttonPushed &= ~(0x03);
               isPlayer1Turn = true;
               continue;
            }
            else if (puckPosition == 0) {
               // Failed to push the button in time.
               player2Score++;
               pointDone = true;
               continue; // out of the while loop
            }
            //printf("\n%d %X\n",__LINE__,buttonPushed);
            buttonPushed &= ~(0x03); // clear button buffer after checking	 
            puckPosition--;
            // At this point the lit LED is the same as puckPosition
            delay_ms(frameDelay);
         }

      } // End of point loop

      scoreBlinks(isPlayer1Turn);


      // Figure out what the game line is
      line = PLAYTO;
      if (player1Score > player2Score) {
         if ((player1Score >= PLAYTO && (player1Score - player2Score) >= WINBY) || player1Score == MAXSCORE) {
            // Player 1 won!
            gameDone = true;
            line = player1Score;
         }
         else if (player2Score >= PLAYTO - WINBY) {
            line = player2Score + WINBY;
         }
         // else line stays its initial value of PLAYTO
      }
      else // Player 2 is higher OR there's a tie
      {
         if ((player2Score >= PLAYTO && (player2Score - player1Score) >= WINBY) || player2Score == MAXSCORE) {
            gameDone = true;
            line = player2Score;
         }
         else if (player1Score >= PLAYTO - WINBY) {
            line = player1Score + WINBY;
         }
         // else line stays its initial value of PLAYTO
      }
      if (line > MAXSCORE) {
         line = MAXSCORE;
      }

      // Write out the score and the end-game point "line"
      INTERRUPT_GlobalInterruptDisable();
      for (int j = 0; j < SCOREBLINKTIMES; j++) {
         showScore((j & 0x01) == 0x01, gameDone, isPlayer1Turn, line);
      }
      // In case SCOREBLINKTIMES is odd (j ends even):
      showScore(true, gameDone, isPlayer1Turn, line);
      INTERRUPT_GlobalInterruptEnable();
      
      // Get the next point set up.
      if (isPlayer1Turn) {
         puckPosition = 0;
      }
      else {
         puckPosition = NLEDS - 1;
      }
      frameDelay = MEDIUM;

   } // End of game loop
}

void showScore(bool blinkOn, bool gameDone, bool isP1Turn, uint8_t line)
{
   uint8_t brightness = getADCClipped();
   for (int i = 0; i < NLEDS; i++) {
      if (i < player1Score - 1) {
         SPI1_Exchange8bit(0);
         SPI1_Exchange8bit(brightness);
         SPI1_Exchange8bit(0);
      }
      else if (i > NLEDS - player2Score) {
         SPI1_Exchange8bit(0);
         SPI1_Exchange8bit(0);
         SPI1_Exchange8bit(brightness);
      }
      else if (i == player1Score - 1) {
         if (isP1Turn) {
            if (blinkOn) {
               SPI1_Exchange8bit(0);
               SPI1_Exchange8bit(brightness);
               SPI1_Exchange8bit(0);
            }
            else {
               if (gameDone) {
                  SPI1_Exchange8bit(brightness);
                  SPI1_Exchange8bit(brightness);
                  SPI1_Exchange8bit(brightness);
               }
               else {
                  SPI1_Exchange8bit(0);
                  SPI1_Exchange8bit(0);
                  SPI1_Exchange8bit(0);
               }
            }
         }
         else {
            SPI1_Exchange8bit(0);
            SPI1_Exchange8bit(brightness);
            SPI1_Exchange8bit(0);
         }
      }
      else if (i == NLEDS - player2Score) {
         if (!isP1Turn) {
            if (blinkOn) {
               SPI1_Exchange8bit(0);
               SPI1_Exchange8bit(0);
               SPI1_Exchange8bit(brightness);
            }
            else {
               if (gameDone) {
                  SPI1_Exchange8bit(brightness);
                  SPI1_Exchange8bit(brightness);
                  SPI1_Exchange8bit(brightness);
               }
               else {
                  SPI1_Exchange8bit(0);
                  SPI1_Exchange8bit(0);
                  SPI1_Exchange8bit(0);
               }
            }
         }
         else {
            SPI1_Exchange8bit(0);
            SPI1_Exchange8bit(0);
            SPI1_Exchange8bit(brightness);
         }
      }
      else if (((i == line - 1) || (i == NLEDS - line)) && !gameDone) {
         SPI1_Exchange8bit(brightness);
         SPI1_Exchange8bit(0); // Add red to green to make yellow
         SPI1_Exchange8bit(0);
      }
      else {
         SPI1_Exchange8bit(0);
         SPI1_Exchange8bit(0);
         SPI1_Exchange8bit(0);
      }
   }
   delay_ms(SCOREBLINKDELAYMS);
}

// Somehow put in a "tug of war" game, too.
// Light starts in the middle and button smashing "pushes" the light
// to you opponent.
// I use the "power" switch to switch games.
// Perhaps also to enter "secret" modes?

void writeRainbow(void)
{
   INTERRUPT_GlobalInterruptDisable();
   uint8_t red = 255;
   uint8_t green = 0;
   uint8_t blue = 0;

   do {
      uint8_t redTemp = red;
      uint8_t greenTemp = green;
      uint8_t blueTemp = blue;
      uint8_t brightness = ADRESH; // Check brightness dial every frame
      //uint8_t brightness = 128; // Check brightness dial every frame
      for (int i = 0; i < NLEDS; i++) {
         if (greenTemp > brightness)
            SPI1_Exchange8bit(brightness);
         else
            SPI1_Exchange8bit(greenTemp);
         if (redTemp > brightness)
            SPI1_Exchange8bit(brightness);
         else
            SPI1_Exchange8bit(redTemp);
         if (blueTemp > brightness)
            SPI1_Exchange8bit(brightness);
         else
            SPI1_Exchange8bit(blueTemp);
         getNextRainbowColor(&redTemp, &greenTemp, &blueTemp);
      }
      getNextRainbowColor(&red, &green, &blue);
      delay_ms(RAINBOWDELAYMS);
   }
   while (!(red == 255 && blue == 0 && green == 0));

   // After the rainbow, turn off the LEDs
   for (int i = 0; i < NLEDS; i++) {
      SPI1_Exchange8bit(0);
      SPI1_Exchange8bit(0);
      SPI1_Exchange8bit(0);
   }
   INTERRUPT_GlobalInterruptEnable();
   delay_ms(RAINBOWDELAYMS);
}

void getNextRainbowColor(uint8_t* red, uint8_t* green, uint8_t* blue)
{
   if ((*red == 255) && (*blue == 0) && (*green != 255)) {
      if (*green < 255-RAINBOW_INCREMENT)
         (*green) += RAINBOW_INCREMENT;
      else
         *green = 255;
   }
   else if ((*green == 255) && (*blue == 0) && (*red != 0)) {
      if (*red > RAINBOW_INCREMENT)
         (*red) -= RAINBOW_INCREMENT;
      else
         *red = 0;
   }
   else if ((*red == 0) && (*green == 255) && (*blue != 255)) {
      if (*blue < 255-RAINBOW_INCREMENT)
         (*blue) += RAINBOW_INCREMENT;
      else
         *blue = 255;
   }
   else if ((*red == 0) && (*blue == 255) && (*green != 0)) {
      if (*green > RAINBOW_INCREMENT)
         (*green) -= RAINBOW_INCREMENT;
      else
         *green = 0;
   }
   else if ((*blue == 255) && (*green == 0) && (*red != 255)) {
      if (*red < 255-RAINBOW_INCREMENT)
         (*red) += RAINBOW_INCREMENT;
      else
         *red = 255;
   }
   else if ((*red == 255) && (*green == 0) && (*blue != 0)) {
      if (*blue > RAINBOW_INCREMENT)
         (*blue) -= RAINBOW_INCREMENT;
      else
         *blue = 0;
   }
}

void delay_ms(uint16_t ms)
{
   while(ms > 0)
   {
      __delay_ms(1);
      ms--;
   }
}
void delay_us(uint16_t us)
{
   while(us > 0)
   {
      __delay_us(1);
      us--;
   }
}

void playTugOfWar(void)
{
   uint8_t tugPos = 3;
   uint8_t random = ADRESL>>6; // kind of random. LSB or 10-bit adc
   uint8_t nleds = NLEDS;
   if (((nleds & 0x01) == 0x01) || ((random & 0x01) == 0x01))
   {
      tugPos = nleds >> 1;
   }
   else
   {
      tugPos = (nleds >> 1) - 1;
   }
   uint8_t line1 = 0;
   uint8_t line2 = 0;
   if ((nleds - tugPos) > 10)
   {
      line1 = tugPos-10;
      line2 = tugPos+10;
   }
   else
   {
      line1 = 0;
      line2 = nleds-1;
   }
   bool keepPlaying = true;
   buttonPushed = 0;
   BUTTON1LED_SetHigh();
   BUTTON2LED_SetHigh();
   while(keepPlaying)
   {
      while (((buttonPushed & 0x01) != 0x01) && ((buttonPushed & 0x02) != 0x02) && (SWITCH_GetValue() != 0)) 
      {
         writeTugPuck(tugPos, line1, line2);
      }
      if (SWITCH_GetValue() == 0)
      {
         keepPlaying = false;
         BUTTON1LED_SetLow();
         BUTTON2LED_SetLow();
         return;
      }
      if ((buttonPushed & 0x03) == 0x03) // both buttons pushed
      {
         // do nothing
      }
      else if ((buttonPushed & 0x01) == 0x01)
      {
         if (tugPos < line2-1)
         {
            tugPos++;
         }
         else
         {
            tugPos = nleds;
            keepPlaying = false;
         }
      }
      else if ((buttonPushed & 0x02) == 0x02)
      {
         if (tugPos > line1+1)
         {
            tugPos--;
         }
         else
         {
            tugPos = 0;
            keepPlaying = false;
         }
      }
      // else... not sure why else would happen
      buttonPushed &= ~(0x03);
   }
   BUTTON1LED_SetLow();
   BUTTON2LED_SetLow();
   if (tugPos == 0)
   {
      scoreBlinks(false);
   }
   else
   {
      scoreBlinks(true);
   }
}

void writeTugPuck(uint8_t puckPos, uint8_t line1, uint8_t line2)
{
   uint8_t brightness = getADCClipped();
   INTERRUPT_GlobalInterruptDisable();
   for (int i = 0; i < NLEDS; i++) {
      if (i == puckPos)
      {
         SPI1_Exchange8bit(brightness); //g
         SPI1_Exchange8bit(brightness); //r
         SPI1_Exchange8bit(brightness); //b
      }
      else if (i == line1)
      {
         SPI1_Exchange8bit(0); //g
         SPI1_Exchange8bit(0); //r
         SPI1_Exchange8bit(brightness); //b
      }
      else if (i == line2)
      {
         SPI1_Exchange8bit(0); //g
         SPI1_Exchange8bit(brightness); //r
         SPI1_Exchange8bit(0); //b
      }
      else
      {
         SPI1_Exchange8bit(0); //g
         SPI1_Exchange8bit(0); //r
         SPI1_Exchange8bit(0); //b
      }
   }
   INTERRUPT_GlobalInterruptEnable();
   delay_us(55); // Maybe not needed?
}

void scoreBlinks(bool isP1Turn)
{
         // Output some big blinks to acknowledge the point scored
      INTERRUPT_GlobalInterruptDisable();
      for (int j = 0; j < TURNBLINKTIMES; j++) {
         uint8_t brightness = getADCClipped();
         if ((j & 0x01) != 0x01) {
            if (isP1Turn) {
               for (int i = 0; i < NLEDS; i++) {
                  if ((i & 0x01) == 0x01)
                  {
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(brightness);
                     SPI1_Exchange8bit(0);                     
                  }
                  else
                  {
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(0);                     
                  }
               }
            }
            else {
               for (int i = 0; i < NLEDS; i++) {
                  if ((i & 0x01) == 0x01)
                  {
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(brightness);                     
                  }
                  else
                  {
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(0);                     
                  }
               }
            }
         }
         else {
            if (isP1Turn) {
               for (int i = 0; i < NLEDS; i++) {
                  if ((i & 0x01) != 0x01)
                  {
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(brightness);
                     SPI1_Exchange8bit(0);                     
                  }
                  else
                  {
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(0);                     
                  }
               }
            }
            else {
               for (int i = 0; i < NLEDS; i++) {
                  if ((i & 0x01) != 0x01)
                  {
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(brightness);                     
                  }
                  else
                  {
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(0);
                     SPI1_Exchange8bit(0);                     
                  }
               }
            }
         }
         delay_ms(TURNBLINKDELAYMS);
      }
      // Write out a blank again.
      for (int i = 0; i < NLEDS; i++) {
         SPI1_Exchange8bit(0);
         SPI1_Exchange8bit(0);
         SPI1_Exchange8bit(0);
      }
      INTERRUPT_GlobalInterruptEnable();
      delay_ms(TURNBLINKDELAYMS);
}

/**
 End of File
 */