#include <stdio.h>
#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000



void LedOn(unsigned char ucLedIndeks)

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
	

void Delay(int LiczbaPodana){
	
	int ucLoopCounter;
	int Opoznienie=LiczbaPodana*11999;
	
 for(ucLoopCounter=0; ucLoopCounter<Opoznienie; ucLoopCounter++){}
}

void LedeInit(){
 IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
 }


int main(){
	  int ucLoopCounter;
	  unsigned char ucLedIndeks
	  LedeInit();
    LedOn(2);
}