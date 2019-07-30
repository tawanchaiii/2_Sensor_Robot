#include <ipst.h>
byte x;
//servo1  ยกขึ้น 80  ยกลง   0
//servo2  กาง 0    หุบ   71
void setup() {
  OK();
  setTextSize(2);
  glcd(4, 0, "Wireless-x");
  Serial1.begin(9600);
}

void loop() }
  while (Serial1.available() > 0)
  x = Serial1.read();
  //glcd(1, 0, "HEX= %h   ", x);
  if (x == 0x03)
  {
    fd2(60 , 60);
  }
  else if (x == 0x04)
  {
    bk2(70, 70);
  }
  else if (x == 0x02)
  {
    //tr(50); 
    sr(35);
  }
  else if (x == 0x01)
  {
    //tl(50);
    sl(35);
  }
  else if(x == 0x80){ //7
    servo(1,180);
  }
  else if(x == 0x10){ //4
    servo(1,96);
  }
 
  
 

