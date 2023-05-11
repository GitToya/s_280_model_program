#include "mbed.h"
#include "Servo.h"
//定数
#define DATA_SIZE 11
const char MOTER = '0';
const char SERVO_X = '1';
const char SERVO_Y ='2';

const float SERVO_MAX_LENGE = 0.7;
const float SERVO_MIN_LENGE = 0.3;

Serial TWE(p9,p10);
PwmOut moter(p25);
Servo x_servo(p26);
Servo y_servo(p22);
  Serial PC(USBTX,USBRX);
//関数群
void receive();
 void moterspeed_decode(char,char);
  float ctoi(char,char);
  
int main()
{
 TWE.baud(115200);
 while(1){
  receive();
 }
}

void receive()
{
    char c_receive_moterspeed[3];
    
        if(TWE.getc()==':')
        {
           
            if(TWE.getc()=='0')
            {
                if(TWE.getc()=='4')
                {
                    if(TWE.getc()=='0')
                    {
                        if(TWE.getc()=='1')
                        {
                            if(TWE.getc()=='0')
                            {

                             c_receive_moterspeed[0] = TWE.getc();
                             c_receive_moterspeed[1] = TWE.getc();
                             c_receive_moterspeed[2] = TWE.getc(); 
                              
               
                              if(c_receive_moterspeed[0]==MOTER)
                              {
                                moter =ctoi(c_receive_moterspeed[1],c_receive_moterspeed[2]);
                                PC.putc( c_receive_moterspeed[2]);
                                
                                
                              }
                              if(c_receive_moterspeed[0]==SERVO_X)
                              {
                                
                                
                                    x_servo = ctoi(c_receive_moterspeed[1],c_receive_moterspeed[2]);
                                    
                              }
                               if(c_receive_moterspeed[0]==SERVO_Y)
                              {
                               
                                    y_servo = ctoi(c_receive_moterspeed[1],c_receive_moterspeed[2]);
                                  
                             
                            }
                          }
                         
                        }
                    }
                }
            }
        }
}


float ctoi(char a,char b) {
    
    if(a== '1')
    {
        return 1.0;
    }else
    {
        if(b=='0') return 0.0;
         if(b=='1') return 0.1;
          if(b=='2') return 0.2;
           if(b=='3') return 0.3;
            if(b=='4') return 0.4;
             if(b=='5') return 0.5;
              if(b=='6') return 0.6;
               if(b=='7') return 0.7;
                if(b=='8') return 0.8;
                 if(b=='9') return 0.9;
                 
    }
}

