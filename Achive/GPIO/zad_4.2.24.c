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

#define MILISECOND 11999;

enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};  /* tak jakby przechowuje nam i definuje nazwy przyciskowzeby funkcja nastepna mogla nam je zwracac*/
enum StepLedDirection{LEFT, RIGHT};  

void Delay(int iTimeMs){                                      /*timer robiacy opoznienie*/
	
unsigned int uiLoopCounter;
int iDelation=iTimeMs*MILISECOND;
	
 for(uiLoopCounter=0; uiLoopCounter<iDelation; uiLoopCounter++){}
}

void LedeInit(){                                                  /* ustawia kierunek pinow odp. ledom na wyjsciowy */
	IO1DIR =IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm;                 /*alternatywa bitowa OR, gdy ktores jest TRUE(1) zwraca 1*/
	IO1SET = LED0_bm;																								/*zeby na poczatku palila sie jakas dioda jako punkt odniesienia*/
}

void LedOn(unsigned char ucLedIndeks){                             /*to wlacza diody i gasi pozostale*/

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

enum KeyboardState eKeyboardRead(){
	if((S0_bm & IO0PIN)==0){                         /*wcisniety przycisk ma stan 0 wiec gdy obydwa sa na zero to jest wcisniety*/
		return (BUTTON_0);                               /*zeby zwrocilo ktory przycisk nacisniety*/
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
	return (RELASED);                                  /*gdy zaden z powyzszych nie jest wcisniety lub wcisniete sa inne niz 1 i 2 bo tak jest w poleceniu*/
}

void KeyboardInit(){                                              /* ustawia kierunki pinow odp. przyciskom na wejcsiowe */
	IO0DIR = IO0DIR & (~(S0_bm | S1_bm | S2_bm | S3_bm));              /* negacja bitowa bo inaczej musieliby my zmienic kierunek pozostaBych bitów*/
}

void LedStep(enum StepLedDirection eStepLedDirection){
	
static unsigned int uiStepChange;                /* liczy kroki (przesunieciana), na start obiektowi statycznemu przypisywane jest 0, nie znika po zakonczeniu wywolania funkcji */
	
	if(eStepLedDirection == RIGHT){
		uiStepChange--;             /* w lewo dodaje,modulo(%) zwraca tylko reszte z dzielenia */
	}
	else{
		uiStepChange++;             /* w prawo odejmuje,modulo zwraca tylko reszte z dzielenia */
	}
	LedOn(uiStepChange%4);
}

void LedStepLeft(){
	LedStep(LEFT);
}

void LedStepRight(){
	LedStep(RIGHT);
}

int main(){

	LedeInit();
	KeyboardInit();
	
	while(1){
	
		switch(eKeyboardRead()) {
			case BUTTON_1:
				LedStepRight();
				break;
			case BUTTON_2:
				LedStepLeft();
				break;
		}
		Delay(250);
	}
}