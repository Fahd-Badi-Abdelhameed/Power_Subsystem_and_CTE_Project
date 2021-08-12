/*****************************************************************************/
/* Title        	: 	EPS Subsystem Project   				             */
/* File Name    	: 	EPS_Interface.h                                      */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	17/09/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

#ifndef EPS_INTERFACE_H_
#define EPS_INTERFACE_H_


#define FRAME_SIZE					10


#define IND_START_OF_FRAME		    0
#define IND_SOURCE_ADDRESS		    1
#define IND_DESTINATION_ADDRESS		2
#define IND_VOLTAGE_LEVEL_1		    3
#define IND_VOLTAGE_LEVEL_2		    4
#define IND_CURRENT_LEVEL_1		    5
#define IND_TEMP_READING_1		    6
#define IND_TEMP_READING_2		    7
#define IND_TEMP_READING_3		    8
#define IND_END_OF_FRAME		    9


#define START_OF_FRAME		    0xF0
#define SOURCE_ADDRESS		    0x02
#define DESTINATION_ADDRESS		0x01
#define END_OF_FRAME		    0x0F



uint16 Temperature_u16ReadValue(uint8 Copy_u8ChannelNumber);
uint16 Voltage_u16ReadValue(uint8 Copy_u8ChannelNumber);
uint16 Current_u16ReadValue(uint8 Copy_u8ChannelNumber);



#endif /* EPS_INTERFACE_H_ */
