/* 
 * File:   adc.h
 * Author: sam w (TEAM 207)
 * Date: 24 March 2016
 * Description: This file declares the functions and relevant values and registers
 *              associated with the Analog to Digital Converter module 
 * 
 */

#ifndef ADC_H
#define	ADC_H

/* These buffers will be used to read the voltages across each Photo Transistor
 * in each of the IR Modules
 *
 * These are the values we will use to determine the robot's position with
 *  respect to the black tape path it is supposed to follow
 */
#define IRMOD_CENTER ADC1BUF1 // (Center) IR Module 1
#define IRMOD_LEFT ADC1BUF2 // (Front Left) IR Module 2
#define IRRMOD_RIGHT ADC1BUF3 // (Front Right) IR Module 3

/*Tape Determination
 * These values will help determine whether an IR Module is "on" black tape or 
 * "off" of the black tape.
 * 
 * These values are only temporary and will need to be tested
 */
#define ON_BLACKTAPE 800 /*if any of the above adc buffers are greater than or 
                         * equal to this value, then that IR Module is on black tape
                         */

#define OFF_BLACKTAPE 200/*if any of the above adc buffers are less than or 
                         * equal to this value, then that IR Module is NOT on black tape
                         */

void initADC();


#endif	/* ADC_H */