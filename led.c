#include <LPC21xx.H>
#include "led.h"

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

enum StepLedDirection{LEFT, RIGHT};

void LedeInit(){                                                  
	IO1DIR =IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm;                 
	IO1SET = LED0_bm;																								
}

void LedOn(unsigned char ucLedIndeks){                            

IO1CLR = (LED0_bm | LED1_bm | LED2_bm | LED3_bm);	                
	
	if(ucLedIndeks == 0){
		IO1SET = LED0_bm;
	}
	else if(ucLedIndeks == 1){
		IO1SET = LED1_bm;
	}
	else if(ucLedIndeks == 2){
		IO1SET = LED2_bm;
	}
	else if(ucLedIndeks ==3 ){
		IO1SET = LED3_bm;
	}
}

void LedStep(enum StepLedDirection eStepLedDirection){
	
static unsigned int uiStepChange;                                 
	
	if(eStepLedDirection == RIGHT){
		uiStepChange--;                                              
	}
	else{
		uiStepChange++;                                              
	}
	LedOn(uiStepChange%4);                                          
}

void LedStepLeft(){                                               
	LedStep(LEFT);
}

void LedStepRight(){                                              
	LedStep(RIGHT);
}