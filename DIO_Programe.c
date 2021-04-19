/************************** Auther : Ahmed Kamal **************************/
/************************** Date : 19/10/2020    **************************/
/************************** Version : V1         **************************/
/************************** Description :        **************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

void DIO_VidSetPinDirection(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Direction)
{
	if(STATE_OUT == Copy_U8Direction)        /* chech if direction OUTPUT  */
	{
		switch(Copy_U8Port)
		{
			case PortA : SET_BIT(DDRA,Copy_U8Pin);   break;
			case PortB : SET_BIT(DDRB,Copy_U8Pin);   break;
			case PortC : SET_BIT(DDRC,Copy_U8Pin);   break;
			case PortD : SET_BIT(DDRD,Copy_U8Pin);   break;
			default: 								 break;
		}
		
	}
	else if(STATE_IN == Copy_U8Direction)   /* chech if direction Input  */
	{
		switch(Copy_U8Port)
		{
			case PortA : CLR_BIT(DDRA,Copy_U8Pin);   break;
			case PortB : CLR_BIT(DDRB,Copy_U8Pin);   break;
			case PortC : CLR_BIT(DDRC,Copy_U8Pin);   break;
			case PortD : CLR_BIT(DDRD,Copy_U8Pin);   break;
			default: 								 break;
		}
	}
	else
	{
		
	}
	
	
}

void DIO_VidSetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Value)
{
	if(STATE_HIGH == Copy_U8Value)        /* chech if pin FIVE Volte  */
	{
		switch(Copy_U8Port)
		{
			case PortA : SET_BIT(PORTA,Copy_U8Pin);   break;
			case PortB : SET_BIT(PORTB,Copy_U8Pin);   break;
			case PortC : SET_BIT(PORTC,Copy_U8Pin);   break;
			case PortD : SET_BIT(PORTD,Copy_U8Pin);   break;
			default: 								  break;
		}
		
	}
	else if(STATE_LOW == Copy_U8Value)   /* chech if Pin ZERO Volt  */
	{
		switch(Copy_U8Port)
		{
			case PortA : CLR_BIT(PORTA,Copy_U8Pin);   break;
			case PortB : CLR_BIT(PORTB,Copy_U8Pin);   break;
			case PortC : CLR_BIT(PORTC,Copy_U8Pin);   break;
			case PortD : CLR_BIT(PORTD,Copy_U8Pin);   break;
			default: 								  break;
		}
	}
	else
	{
		
	}
}



u8 DIO_VidGetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin)
{
	u8 value;
	switch(Copy_U8Port)
	{
	case PortA : value= GET_BIT(PINA,Copy_U8Pin);   break;
	case PortB : value= GET_BIT(PINB,Copy_U8Pin);   break;
	case PortC : value= GET_BIT(PINC,Copy_U8Pin);   break;
	case PortD : value= GET_BIT(PIND,Copy_U8Pin);   break;
	default: 				    		  			break;
	}
	return value;
}



void DIO_VidSetPortDirection(u8 Copy_U8Port, u8 Copy_U8Direction)
{
	switch(Copy_U8Port)
	{
		case PortA : DDRA=Copy_U8Direction; 		break;
		case PortB : DDRB=Copy_U8Direction; 		break;
		case PortC : DDRC=Copy_U8Direction; 		break;
		case PortD : DDRD=Copy_U8Direction; 		break;
		default: 				    		  		break;
	}
	
}

void DIO_VidSetPortValue(u8 Copy_U8Port, u8 Copy_U8Value)
{
	switch(Copy_U8Port)
	{
		case PortA : PORTA=Copy_U8Value; 			break;
		case PortB : PORTB=Copy_U8Value; 			break;
		case PortC : PORTC=Copy_U8Value; 			break;
		case PortD : PORTD=Copy_U8Value; 			break;
		default: 				    		 	 	break;
	}	
}

void DIO_VidTogglePin(u8 Copy_U8Port,u8 Copy_U8Pin)
{
	switch(Copy_U8Port)
	{
		case PortA : TGL_BIT(PORTA,Copy_U8Pin); 			break;
		case PortB : TGL_BIT(PORTB,Copy_U8Pin); 			break;
		case PortC : TGL_BIT(PORTC,Copy_U8Pin); 			break;
		case PortD : TGL_BIT(PORTD,Copy_U8Pin); 			break;
		default: 						    		 	 	break;
	}
}

void DIO_VidTogglePort(u8 Copy_U8Port)
{
	switch(Copy_U8Port)
	{
		case PortA : PORTA=PORTA^0xFF; 			break;
		case PortB : PORTB=PORTB^0xFF; 			break;
		case PortC : PORTC=PORTC^0xFF; 			break;
		case PortD : PORTD=PORTD^0xFF; 			break;
		default: 						     	break;
	}
}