// 
// 
// 

#include "VESC_uart_imp.h"

#include "datatypes.h"
#include "bldc_interface.h"
#include "bldc_interface_uart.h"


static void send_packet(unsigned char * data, unsigned int len){
	// UART WRITING STUFF
	for(uint8_t i = 0; i < len; i++){
		Serial1.write(data[i]);
	}
}

void comm_uart_init(void){
	// initialize UART
	Serial1.begin(UART_BAUD_RATE);
	
	// initialize BLDC interface and provide send function
	bldc_interface_uart_init(send_packet);
	
	bldc_interface_set_rx_value_func(bldc_val_received);
}

void bldc_val_received(mc_values * val){
	Serial.print("Duty Cycle: "); Serial.println(val->duty_now);
	Serial.print("Fault Code: ");Serial.println(val->fault_code);
	Serial.print("RPM: ");Serial.println(val->rpm);
	Serial.print("Battery Voltage: ");Serial.println(val->v_in);
}
