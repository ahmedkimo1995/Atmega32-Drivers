#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

void DIO_VidSetPortDirection(	u8 Copy_U8Port, u8 Copy_U8Direction);

void DIO_VidSetPinDirection(	u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Direction);

void DIO_VidSetPinValue(		u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Value);

void DIO_VidSetPortValue(		u8 Copy_U8Port, u8 Copy_U8Value);

void DIO_VidTogglePin(			u8 Copy_U8Port, u8 Copy_U8Pin);

u8 DIO_VidGetPinValue(			u8 Copy_U8Port, u8 Copy_U8Pin);


#endif