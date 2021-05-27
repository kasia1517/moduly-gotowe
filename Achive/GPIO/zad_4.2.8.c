#include <stdio.h>
#include <LPC21xx.H>

void Delay(){
 
 int ucLoopCounter;
 for(ucLoopCounter=0; ucLoopCounter != 757550; ucLoopCounter++){} /*10hZ TO 0,1S*/
}
	 

int main(){
	int ucLoopCounter;
 while(1){
  IO1DIR = 0x10000;
  IO1SET = 0x10000;
	Delay();
  IO1CLR = 0x10000;
	Delay();
 }
}
