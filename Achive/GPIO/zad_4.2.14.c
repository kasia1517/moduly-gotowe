#include <stdio.h>
#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

void LedeInit(){
 IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
}

void LedOn(unsigned char ucLedIndeks){

 unsigned char ucNumber = ucLedIndeks;

 switch(ucNumber){
 case 0:
  IO1SET = LED0_bm;
	break;
 case 1:
	IO1SET = LED1_bm;
	break;
 case 2:
	IO1SET = LED2_bm;
	break;
 case 3:
  IO1SET = LED3_bm;
	break;
 default:
  break;
 }
}

int main(){
	  int ucLoopCounter;
	  LedeInit();
    LedOn(2);
}