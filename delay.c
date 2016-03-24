/*  
 *  Class: ECE372a
 * 
 *  Group: 209
 *
 *  Lab: 1 Part 3
 * 
 *  File: delay.c
 * 
 *  Member: Michael Harmon (Software)
 *          Abdul Rana (Hardware)
 *          James Beulke (System Integration)
 *          Ali Hassan (Quality Control)
 */

#include <xc.h>
#include "delay.h"

void delayMs(unsigned int delay){
  int x;
  for(x = 0; x < delay; x++)delayUs(1000);
}

void delayUs(unsigned int delay){
  TMR1 = 0;// Reset Timer Register
  PR1 = delay;// Period Register; Exponents of uS and MHz cancel
  T2CONbits.TCKPS = 3;// Prescaler to 8
  IFS0bits.T1IF = 0;// Interrupt Flag Down
  IPC2bits.T2IP = 7;// Interrupt Priority Default
  T1CONbits.ON = 1;// Start Timer
  while(IFS0bits.T1IF == 0){};// Wait Loop
  IFS0bits.T1IF = 0;
}

