#include <stdio.h>
#include <LPC21xx.H>
#define LED3_bm 0x00080000

void Delay(int LiczbaPodana){
	
	int ucLoopCounter;
	int Opoznienie=LiczbaPodana*11999;
	
 for(ucLoopCounter=0; ucLoopCounter<Opoznienie; ucLoopCounter++){}
}
	 

int main(){
	
	int ucLoopCounter;
	
 while(1){
  IO1DIR = LED3_bm;
  IO1SET = LED3_bm;
	Delay(100);
  IO1CLR = LED3_bm;
	Delay(100);
 }
}