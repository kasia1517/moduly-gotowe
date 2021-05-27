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
 
enum ButtonState {RELASED, PRESSED};

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
	IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;    /*alternatywa bitowa OR, gdy ktores jest TRUE(1) zwraca 1*/
}

enum ButtonState eReadButton1(){
	if(S0_bm & IO0PIN){          /*&-suma bitowa(musza byc spelnione obydwa warunki),S0_bm odpowiada przyciskowi 0, IO0PIN sprawdza styan pinów*/
		return RELASED;
	}
	else{
		return PRESSED; 					 /*zwraca PRESSED gdy wcisniety jest guzik*/
	}
}

//void KeyboardInit(){
	

int main(){
	
	enum ButtonState eResult;    /* definiuje ButtonState jako eResult*/
	
	LedeInit();
	
	while(1){
	eResult = eReadButton1();
	switch(eResult){
		case PRESSED:              /*gdy wcisniety przycisk*/
			LedOn(1);                /*zapala diode 1*/
			IO1CLR = LED0_bm;        /*gasi diode 0*/
			break;                   /*musi byc w switchu*/
			case RELASED:            /*gdy nie wcisniety przycisk*/
			LedOn(0);                               
			IO1CLR = LED1_bm;                       
			break;
		}
	}
}

		

