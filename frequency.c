#include <reg51.h>
#include "lcd.h"

sbit Input= P3^4;                  
unsigned int pulses ;


void Delay (unsigned int value)       
{
 unsigned int j;
	   
	for (j=0; j<value ;j++)
	{  
		
		TH1=0xFC;
		TL1=0x66;
		TF1=0;
		TR1=1;
		while(TF1==0);
		TF1=0;
		TR1=0;
	}
}


void main (void) 
{ 
	LCD_Intialization();                      
	Input=1;                                   
	
	while(1)
	{  
  		TMOD=0x15;                         
	    TL0=0x00;                           
	    TH0=0x00;
		  TR0=1;                             
			Delay (1000);                       
		  TR0=0;                              
		  pulses=(TH0*256)+TL0;               
       
		 
		 if (TH0 == 0xFF && TL0 == 0xFF)    /*If the input signal is very slow, then the timer will overflow some time after the first rising edge
                                         arrives. In case of an overflow, show "Error" message on the LCD or "--------" on the seven
                                          segment LED display.*/

			 {
				  LCD_Command(0x01);
          LCD_ShowString(1, 5, "Error");
        } 
		 else 
			 {
        LCD_Command(0x01);
				LCD_ShowString(1,0, "Frequency Countr" );
        LCD_ShowString(2, 1, "Fre:");     
        LCD_ShowNum(2, 6, pulses, 5);
        LCD_ShowString(2, 12, "Hz");
       }	 	  	
}  
	
}
