#include "led.h"
#include "keyboard.h"

#define MILISECOND 11999


void Delay(int iTimeMs){                                      								
	
unsigned int uiLoopCounter;																										
int iDelation=iTimeMs*MILISECOND;
	
 for(uiLoopCounter=0; uiLoopCounter<iDelation; uiLoopCounter++){}
}
//sdsdsdsdd

int main(){

	LedeInit();
	KeyboardInit();
	
	while(1){
		switch(eKeyboardRead()){
			case BUTTON_1:
				LedStepRight();
				break;
			case BUTTON_2:
				LedStepLeft();
				break;
			default:
				break;
		}
		Delay(25);
	}
}
