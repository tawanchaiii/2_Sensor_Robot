#include <ipst.h>
byte x;
void setup() {
  OK();
  Serial1.begin(9600);
  //fd2(50, 50); delay(500); ao();
  servo(0,90);
  setTextSize(2);
  glcd(4, 0, "Wireless-x");
  qqq();
  
}
void loop () {
  
}
void qqq() {
  while(1){
  while (Serial1.available() > 0)
    x = Serial1.read();
  if (x == 0xA)//เดินหน้าเลี้ยงขวา
  {
    fd2(80, 50);
  }
  else if (x == 0xC)//เดินหน้าเลี้ยงซ้าย
  {
    fd2(50, 80);
  }
  else if (x == 0x9)//เดินหน้าช้า
  {
    fd2(35, 30);
  }
  else if (x == 0x03)//ถอยหลังเลี้ยงขวา
  {
    bk2(80, 60);
  }
  else if (x == 0x05)//ถอยหลังเลี้ยงซ้าย
  {
    bk2(50, 80);
  }
  else if (x == 0x08)//เดินหน้า
  {
    fd2(65, 60);
  }
  else if (x == 0x01)//ถอยหลัง
  {
    bk2(50, 50);
  }
  else if (x == 0x02)//เลี้ยงขวา
  {
    sr(20);
  }
  else if (x == 0x04)//เลี้ยงซ้าย
  {
    sl(20);
  }
  else if (x == 0x80)//ขึ้น
  {
    servo (2,29);
    delay (200);
    servo (2, -1);
  }
  else if (x == 0x10)//ลง
  {
    servo (2,105);
    delay (200);
    servo (2, -1);
  }
  else if (x == 0x20)//อ้า
  {
    servo (1,105);
    delay (200);
    servo (1, -1);
  }
  else if (x == 0x40)//หุบ
  {
    servo (1, 15);
    delay (1000);
  }
  else if (x == 0xFF)//เข้า auto
  {
    break;
  }
  else ao();
  }
}
