// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       VESC_UART_arduino.ino
    Created:	2018-09-10 8:51:51 PM
    Author:     ADAM-LAPTOP\adam
*/

// Define User Types below here or use a .h file
//

#include "bldc_interface.h"
#include "bldc_interface_uart.h"
#include "VESC_uart_imp.h"
uint8_t buf[256] = {};
uint8_t buf_ind		= 0;
// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
void setup()
{
	comm_uart_init();
	SERIAL_DEBUG.begin(115200);
}

// Add the main program code into the continuous loop() function
void loop()
{
	//bldc_interface_send_alive();
	delay(200);
	bldc_interface_get_values();
	delay(200);
	//bldc_interface_set_duty_cycle(0.10);
	//delay(200);
	//bldc_interface_get_values();
	//delay(200);
	
	bldc_interface_set_rpm(2000);
	delay(1000);
	bldc_interface_set_rpm(0);
	delay(1000);
}

void serialEvent1(){
	buf_ind = 0;
	unsigned char b = 0; 
	while(SERIALIO.available()){
		b = SERIALIO.read();
		buf[buf_ind++] = b;
		bldc_interface_uart_process_byte(b);
	}
	
	
}