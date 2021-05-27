#include <stdio.h>
#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

void Delay(int LiczbaPodana){
	
	int ucLoopCounter;
	int Opoznienie=LiczbaPodana*11999;
	
 for(ucLoopCounter=0; ucLoopCounter<Opoznienie; ucLoopCounter++){}
}

int main(){
	int ucLoopCounter;
    while(1){
	  IO1DIR = LED0_bm;
    IO1SET = LED0_bm;
	  Delay(250);
		IO1CLR = LED0_bm;
			
		IO1DIR = LED3_bm;
    IO1SET = LED3_bm;
		Delay(250);
		IO1CLR = LED3_bm;
			
			
	  IO1DIR = LED1_bm;
    IO1SET = LED1_bm;
    Delay(250);
		IO1CLR = LED1_bm;
			
	  IO1DIR = LED2_bm;
    IO1SET = LED2_bm;
    Delay(250);
		IO1CLR = LED2_bm;
			
	  
		}
}