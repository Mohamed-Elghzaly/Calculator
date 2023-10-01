/* 
 * File:   application.h
 * Author: Mohamed Elghzaly
 *
 * Created on September 3, 2023, 12:40 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */
#include <pic18.h>
#include "ECU_Layer/ecu_layer_init.h"

#define TRUE     1
#define FAULSE   0

#define MaxElement   6

extern keypad_t keypad_1;
extern led_t led1;
extern lcd_8bit_t lcd_2;
extern lcd_4bit_t lcd_1;
extern keypad_t keypad_1;

/* Section : Macro Functions Declaration */

/* Section : Data Type Declaration */

/* Section : Function Declaration */
void application_intialize(void);


#endif	/* APPLICATION_H */

