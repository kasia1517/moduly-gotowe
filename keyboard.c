#include <LPC21xx.H>
#include "keyboard.h"

#define S0_bm 0x00000010
#define S1_bm 0x00000040 
#define S2_bm 0x00000020
#define S3_bm 0x00000080

enum KeyboardState eKeyboardRead(){
	if((S0_bm & IO0PIN)==0){                         								
		return (BUTTON_0);                             							 
	}
	else if((S1_bm & IO0PIN)==0){ 
		return (BUTTON_1); 					     
	}
	else if((S2_bm & IO0PIN)==0){ 
		return (BUTTON_2);
		}
	else if((S3_bm & IO0PIN)==0){ 
		return (BUTTON_3);
	}
	return (RELASED);                                							  
}

void KeyboardInit(){                                              
	IO0DIR = IO0DIR & (~(S0_bm | S1_bm | S2_bm | S3_bm));           
}