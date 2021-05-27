#include <stdio.h>
#include <LPC21xx.H>
#define LED0_bm 0x00010000

void Delay(int LiczbaPodana){
	
	unsigned char ucLoopCounter;
	int Opoznienie=LiczbaPodana*11999;
	
 for(ucLoopCounter=0; ucLoopCounter<Opoznienie; ucLoopCounter++){}
}
	 

int main(){
	
 while(1){
  IO1DIR = LED0_bm;
  IO1SET = LED0_bm;
	Delay(100);
  IO1CLR = LED0_bm;
	Delay(100);
 }
}