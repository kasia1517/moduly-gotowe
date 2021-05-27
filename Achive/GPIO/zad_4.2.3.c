#include <LPC21xx.H>

int main()
{
 while(1){
  IO1DIR = 0x10000;
  IO1SET = 0x10000;
  IO1CLR = 0x10000;
 }
}
