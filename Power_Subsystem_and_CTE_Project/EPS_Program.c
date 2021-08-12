/*****************************************************************************/
/* Title        	: 	EPS Subsystem Project   				             */
/* File Name    	: 	EPS_Program.c                                        */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	17/09/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

#include "EPS_Interface.h"



extern uint8 DataFrame[FRAME_SIZE] =
  {
	   START_OF_FRAME,
	   SOURCE_ADDRESS,
	   DESTINATION_ADDRESS,
	   0, 0, 0, 0, 0, 0,
	   END_OF_FRAME
  };


uint16 Temperature_u16ReadValue(uint8 Copy_u8ChannelNumber){

	uint16 Local_u16Temperature = 0;

	Local_u16Temperature = (ADC_u16ReadValue(Copy_u8ChannelNumber)/2.05);

	return Local_u16Temperature;

}



uint16 Voltage_u16ReadValue(uint8 Copy_u8ChannelNumber){

	uint16 Local_u16DigitalValue = 0;

	Local_u16DigitalValue = ((ADC_u16ReadValue(Copy_u8ChannelNumber)*5)/1012);

	return Local_u16DigitalValue;
}


uint16 Current_u16ReadValue(uint8 Copy_u8ChannelNumber){

	uint16 Local_u16Value  = 0;
	uint16 Local_u16ACSCurrent = 0;

	Local_u16Value = (ADC_u16ReadValue(Copy_u8ChannelNumber))/(0.2);

	Local_u16ACSCurrent = (Local_u16Value*5)/1024;

	return Local_u16ACSCurrent;
}



