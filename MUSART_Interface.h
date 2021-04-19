/*
 * UART_Interface.h
 *
 *  Created on: Nov 11, 2020
 *      Author: acer
 */

#ifndef _MUSART_INTERFACE_H_
#define _MUSART_INTERFACE_H_


void MUSART_VidInit(u32 Copy_U16BaudRate);


void MUSART_VidSendData(u8 Copy_U8Data);

u8 MUSART_VidReceiveDataPolling(void);

void MUSART_VidReceiveDataInterrupt(void);

void MUSART_VidCallBack(u8* Copy_PRXValue ,  void (*MUSART_Func)(void));


#endif
