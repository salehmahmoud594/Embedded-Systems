/* 
 * File:   application.c
 * Author: Saleh Mahmoud
 * Created on October 31, 2020
 */

#include "application.h"

led_t led1 = {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN0, .led_status = LED_OFF};
led_t led2 = {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN1, .led_status = LED_OFF};
led_t led3 = {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN2, .led_status = LED_OFF};

button_t btn2 = {.port_name = PORTD_INDEX, .pin = PIN1, .button_status = BUTTON_NOT_PRESSED};
uint8_t btn2_status = ZERO_INIT;

int main() {
    uint8_t count =0;
	
    led_initialize(&led1);
    led_initialize(&led2);
    led_initialize(&led3);
	
    button_initialize(&btn2);
    
    while(TRUE){
        button_get_status(&btn2, &btn2_status);
        
        if(btn2_status == BUTTON_PRESSED){
			
            if(count == 0 )
			{
                led_turn_on(&led1);
                __delay_ms(500);
                led_turn_off((&led1));
                count++;
            }
            else if(count == 1)
			{	
				for(uint8_t i = 0; i < 2; i++)
				{
					led_turn_on(&led2);
					__delay_ms(500);
					led_turn_off((&led2));
					__delay_ms(500);
				}	
                count++;
            }
            else if(count == 2)
			{	
                for(uint8_t i = 0; i < 3; i++)
				{
					led_turn_on(&led2);
					__delay_ms(500);
					led_turn_off((&led2));
					__delay_ms(500);
				}
                count++;
            }
            else if(count == 3)
			{
                led_turn_on(&led1);
                led_turn_on(&led2);
                led_turn_on(&led3);
                __delay_ms(500);
                count++;
            }
            else if(count == 4)
			{
                led_turn_off(&led1);
                led_turn_off(&led2);
                led_turn_off(&led3);
                __delay_ms(500);
                count = 0;   
            }
        }
    }
}