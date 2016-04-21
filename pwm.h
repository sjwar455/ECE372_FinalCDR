/* 
 * File:   pwm.h
 * Author: sam w (TEAM 207)
 * Description: This file declares the functions and relevant values and registers
 *              associated with the pulse width modulation (pwm) capability of the 
 *              output compare modules
 * 
 *              these output compare modules are used to control the speed and direction
 *               of two external motors 
 */

#ifndef PWM_H
#define PWM_H

/*General PWM Values
 * These values are used throughout the rest of the project 
 *
 */
#define PWM_FREQUENCY 0x7FFF //for 305 Hz (w prescale 1:1) *from pic32MX470 datasheet Section 16: Output Compare
#define GND 0

/*Motor 1 registers
 * These registers are pulled directly from the pic32MX470 datasheet
 * Section 12: I/O Ports 
 * Section 16: Output Compare
 */
#define M1_ENABLE OC4CONbits.ON
#define DUTYCYCLE_M1 OC4RS // Duty Cycle for motor 1's pwm signal. Used to adjust the speed of motor 1
#define M1_PIN_MAP 0b1011  //used to map the directional pins for motor 1 (i.e. M1_POSDIR_PIN and M1_NEGDIR_PIN)

//Directional Pins: 
#define M1_POSDIR_PIN RPD3Rbits.RPD3R /*positive direction pin for motor 1
                                       * set to M2_PIN_MAP when motors are moving 
                                       * in the positive direction;
                                       * set to GND when motors are moving in 
                                       * the negative direction.
                                       */

#define M1_POSDIR_GND LATDbits.LATD3  /* positive direction pin LAT Bit for motor 1
                                       * *set to 0 when motors are moving in negative direction
                                        */

#define M1_NEGDIR_PIN RPE5Rbits.RPE5R /*negative direction pin for motor 1
                                       * set to M2_PIN_MAP when motors are moving 
                                       * in the negative direction;
                                       * set to GND when motors are moving in 
                                       * the positive direction.
                                       */

#define M1_NEGDIR_GND LATEbits.LATE5 /*  negative direction pin LAT Bit  for motor 1
                                       * *set to 0 when motors are moving in postive direction
                                        */

/*Motor 2 registers
 * These registers are pulled directly from the pic32MX470 datasheet
 * Section 12: I/O Ports 
 * Section 16: Output Compare
 */
#define M2_ENABLE OC2CONbits.ON 
#define DUTYCYCLE_M2 OC2RS // Duty Cycle for motor 1's pwm signal. See pwm.c for usage details
#define M2_PIN_MAP 0b1011  // used to map the directional pins for motor 2 (i.e. M2_POSDIR_PIN and M2_NEGDIR_PIN)

//Directional Pins: 
#define M2_POSDIR_PIN RPD1Rbits.RPD1R /*positive direction pin for motor 2
                                       * set to M2_PIN_MAP when motors are moving 
                                       * in the positive direction;
                                       * set to GND when motors are moving in 
                                       * the negative direction.
                                       */

#define M2_POSDIR_GND LATDbits.LATD1  /*positive direction pin LAT Bit for motor 2
                                       * *set to GND when motors are moving in negative direction
                                        */

#define M2_NEGDIR_PIN RPD5Rbits.RPD5R /*negative direction pin for motor 2
                                       * set to M2_PIN_MAP when motors are moving 
                                       * in the negative direction;
                                       * set to GND when motors are moving in 
                                       * the negative direction.
                                       */

#define M2_NEGDIR_GND LATDbits.LATD5 /*negative direction pin LAT Bit for motor 2
                                       * *set to 0 when motors are moving in postive direction
                                        */

void initMotors();
void init_M1();
void init_M2();
void turnLeft();
void turnRight();
void changeDirection();
void go();
void stop();

#endif /*PWM_H*/