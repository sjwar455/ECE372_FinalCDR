/* 
 * File:  main.c
 * Author: sam w (TEAM 207)
 * Description: TODO
 * 
 */

#include <xc.h>
#include <sys/attribs.h>
#include "config.h"
#include "adc.h"
#include "timer.h"
#include "pwm.h"
#include "interrupt.h"


typedef enum{
     GO, STOP, TURNLEFT, TURNRIGHT, CHECKSENSORS
}stateType;

volatile stateType state = STOP;

int main(void)
{
    SYSTEMConfigPerformance(10000000);
    enableInterrupts();
    
    initMotors();
    initADC();
    
    while(1)
    {
    
    }
    
    return 0;
}

//pic32MX470L datasheet has example code
//they use the adc slightly different way, but the logic is the same 
// we use the same registers just use different names for those registers


