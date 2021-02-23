### Primera Parte

const int LED0 = 4;
const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 7;
const int LED4 = 8;
const int LED5 = 9;
const int PB_UP = 2;
const int PB_DOWN = 3;
int led0 = LOW, led1 = LOW;

const int TIMING_DELAY = 250;

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
  digitalWrite(LED0,led0);
  digitalWrite(LED1,led1);	

}


void loop(){

    int num =0;
    int led2 = 0, led3 = 0, led4 = 0, led5 = 0;
    int i=0, state = 0;
    int pb_val1 = digitalRead(PB_UP);
    int pb_val2 = digitalRead(PB_DOWN);	

  


        switch(state){
          
          case 0:
              if(((pb_val1 == 0) & (pb_val2 == 0)) || ((pb_val1 == 1) & (pb_val2 == 0))){					
                         for(i=0;i<=64;i++){
        					num = i; 
                
                		  led0 = num & 0b0000001;
                          led1 = num & 0b0000010;
                          led2 = num & 0b0000100;
                          led3 = num & 0b0001000;
                          led4 = num & 0b0010000;
                          led5 = num & 0b0100000;
    
                          digitalWrite(LED0,led0);
                          digitalWrite(LED1,led1);
                          digitalWrite(LED2,led2);
                          digitalWrite(LED3,led3);
                          digitalWrite(LED4,led4);
                          digitalWrite(LED5,led5);
                          delay(TIMING_DELAY);
    					pb_val1 = digitalRead(PB_UP);
          				pb_val2 = digitalRead(PB_DOWN);
                     
                      if(pb_val1 == 1 & pb_val2 == 0){
                        state = 0;  
    
                      }else if(pb_val1 == 0 & pb_val2 == 1){
                        state = 1;
                        break;
                      }                         
                          if(i==64){
                              i=0;
                          }
                    }
              }
    		
         case 1:
                
               if(((pb_val1 == 0) & (pb_val2 == 0)) || ((pb_val1 == 0) & (pb_val2 == 1))){
    
                   for(i=num;i>=00;i--){
        				num = i;
                     
                          led0 = num & 0b0000001;
                          led1 = num & 0b0000010;
                          led2 = num & 0b0000100;
                          led3 = num & 0b0001000;
                          led4 = num & 0b0010000;
                          led5 = num & 0b0100000;
    
                          digitalWrite(LED0,led0);
                          digitalWrite(LED1,led1);
                          digitalWrite(LED2,led2);
                          digitalWrite(LED3,led3);
                          digitalWrite(LED4,led4);
                          digitalWrite(LED5,led5);
                          delay(TIMING_DELAY);
    					pb_val1 = digitalRead(PB_UP);
          				pb_val2 = digitalRead(PB_DOWN);
                           
                       if(pb_val1 == 1 & pb_val2 == 0){
                         state = 0;  
                         break;
                       }else if(pb_val1 == 0 & pb_val2 == 1){
                         state = 1;
                       } 
                     	if(i==00){
                            i=63;
                        }
                 }
              }
  }
}

