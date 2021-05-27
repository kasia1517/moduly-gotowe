#include <stdio.h>
#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

#define S0_bm 0x00000010
#define S1_bm 0x00000040 /*COS ZLE JEST BO NA TO REAGUJE BUT 2 przyciski to wejscia wiec dir 0*/
#define S2_bm 0x00000020
#define S3_bm 0x00000080
 
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

void LedeInit(){
 IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
 }

unsigned char ucReadButton1(){
 if(S2_bm & IO0PIN){
  return 0;
 }
 else{
  return 1;
 }
}

int main(){

  LedeInit();
	
	while(1){
	if(1 == ucReadButton1()){
  LedOn(1);
	IO1CLR = LED0_bm;
	}
	else if(0 == ucReadButton1()){
  LedOn(0);
	IO1CLR = LED1_bm;
	}
}
}
		

