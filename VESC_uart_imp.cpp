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
		SERIALIO.write(data[i]);
	}
}

void comm_uart_init(void){
	// initialize UART
	SERIALIO.begin(UART_BAUD_RATE);
	
	// initialize BLDC interface and provide send function
	bldc_interface_uart_init(send_packet);
	
	bldc_interface_set_rx_value_func(bldc_val_received);
}

void bldc_val_received(mc_values * val){
	SERIAL_DEBUG.print("Battery Voltage\t: ");	SERIAL_DEBUG.println(val->v_in);
	SERIAL_DEBUG.print("Battery Current\t: "); 	SERIAL_DEBUG.println(val->current_in);
	SERIAL_DEBUG.print("Motor Current\t: "); 	SERIAL_DEBUG.println(val->current_motor);
	SERIAL_DEBUG.print("Duty Cycle\t: "); 		SERIAL_DEBUG.println(val->duty_now);
	SERIAL_DEBUG.print("RPM\t\t: ");			SERIAL_DEBUG.println(val->rpm);
	SERIAL_DEBUG.print("Tachometer\t: "); 		SERIAL_DEBUG.println(val->tachometer);
	SERIAL_DEBUG.print("Fault Code \t: ");		SERIAL_DEBUG.println(val->fault_code);
}
