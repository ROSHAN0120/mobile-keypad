
#include<reg51.h>




//Function declarations
void cct_init(void);
void delay(int);
void lcdinit(void);
void writecmd(int);
void writedata(char);

unsigned char READ_SWITCHES(void);
unsigned char get_key(void);
unsigned char count = 0;

//*******************
//Pin description
/*
P2 is data bus
P3.7 is RS
P3.6 is E
P1.0 to P1.3 are keypad row outputs
P1.4 to P1.7 are keypad column inputs
*/
//********************
// Define Pins
//********************
sbit RowA = P2^0;     //RowA
sbit RowB = P2^1;     //RowB
sbit RowC = P2^2;     //RowC
sbit RowD = P2^3;     //RowD

sbit C1   = P2^4;     //Column1
sbit C2   = P2^5;     //Column2
sbit C3   = P2^6;     //Column3
sbit C4   = P2^7;     //Column4

sbit RS    = P3^6;     //E pin for LCD
sbit E   = P3^7;     //RS pin for LCD


int main(void)
{
   unsigned char key;                // key char for keeping record of pressed key

   cct_init();              // Make input and output pins as required
   lcdinit();               // Initilize LCD
	TMOD = 0x20;
	TH1 = 0xFD;
	SCON = 0x50;
	TR1 =1;
   while(1)
   { 
     key = get_key();       // Get pressed key
	writecmd(0x01);        // Clear screen    
	writedata(key);        // Echo the key pressed to LCD
	SBUF =key;
	while (T1 == 0); 
	T1 = 0; 
   }
}


void cct_init(void)
{
	P2 = 0xf0;   //used for generating outputs and taking inputs from Keypad
	P0 = 0x00;   //used as data port for LCD
	P3 = 0x00;   //used for RS and E   
}



void delay( int a)
{
   int i;
   for(i=0;i<a;i++);   //null statement
}

void writedata(unsigned char t)
{
   RS = 1;             // This is data
   P0 = t;             //Data transfer
   E  = 1;             // => E = 1
   delay(150);
   E  = 0;             // => E = 0
   delay(150);
}


void writecmd(int z)
{
   RS = 0;             // This is command
   P0 = z;             //Data transfer
   E  = 1;             // => E = 1
   delay(150);
   E  = 0;             // => E = 0
   delay(150);
}

void lcdinit(void)
{

     delay(15000);
   writecmd(0x30);
     delay(4500);
 
   writecmd(0x38);    //function set
   writecmd(0x0c);    //display on,cursor off,blink off
   writecmd(0x01);    //clear display
   writecmd(0x06);    //entry mode, set increment
}

//void Return(void)     //Return to 0 location on LCD
//{
  //writecmd(0x02);
    //delay(1500);
//}




unsigned char READ_SWITCHES(void)	
{	
	RowA = 0; RowB = 1; RowC = 1; RowD = 1; 	
	

   
	if (C1 == 0) 
   { 
		   count = 0 ;
      
      delay(10000);
		 	if (C1 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
		

     
				switch (count)
			 {
				case 0: return '7';break;
				case 1 : return 'A';break;
					default :return 'B';break;
			 }				
		 
   }




	if (C2 == 0) 
		
	
	{ 
		   count = 0 ;
  
      delay(10000);
		 	if (C2 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			

     
				switch (count)
			 {
				case 0: return '8';break;
				case 1 : return 'C';break;
				
	
				default :return 'D';break;
			 }				
		 
   }

	
   
	 
	 
	if (C3 == 0) 
		
	
   { 
		   count = 0 ;
 
      delay(10000);
		 	if (C3 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			

     
				switch (count)
			 {
				case 0: return '9';break;
				case 1 : return 'E';break;
				
				
				default :return 'F';break;
			 }				
		 
   }

	 
	 
	if (C4 == 0) 
		
	
	
 { 
		   count = 0 ;
  
      delay(10000);
		 	if (C4 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
	
     
				switch (count)
			 {
				case 0: return '/';break;
				case 1 : return 'G';break;
				
			
				default :return 'H';break;
			 }				
		 
   }


	RowA = 1; RowB = 0; RowC = 1; RowD = 1; 	

	if (C1 == 0) 
   { 
		   count = 0 ;

      delay(10000);
		 	if (C1 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			

				switch (count)
			 {
				case 0: return '4';break;
				case 1 : return 'I';break;

					default :return 'J';break;
			 }				
		 
   }

	 
	 
	 
	if (C2 == 0) 
		
	
	{ 
		   count = 0 ;
   
      delay(10000);
		 	if (C2 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
	

     
				switch (count)
			 {
				case 0: return '5';break;
				case 1 : return 'K';break;
				
						default :return 'L';break;
			 }				
		 
   }

	 
	 
	if (C3 == 0) 
		
	
   { 
		   count = 0 ;

      delay(10000);
		 	if (C3 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
		
		
     
				switch (count)
			 {
				case 0: return '6';break;
				case 1 : return 'M';break;
			
				default :return 'N';break;
			 }				
		 
   }


   if (C4 == 0) 
		
	
	
 { 
		   count = 0 ;

      delay(10000);
		 	if (C4 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
		
     
				switch (count)
			 {
				case 0: return '*';break;
				case 1 : return 'O';break;

				default :return 'P';break;
			 }				
		 
   }
	
	RowA = 1; RowB = 1; RowC = 0; RowD = 1; 	


	 if (C1 == 0) 
   { 
		   count = 0 ;

      delay(10000);
		 	if (C1 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
	
		
     
				switch (count)
			 {
				case 0: return '1';break;
				case 1 : return 'Q';break;

					default :return 'R';break;
			 }				
		 
   }

	 
	 
	 
	if (C2 == 0) 
		
	
	{ 
		   count = 0 ;

      delay(10000);
		 	if (C2 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
	
			
				switch (count)
			 {
				case 0: return '2';break;
				case 1 : return 'S';break;

				default :return 'T';break;
			 }				
		 
   }

	 
	 
	if (C3 == 0) 
		
	
   { 
		   count = 0 ;

      delay(10000);
		 	if (C3 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
		
	

     
				switch (count)
			 {
				case 0: return '3';break;
				case 1 : return 'U';break;

				default :return 'V';break;
			 }				
		 
   }

	
   if (C4 == 0) 
		
	
	
 { 
		   count = 0 ;

      delay(10000);
		 	if (C4 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}

	
     
				switch (count)
			 {
				case 0: return '-';break;
				case 1 : return 'W';break;

				default :return 'X';break;
			 }				
		 
   }
	 
	 
	
	RowA = 1; RowB = 1; RowC = 1; RowD = 0; 	//Test Row D

	if (C1 == 0) 
   { delay(10000); while (C1==0); writecmd(0x01); }
	if (C2 == 0) 
		
	
	{ 
		   count = 0 ;

      delay(10000);
		 	if (C2 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			

     
				switch (count)
			 {
				case 0: return '0';break;
				case 1 : return 'Y';break;

				default :return 'Z';break;
			 }				
		 
   }

	if (C3 == 0) 
   { delay(10000); while (C3==0); return '='; }
	if (C4 == 0) 
   { delay(10000); while (C4==0); return '+'; }

	return 'n';           	// Means no key has been pressed
}

unsigned char get_key(void)           //get key from user
{
	char key = 'n';              //assume no key pressed

	while(key=='n')              //wait untill a key is pressed
		key = READ_SWITCHES();   //scan the keys again and again

	return key;                  //when key pressed then return its value
}
