/*
 * UART_Program.c
 *
 *  Created on: Nov 11, 2020
 *      Author: acer
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MUSART_Interface.h"
#include "MUSART_Config.h"
#include "MUSART_Private.h"

#ifndef SYS_CLK
#define SYS_CLK
#endif

static u8* Copy_U8PSet_RXValue = 0 ;

static void (*Copy_PVidRxFunc)(void) = 0 ;

void MUSART_VidInit(u32 Copy_U16BaudRate)
{
	u16 LOC_U16UBRR_Val = (SYS_CLK/(16*Copy_U16BaudRate))-1 ;

	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);

	UBRRL = LOC_U16UBRR_Val ;
	UBRRH = LOC_U16UBRR_Val >> 8 ;

	UCSRC = 0b10000110 ;
}

void MUSART_VidReceiveDataInterrupt(void)
{
	SET_BIT(UCSRB,7);
}

u8 MUSART_VidReceiveDataPolling(void)
{
	u8 LOC_U8RX_Data;
	while(! GET_BIT(UCSRA , 7));
	LOC_U8RX_Data = UDR ;
	return LOC_U8RX_Data ;
}

void MUSART_VidSendData(u8 Copy_U8Data)
{
	while(! GET_BIT(UCSRA , 5));
	UDR = Copy_U8Data ;
}

void MUSART_VidCallBack(u8* Copy_PRXValue , void (*MUSART_Func)(void))
{
	Copy_U8PSet_RXValue = Copy_PRXValue ;
	Copy_PVidRxFunc = MUSART_Func;

}

void __vector_13(void)  __attribute__((signal))
{
	if(Copy_PVidRxFunc != 0)
	{
		*Copy_U8PSet_RXValue = UDR ;
		Copy_PVidRxFunc();
	}
}
