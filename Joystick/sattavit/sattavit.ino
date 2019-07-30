#include <ipst.h>
byte x;
void setup() {
  setTextSize(2);
  glcd(2, 0, "Wireless-x")
  Serial1.begin(9600);
}

void loop() {
  while (Serial1.available() > 0)
  x = Serial1.read();
  glcd(1, 0, "HEX= %h   ", x);
  if (x == 0xA)
  {
    fd2(100, 70);
  }
  else if (x == 0xC)
  {
    fd2(40, 100);
  }
    else if (x == 0x7)
  {
    fd2(100, 100);
  }
   else if (x == 0x03)
  {
    bk2(100, 40);
  }
   else if (x == 0x05)
  {
    bk2(40, 100);
  }
  else if (x == 0x08)
  {
    fd2(100, 90);
  }
  else if (x == 0x01)
  {
    bk2(70, 60);
  }
  else if (x == 0x02)
  {
    sr(60);
  }
  else if (x == 0x04)
  {
    sl(60 );
  }
  else ao();

}
