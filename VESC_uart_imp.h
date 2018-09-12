// VESC_uart_imp.h

#ifndef _VESC_UART_IMP_h
#define _VESC_UART_IMP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define UART_BAUD_RATE 115200

#include "datatypes.h"
#include "bldc_interface_uart.h"

#include "bldc_interface.h"

static void send_packet(unsigned char * data, unsigned int len);
void comm_uart_init(void);
void bldc_val_received(mc_values * val);


#endif

