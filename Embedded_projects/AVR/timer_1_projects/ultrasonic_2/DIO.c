#include "DIO_Interface.h"

void DIO_Init(void)
{
	u8 PinNum_InPort;
	Port_type Port;
	PinStatus_type Status;
	u8 LocalIterator;
	
	for (LocalIterator=0;LocalIterator<TOTAL_PINS;LocalIterator++)
	{
		Status=PinsStatus[LocalIterator];
		Port=LocalIterator/8;
		PinNum_InPort=LocalIterator%8;
		
		switch (Status)
		{
			case OUTPUT:
			switch (Port)
			{
				case PA:
				SET_BIT(DDRA,PinNum_InPort);
				break;
				case PB:
				SET_BIT(DDRB,PinNum_InPort);
				break;
				case PC:
				SET_BIT(DDRC,PinNum_InPort);
				break;
				case PD:
				SET_BIT(DDRD,PinNum_InPort);
				break;
			}
			break;
			case INPULLUP:
			switch (Port)
			{
				case PA:
				CLEAR_BIT(DDRA,PinNum_InPort);
				SET_BIT(PORTA,PinNum_InPort);
				break;
				case PB:
				CLEAR_BIT(DDRB,PinNum_InPort);
				SET_BIT(PORTB,PinNum_InPort);
				break;
				case PC:
				CLEAR_BIT(DDRC,PinNum_InPort);
				SET_BIT(PORTC,PinNum_InPort);
				break;
				case PD:
				CLEAR_BIT(DDRD,PinNum_InPort);
				SET_BIT(PORTD,PinNum_InPort);
				break;
			}
			break;
			case INFREE:
			switch (Port)
			{
				case PA:
				CLEAR_BIT(DDRA,PinNum_InPort);
				CLEAR_BIT(PORTA,PinNum_InPort);
				break;
				case PB:
				CLEAR_BIT(DDRB,PinNum_InPort);
				CLEAR_BIT(PORTB,PinNum_InPort);
				break;
				case PC:
				CLEAR_BIT(DDRC,PinNum_InPort);
				CLEAR_BIT(PORTC,PinNum_InPort);
				break;
				case PD:
				CLEAR_BIT(DDRD,PinNum_InPort);
				CLEAR_BIT(PORTD,PinNum_InPort);
				break;
			}
			break;
		}
		
	}
}

void DIO_WritePort(Port_type Port,u8 Value)
{
	switch (Port)
	{
		case PA:
		ASSIGN_REG(PORTA,Value);
		break;
		case PB:
		ASSIGN_REG(PORTB,Value);
		break;
		case PC:
		ASSIGN_REG(PORTC,Value);
		break;
		case PD:
		ASSIGN_REG(PORTD,Value);
		break;
	}
}
void DIO_WriteBitsInPort(Port_type Port,u8 Value,u8 Mask)
{
	switch (Port)
	{
		case PA:
		CLEAR_BITS_REG(PORTA,Mask);
		SET_BITS_REG(PORTA,Value&Mask);
		break;
		case PB:
		CLEAR_BITS_REG(PORTB,Mask);
		SET_BITS_REG(PORTB,Value&Mask);
		break;
		case PC:
		CLEAR_BITS_REG(PORTC,Mask);
		SET_BITS_REG(PORTC,Value&Mask);
		break;
		case PD:
		CLEAR_BITS_REG(PORTD,Mask);
		SET_BITS_REG(PORTD,Value&Mask);
		break;
	}
}
u8 DIO_ReadPort(Port_type Port)
{
	switch (Port)
	{
		case PA:
		return PINA;
		break;
		case PB:
		return PINB;
		break;
		case PC:
		return PINC;
		break;
		case PD:
		return PIND;
		break;
		default:
		return 0x00;
		break;
	}
}
void DIO_WritePin(PinNum_type Pin,VoltageLevel_type Value)
{
	u8 PinNum_InPort=Pin%8;
	Port_type Port=Pin/8;
	switch (Port)
	{
		case PA:
		if (HIGH==Value)
		{
			SET_BIT(PORTA,PinNum_InPort);
		}
		else
		{
			CLEAR_BIT(PORTA,PinNum_InPort);
		}
		break;
		case PB:
		if (HIGH==Value)
		{
			SET_BIT(PORTB,PinNum_InPort);
		}
		else
		{
			CLEAR_BIT(PORTB,PinNum_InPort);
		}
		break;
		case PC:
		if (HIGH==Value)
		{
			SET_BIT(PORTC,PinNum_InPort);
		}
		else
		{
			CLEAR_BIT(PORTC,PinNum_InPort);
		}
		break;
		case PD:
		if (HIGH==Value)
		{
			SET_BIT(PORTD,PinNum_InPort);
		}
		else
		{
			CLEAR_BIT(PORTD,PinNum_InPort);
		}
		break;
	}
}
void DIO_TogglePin(PinNum_type Pin)
{
	u8 PinNum_InPort=Pin%8;
	Port_type Port=Pin/8;
	switch (Port)
	{
		case PA:
			TOOGLE_BIT(PORTA,PinNum_InPort);
		break;
		case PB:
			TOOGLE_BIT(PORTB,PinNum_InPort);
		break;
		case PC:
			TOOGLE_BIT(PORTC,PinNum_InPort);
		break;
		case PD:
			TOOGLE_BIT(PORTD,PinNum_InPort);
		break;
	}
}
VoltageLevel_type DIO_ReadPin(PinNum_type Pin)
{
	u8 PinNum_InPort=Pin%8;
	Port_type Port=Pin/8;
	switch (Port)
	{
		case PA:
		return CHECK_BIT(PINA,PinNum_InPort);
		break;
		case PB:
		return CHECK_BIT(PINB,PinNum_InPort);
		break;
		case PC:
		return CHECK_BIT(PINC,PinNum_InPort);
		break;
		case PD:
		return CHECK_BIT(PIND,PinNum_InPort);
		break;
		default:
		return 0x00;
		break;
	}
}

