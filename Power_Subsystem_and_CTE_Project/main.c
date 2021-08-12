/*****************************************************************************/
/* Title        	: 	EPS Subsystem Project   				             */
/* File Name    	: 	main.c                                               */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	17/09/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/* ****************************************************************************
* The egyptian space agency training project, summer 2020.					  *
* This version is a modification to the original version that was             *
* used by the Arduino board during training.                                  *
******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "ADC_interface.h"
#include "UART_interface.h"
#include "EPS_Interface.h"


uint8 DataFrame[FRAME_SIZE];


int main(void){

	/* ADC initialization */
	ADC_voidInit();

	/* USART initialization */
	UART_voidInit();

	/******** Configure ADC Pins ***************
	 * Temperature Sensor_1 (PA0) --> Input
	 * Temperature Sensor_2 (PA1) --> Input
	 * Temperature Sensor_3 (PA2) --> Input
	 * Temperature Sensor_1 (PA3) --> Input
	 * Temperature Sensor_2 (PA4) --> Input
	 * Temperature Sensor_3 (PA5) --> Input
	 ********************************************/

	DIO_voidSetPinDirection(PORT_A, PIN0, INPUT);
	DIO_voidSetPinDirection(PORT_A, PIN1, INPUT);
	DIO_voidSetPinDirection(PORT_A, PIN2, INPUT);
	DIO_voidSetPinDirection(PORT_A, PIN3, INPUT);
	DIO_voidSetPinDirection(PORT_A, PIN4, INPUT);
	DIO_voidSetPinDirection(PORT_A, PIN5, INPUT);


	/******** Configure UART Pins ***************
	 * RX(PD0) --> Input
	 * TX(PD1) --> Output
	 ********************************************/

	DIO_voidSetPinDirection(PORT_D, PIN0, INPUT );
	DIO_voidSetPinDirection(PORT_D, PIN1, OUTPUT);

	uint8 ReceiveData = 0;

	while(1){

		  ReceiveData = UART_u8ReceiveByte();
		  _delay_ms(20);
		  UART_voidSendByte('\r');
		  UART_voidSendByte('\n');

		  if(ReceiveData == 'A'){

			  DataFrame[IND_TEMP_READING_1 ] = Temperature_u16ReadValue(CH_A0);
			  DataFrame[IND_TEMP_READING_2 ] = Temperature_u16ReadValue(CH_A1);
			  DataFrame[IND_TEMP_READING_3 ] = Temperature_u16ReadValue(CH_A2);
			  DataFrame[IND_VOLTAGE_LEVEL_1] = Voltage_u16ReadValue(CH_A3	 );
			  DataFrame[IND_VOLTAGE_LEVEL_2] = Voltage_u16ReadValue(CH_A4    );
			  DataFrame[IND_CURRENT_LEVEL_1] = Current_u16ReadValue(CH_A5    );

			  for(uint8 i=0; i<FRAME_SIZE; i++){

				  UART_voidWriteHexadecimalNumber(DataFrame[i]);
				  UART_voidSendStringBlocking("  ");
				  _delay_ms(200);

			  }

		  }
		  else{

			  UART_voidWriteHexadecimalNumber(0x54);
		  	  UART_voidSendStringBlocking("  ");
		  	  _delay_ms(200);
		  }

			UART_voidSendByte('\r');
			UART_voidSendByte('\n');

	}

	return 0;
}

