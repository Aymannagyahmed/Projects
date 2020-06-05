

#ifndef DE_H_
#define DE_H_

#define Set_Bit(Register,Bit) (Register|=(1<<Bit))
#define Clear_Bit(Register,Bit) (Register &=~(1<<Bit))
#define Get_Bit(Register,Bit) ((Register>>Bit)&1)
#define Toggle_Bit(Register,Bit) (Resgister^=(1<<Bit))



#endif /* DE_H_ */