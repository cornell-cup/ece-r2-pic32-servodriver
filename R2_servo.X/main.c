/*
 * File:   main.c
 * Author: CornellCup
 *
 * Created on April 28, 2016, 3:51 PM
 */


#include "config.h"
#include <stdint.h>

#define SERVO_MIN   1500    // 600 us
#define SERVO_REST  3750    // 1500 us
#define SERVO_MAX   6000    // 2400 us
#define STEP        18

uint8_t servo;

void main(void) {
    SYSTEMConfigPerformance(40000000UL);
    INTEnableSystemMultiVectoredInt();
    
    PPSOutput(1, RPB3, OC1);        // pin 7
    PPSOutput(2, RPB5, OC2);        // pin 14
    PPSOutput(4, RPB14, OC3);       // pin 25
    PPSOutput(3, RPB2, OC4);        // pin 6
    PPSOutput(3, RPB13, OC5);       // pin 24
    
    mPORTBSetPinsDigitalOut(BIT_3 | BIT_5 | BIT_14 | BIT_2 | BIT_13);
    
    // pwm mode, fault pin disabled, timer 2 time base
    OC1CON = OCCON_ON | OCCON_OCM1 | OCCON_OCM2; 
    OC2CON = OCCON_ON | OCCON_OCM1 | OCCON_OCM2;
    OC3CON = OCCON_ON | OCCON_OCM1 | OCCON_OCM2;
    OC4CON = OCCON_ON | OCCON_OCM1 | OCCON_OCM2;
    OC5CON = OCCON_ON | OCCON_OCM1 | OCCON_OCM2;
    
    SetDCOC1PWM(25000);
    SetDCOC2PWM(25000);
    SetDCOC3PWM(25000);
    SetDCOC4PWM(25000);
    SetDCOC5PWM(25000);
    
    
    // 16-bit timer 2, no interrupt, 1:16 prescale, PR2=50000 -> period = 20ms
    OpenTimer2(T2_32BIT_MODE_OFF | T2_INT_OFF | T2_PS_1_16 | T2_ON, 50000-1);
   
    while (1){
        
    }
    
    
    
    return;
}
