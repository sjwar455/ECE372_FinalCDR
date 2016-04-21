/* 
 * File:   adc.c
 * Author: sam w (TEAM 207)
 * Date: 24 March 2016
 * Description: This file implements the functions associated with the 
 *              Analog to Digital Converter module 
 * 
 */

#include <xc.h>
#include "adc.h"



//Initializes the ADC 
void initADC(){
    // ADC1 Control Register 1
    AD1CON1bits.FORM = 0; //Data Output Format Bits - Integer 16-bit 
    AD1CON1bits.SSRC = 7; // Conversion Trigger Source Select bits - auto convert
    AD1CON1bits.ASAM = 1; // Auto Sampling on
    
    // ADC1 Control Register 2
    AD1CON2bits.VCFG = 7; //Voltage reference config: VR+ = AVdd & VR- = AVss
    AD1CON2bits.CSCNA = 1; // Scan inputs using MUX A
    AD1CON2bits.SMPI = 15; // Interrupts at the completion of conversion for each 16th sample/convert sequence
    AD1CON2bits.ALTS = 0; //Do not use alternate sampling mode (only using MUX A)
    
    // ADC1 Control Register 3
    AD1CON3bits.ADRC = 0; //Clock derived from peripheral bus clock (PBCLK)
    AD1CON3bits.SAMC = 3; //Auto-Sample Time bits 
    AD1CON3bits.ADCS = 8; // Sample rate?
    
    // ADC1CHS Register
    AD1CHSbits.CH0NA = 0; // Negative Input ( 0 -> Channel 0 negative input is Vrefl)
    
    // ADC1CSSL Register - configure which Analog pins will be used to scan input from
    AD1CSSLbits.CSSL1 = 1; //Scan input from AN1
    AD1CSSLbits.CSSL2 = 1; //Scan input from AN2
    AD1CSSLbits.CSSL3 = 1; //Scan input from AN3
    
    //set interrupt settings
    IFS0bits.AD1IF = 0; // Put down ADC flag
    
    /*not sure if we need to use interrupt routines - just do everything in main for now*/
    //IPC5bits.AD1IP = 7; //interrupt priority level 7
    //IEC0bits.AD1IE = 1; //enable interrupts
    
    
    
    /* TURN ADC ON (**must be last**)
     *  Data sheet does not explain, but insists configuration (above)
     *  must be complete before turning the ADC on
     */
    AD1CON1bits.ADON = 1;
}




 