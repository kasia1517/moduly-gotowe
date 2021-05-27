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
 
//enum ButtonState {RELASED, PRESSED};
enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};


enum KeyboardState eKeyboardRead(){
	if(0==(S0_bm & IO0PIN)){      /*negacja zeby zwrocilo nam TRUE bo wcisniete przyciski maja stan 0 a chcemy 1*/
		return BUTTON_0;          /*zeby zwrocilo ktory przycisk nacisniety*/
	}
	else if(0==(S1_bm & IO0PIN)){ 
		return BUTTON_1; 					     
	}
	else if(0==(S2_bm & IO0PIN)){ 
		return BUTTON_2; 			
	}
	else if(0==(S3_bm & IO0PIN)){ 
		return BUTTON_3;
	}
	return RELASED;            /*gdy zaden z powyzszych nie jest wcisniety ten mowi o tym ze nie sa wcisniete*/
}


void LedOn(unsigned char ucLedIndeks){

unsigned char ucNumber = ucLedIndeks;

switch(ucNumber){
	case 0:
		IO1SET = LED0_bm;
		IO1CLR = LED1_bm | LED2_bm | LED3_bm;	/*dajemy clr zeby zgasic pozostale diody, koniunkcja bo jakbym dala & to by nie dzialalo gdyby nie wszystkie sie swiecily*/
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

int main(){
	
	enum KeyboardState eResult;    /* definiuje ButtonState jako eResult*/
	
	LedeInit();                    /*kierunek-diody dzialaja na pinach wyjsciowych*/
	KeyboardInit();                /*kierunek-przyciski dzialaja na pinach wejsciowych*/
	
	while(1){  
	eResult = eKeyboardRead();
	switch(eResult){
		case BUTTON_0:              
			LedOn(0); 
			break;                   
		case BUTTON_1:              
			LedOn(1);  
			break;      
		case BUTTON_2:              
			LedOn(2);
			break;      
		case BUTTON_3:              
			LedOn(3);
			break;    
    case RELASED:           /*sytuacja gdzie nic nie naciskamy*/   
			LedOn(4);             /*w instrukcji jest ze trzeba dac 4 gdy nic nie wciskamy*/   	
		  break;      		
		}
	}
}
