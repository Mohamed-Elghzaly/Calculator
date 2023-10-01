/* 
 * File:   application.c
 * Author: Mohamed Elghzaly
 *
 * Created on September 3, 2023, 12:00 AM
 */

#include"application.h"




uint8 counter = MaxElement;

uint8 Key = 0;
uint8 Flag = 0;

uint32 Number1 = 0;
uint8 Number1_counter = 0;
uint8 Number1_txt[MaxElement] = {0};

uint32 Number2 = 0;
uint8 Number2_txt[MaxElement] = {0};
uint8 Number2_counter = 0;

uint8 Operator = 0;

uint32 Result = 0;
uint8 Result_txt[MaxElement] = {0};

int main() {

    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    
    lcd_8bit_send_string_pos(&lcd_2, 1, 5, "Welcome");
    __delay_ms(1000);
    lcd_8bit_send_string_pos(&lcd_2, 2, 1, "Mohamed Elghzaly");
    __delay_ms(1000);
    ret = lcd_8bit_send_command(&lcd_2, _LCD_CLEAR);
    
    while(TRUE){
        counter = MaxElement;
        while(counter>0){
            Number1_txt[counter] = 0;
            Number2_txt[counter] = 0;
            counter--;
        }
        Number1_counter = 0;
        Number2_counter = 0;
        Flag = 0;
        while(Key < '*' || Key > '/'){
            ret = keypad_get_value(&keypad_1, &Key, &Flag);
            if(Key == '#'){
            Flag = 0;
            }
            if(Flag == 1){
                __delay_ms(250);
                Number1_txt[Number1_counter] = Key;
                ret = lcd_8bit_send_string_pos(&lcd_2, 1, 1, Number1_txt);
                Flag = 0;
                Number1_counter++;
                Number1 = atoi(Number1_txt);
            }
        }
        Operator  = Key;
        Key = 0;
        while(Key != '='){
            ret = keypad_get_value(&keypad_1, &Key, &Flag);
            if(Flag == 1){
                __delay_ms(250);
                Number2_txt[Number2_counter] = Key;
                ret = lcd_8bit_send_string_pos(&lcd_2, 1, Number1_counter+1, Number2_txt);
                Flag = 0;
                Number2_counter++;
                Number2 = atoi(Number2_txt);
            }
        }
        switch(Operator){
            case '+' : Result = Number1 + Number2  ; break;
            case '-' : Result = Number1 - Number2  ; break;
            case '*' : Result = Number1 * Number2  ; break;
            case '/' : Result = Number1 / Number2  ; break;
            default : ;
        }
        convert_uint32_to_string(Result, Result_txt);
        ret = lcd_8bit_send_string_pos(&lcd_2, 2, 1, Result_txt);
        while(Key != '#'){
            ret = keypad_get_value(&keypad_1, &Key, &Flag);
            if(Key == '#'){
            ret = lcd_8bit_send_command(&lcd_2, _LCD_CLEAR);
            Flag = 0;
            }
        }
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}