#include <stdio.h>
#include <LPC21xx.H>

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000
#define S0_bm 0x00000010
#define S1_bm 0x00000040 
#define S2_bm 0x00000020
#define S3_bm 0x00000080

void Delay(int LiczbaPodana){
	
	int ucLoopCounter;
	int Opoznienie=LiczbaPodana*11999;
	
 for(ucLoopCounter=0; ucLoopCounter<Opoznienie; ucLoopCounter++){}
}

void LedOn(unsigned char ucLedIndeks){

unsigned char ucNumber = ucLedIndeks;

switch(ucNumber){
	case 0:
		IO1SET = LED0_bm;
		IO1CLR = LED1_bm | LED2_bm | LED3_bm;	
	  break;
	case 1:
		IO1SET = LED1_bm;
		IO1CLR = LED0_bm | LED2_bm | LED3_bm;	
	  break;
	case 2:
		IO1SET = LED2_bm;
		IO1CLR = LED0_bm | LED1_bm | LED3_bm;	
	  break;
	case 3:
		IO1SET = LED3_bm;
		IO1CLR = LED0_bm | LED1_bm | LED2_bm;	
	  break;
	default:
		IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;		
		break;
  }
}

void LedeInit(){
	IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;/*alternatywa bitowa OR, gdy ktores jest TRUE(1) zwraca 1*/
}

void KeyboardInit(){
	IO0DIR= (~S0_bm) & (~S1_bm) & (~S2_bm) & (~S3_bm);     /* negacja bitowa bo inaczej musieliby my zmienic kierunek pozostaBych bitów*/
}


unsigned int uiStepChange = 4;

void StepRight(){
	uiStepChange = (uiStepChange-1)%4;
	LedOn(uiStepChange);
}


int main(){
	LedeInit();
  while(1){
	 StepRight();
	 Delay(250);
 }
}

