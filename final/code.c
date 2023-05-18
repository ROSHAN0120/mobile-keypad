
#include<reg51.h>




//Function declarations
void cct_init(void);
void delay(int);
void lcdinit(void);
void writecmd(int);
void writedata(char);
void Return(void);
char READ_SWITCHES(void);
char get_key(void);
unsigned int count = 0;
unsigned char val = 0;
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
sbit RowA = P1^0;     //RowA
sbit RowB = P1^1;     //RowB
sbit RowC = P1^2;     //RowC
sbit RowD = P1^3;     //RowD

sbit C1   = P1^4;     //Column1
sbit C2   = P1^5;     //Column2
sbit C3   = P1^6;     //Column3
sbit C4   = P1^7;     //Column4

sbit E    = P3^6;     //E pin for LCD
sbit RS   = P3^7;     //RS pin for LCD


int main(void)
{
   char key;                // key char for keeping record of pressed key

   cct_init();              // Make input and output pins as required
   lcdinit();               // Initilize LCD

   while(1)
   { 
     key = get_key();       // Get pressed key
	        
	 writedata(key);        // Echo the key pressed to LCD
   }
}


void cct_init(void)
{
	P0 = 0x00;   //not used
	P1 = 0xf0;   //used for generating outputs and taking inputs from Keypad
	P2 = 0x00;   //used as data port for LCD
	P3 = 0x00;   //used for RS and E   
}

void delay(int a)
{
   int i;
   for(i=0;i<a;i++);   //null statement
}

void writedata(char t)
{
   RS = 1;             // This is data
   P2 = t;             //Data transfer
   E  = 1;             // => E = 1
   delay(150);
   E  = 0;             // => E = 0
   delay(150);
}


void writecmd(int z)
{
   RS = 0;             // This is command
   P2 = z;             //Data transfer
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
   writecmd(0x30);
     delay(300);
   writecmd(0x30);
     delay(650);
  
   writecmd(0x38);    //function set
   writecmd(0x0c);    //display on,cursor off,blink off
   writecmd(0x01);    //clear display
   writecmd(0x06);    //entry mode, set increment
}

void Return(void)     //Return to 0 location on LCD
{
  writecmd(0x02);
    delay(1500);
}




char READ_SWITCHES(void)	
{	
	RowA = 0; RowB = 1; RowC = 1; RowD = 1; 	
   
	if (C1 == 0) 
   { 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C1 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C1 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C1 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C1 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '7';break;
				case 3 : return 'A';break;
				case 4 : return 'A';break;
				case 5 : return 'B';break;
					default :return 'B';break;
			 }				
		 
   }




	if (C2 == 0) 
		
	
	{ 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C2 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '8';break;
				case 3 : return 'C';break;
				case 4 : return 'C';break;
				case 5 : return 'D';break;
				default :return 'D';break;
			 }				
		 
   }

	
   
	 
	 
	if (C3 == 0) 
		
	
   { 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C3 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C3 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C3 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C3 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '9';break;
				case 3 : return 'E';break;
				case 4 : return 'E';break;
				case 5 : return 'F';break;
				default :return 'F';break;
			 }				
		 
   }

	 
	 
	if (C4 == 0) 
		
	
	
 { 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C4 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C4 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C4 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C4 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '/';break;
				case 3 : return 'G';break;
				case 4 : return 'G';break;
				case 5 : return 'H';break;
				default :return 'H';break;
			 }				
		 
   }


	RowA = 1; RowB = 0; RowC = 1; RowD = 1; 	

	if (C1 == 0) 
   { 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C1 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C1 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C1 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C1 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '4';break;
				case 3 : return 'I';break;
				case 4 : return 'I';break;
				case 5 : return 'J';break;
					default :return 'J';break;
			 }				
		 
   }

	 
	 
	 
	if (C2 == 0) 
		
	
	{ 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C2 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '5';break;
				case 3 : return 'K';break;
				case 4 : return 'K';break;
				case 5 : return 'L';break;
				default :return 'L';break;
			 }				
		 
   }

	 
	 
	if (C3 == 0) 
		
	
   { 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C3 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C3 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C3 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C3 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '6';break;
				case 3 : return 'M';break;
				case 4 : return 'M';break;
				case 5 : return 'N';break;
				default :return 'N';break;
			 }				
		 
   }

	if (C4 == 0) 
   if (C4 == 0) 
		
	
	
 { 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C4 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C4 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C4 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C4 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '*';break;
				case 3 : return 'O';break;
				case 4 : return 'O';break;
				case 5 : return 'P';break;
				default :return 'P';break;
			 }				
		 
   }
	
	RowA = 1; RowB = 1; RowC = 0; RowD = 1; 	


	 if (C1 == 0) 
   { 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C1 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C1 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C1 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C1 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '1';break;
				case 3 : return 'Q';break;
				case 4 : return 'Q';break;
				case 5 : return 'R';break;
					default :return 'R';break;
			 }				
		 
   }

	 
	 
	 
	if (C2 == 0) 
		
	
	{ 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C2 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '2';break;
				case 3 : return 'S';break;
				case 4 : return 'S';break;
				case 5 : return 'T';break;
				default :return 'T';break;
			 }				
		 
   }

	 
	 
	if (C3 == 0) 
		
	
   { 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C3 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C3 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C3 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C3 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '3';break;
				case 3 : return 'U';break;
				case 4 : return 'U';break;
				case 5 : return 'V';break;
				default :return 'V';break;
			 }				
		 
   }

	if (C4 == 0) 
   if (C4 == 0) 
		
	
	
 { 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C4 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C4 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C4 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C4 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '-';break;
				case 3 : return 'W';break;
				case 4 : return 'W';break;
				case 5 : return 'X';break;
				default :return 'X';break;
			 }				
		 
   }
	 
	 
	
	RowA = 1; RowB = 1; RowC = 1; RowD = 0; 	//Test Row D

	if (C1 == 0) 
   { delay(10000); while (C1==0); writecmd(0x01); }
	if (C2 == 0) 
		
	
	{ 
		   count = 0 ;
      count=count+1;
      delay(10000);
		 	if (C2 == 0)
			{				
		     count=count+1;
		    delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}
			if (C2 == 0) 
			{
				count=count+1;
				delay(10000);
			}


     
				switch (count)
			 {
				case 2: return '0';break;
				case 3 : return 'Y';break;
				case 4 : return 'Y';break;
				case 5 : return 'Z';break;
				default :return 'Z';break;
			 }				
		 
   }

	if (C3 == 0) 
   { delay(10000); while (C3==0); return '='; }
	if (C4 == 0) 
   { delay(10000); while (C4==0); return '+'; }

	return 'n';           	// Means no key has been pressed
}

char get_key(void)           //get key from user
{
	char key = 'n';              //assume no key pressed

	while(key=='n')              //wait untill a key is pressed
		key = READ_SWITCHES();   //scan the keys again and again

	return key;                  //when key pressed then return its value
}
