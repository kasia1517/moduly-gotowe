#include <stdio.h> 
#include <LPC21xx.H>

void Delay(int LiczbaPodana){
	
	unsigned char ucLoopCounter;
	float Opoznienie=LiczbaPodana*11999;
	
 for(ucLoopCounter=0; ucLoopCounter<Opoznienie; ucLoopCounter++){}
}
	 

int main(){
	
	
 while(1){
  IO1DIR = 0x10000;
  IO1SET = 0x10000;
	Delay(1000);
  IO1CLR = 0x10000;
 }
}