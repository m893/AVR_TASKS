#ifndef  EXTI_private.h
#define EXTI_private.h

// register to set which mode will work falling ege or riseing ege or on high level or low level  for int 0 and int 1
#define  MCUCR   *((volatile u8 *)0x55)
#define ISC11       3
#define ISC10       2   
#define  ISC01      1
#define  ISC00      0
// register to set which mode will work falling ege or riseing ege or on high level or low level  for int2
#define  MCUCSR    *((volatile u8 *)0x54)
#define ISC2        6
//enable to make interrupt work
#define  GICR       *((volatile u8 *)0x5B)

#define INT0   6
#define INT1   7
#define INT2   5
//flag for every interrupt
#define  GIFR       *((volatile u8 *)0x5A)
#define INTF0   6
#define INTF1   7
#define INTF2   5

 





#endif  