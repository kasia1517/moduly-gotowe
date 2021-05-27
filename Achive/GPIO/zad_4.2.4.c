#include <stdio.h>
#include <LPC21xx.H>

void Delay(){
 
 int ucLoopCounter;
 for(ucLoopCounter=0; ucLoopCounter != 1001; ucLoopCounter++){}
}
	 

int main(){
	int ucLoopCounter;
 while(1){
  IO1DIR = 0x10000;
  IO1SET = 0x10000;
	Delay();
  IO1CLR = 0x10000;
 }
}
