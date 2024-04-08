# include <reg51.h>
#include "lcd.h"


#define LCD_DATAPORT P0                          
sbit RW=P2^5;                                   
sbit RS=P2^6;                                     
sbit EN=P2^7;                                 


void Delay1(unsigned int x)                      
{	   
	unsigned char i, j;
	while(x--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}	

// LCD Command Function
void LCD_Command (unsigned char cmd)              
{  

	LCD_DATAPORT= cmd;                            
	RS=0;
	RW=0;                                                                            
	EN=1;                                            
	Delay1(1);                                      
	EN=0; 
  Delay1(1);                                                                               

}

// LCD Data Function
void LCD_Data (unsigned char Data)
{ 

	LCD_DATAPORT= Data;                           
  RS=1;                                           
	RW=0;                                     
	EN=1;                                           
	Delay1(1);                                     
	EN=0;                                           
	Delay1(1);                                      
	
}
// Intilization OF LCD
void LCD_Intialization()
{                                     
   LCD_Command(0x38);  
   LCD_Command(0x0c); 
   LCD_Command(0x01);  
}

// Set Cursor function (Enter the coloum ond Row, the Cursor position is on that point)

 void Set_cursor(int row, int coloum)
 {      
	 if(row==1)                                          //Row 1
	    { 	LCD_Command(0x80+coloum); }                  //0x80(First Row first Display) + Desired Number of coloum position
			else if(row==2)                                  //Row 2
	    { 	LCD_Command(0xC0+coloum); }                  //0xC0(sercond Row first Display + Desired Number of coloum position)
 
 
 }

 
 


int LCD_Pow(int X,int Y)        
{
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++)
	{
		Result*=X;
	}
	return Result;
}

void LCD_ShowNum(unsigned char Line,unsigned char Column, unsigned int Number,unsigned char Length)  /// show number on lcd
{
	unsigned char i;
	Set_cursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_Data(Number/LCD_Pow(10,i-1)%10+'0');
	}
}



void LCD_ShowString(unsigned char Line,unsigned char Column,char *String)  /// show string on lcd
{
	unsigned char i;
	Set_cursor(Line,Column);
	for(i=0;String[i]!='\0';i++)
	{
		LCD_Data(String[i]);
	}
}