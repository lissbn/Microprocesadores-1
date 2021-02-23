const int LED0 = 4;
const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 7;
const int LED4 = 8;
const int LED5 = 9;
const int PB_UP = 2;
const int PB_DOWN = 3;
int i = 0;
int push1 = 0;
int push2 = 0;
int prev = 0;
int prev2 = 0;


void setup()
{
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(PB_UP, INPUT);
  pinMode(PB_DOWN, INPUT);


}
void loop(){
	on();
  	off();
  	cases();

}


void on(){

  	int current = digitalRead(PB_UP);
  	int check = digitalRead(PB_DOWN);
  	
  	  if(current == 0 & push1 == 0 & check == LOW){
  	    push1= 1;
  	  }else if(current != prev & push1 == 1 & check == LOW){
  	    if(current == 0){
  	    	 push1 = 0;
  	        i++;
  	    }
  	  }

   prev = current;

      if(i >= 5){
        i = 5;
      }

}

void off(){

    int current2 = digitalRead(PB_DOWN);
    int check = digitalRead(PB_UP);
      
       if(current2 == 0 & push2 == 0 & check == LOW){
    	push2 = 1;
       }else if(current2 != prev2 & push2 == 1 & check == LOW){
         if(current2 == 0){
        	 push2 = 0;
             i--;
        }
       }

   prev2 = current2;

    if(i <= 0){
    	i = 0;
    }
}

void cases(){

  switch(i){
  	

    	case 0:
    	  digitalWrite(LED0,LOW);
          digitalWrite(LED1,LOW);
          digitalWrite(LED2,LOW);
          digitalWrite(LED3,LOW);
          digitalWrite(LED4,LOW);
          digitalWrite(LED5,HIGH);
    
    	break;
      	case 1:
    	  digitalWrite(LED0,LOW);
          digitalWrite(LED1,LOW);
          digitalWrite(LED2,LOW);
          digitalWrite(LED3,LOW);
          digitalWrite(LED4,HIGH);
          digitalWrite(LED5,LOW);
    	break;
      
      	case 2:
    	  digitalWrite(LED0,LOW);
          digitalWrite(LED1,LOW);
          digitalWrite(LED2,LOW);
          digitalWrite(LED3,HIGH);
          digitalWrite(LED4,LOW);
          digitalWrite(LED5,LOW);
    	break;
      
      	case 3:
    	  digitalWrite(LED0,LOW);
          digitalWrite(LED1,LOW);
          digitalWrite(LED2,HIGH);
          digitalWrite(LED3,LOW);
          digitalWrite(LED4,LOW);
          digitalWrite(LED5,LOW);
    	break;
      
      	case 4:
    	  digitalWrite(LED0,LOW);
          digitalWrite(LED1,HIGH);
          digitalWrite(LED2,LOW);
          digitalWrite(LED3,LOW);
          digitalWrite(LED4,LOW);
          digitalWrite(LED5,LOW);
    	break;
      
      	case 5:
    	  digitalWrite(LED0,HIGH);
          digitalWrite(LED1,LOW);
          digitalWrite(LED2,LOW);
          digitalWrite(LED3,LOW);
          digitalWrite(LED4,LOW);
          digitalWrite(LED5,LOW);
    	break;
  }

}