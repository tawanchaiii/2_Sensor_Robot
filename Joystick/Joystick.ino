#include <ipst.h>
#define L 3
#define R 4
#define vl 630
#define vr 630
byte x;
void setup() {
  OK();
  Serial1.begin(9600);
  servo(1, 0);
  servo(2, 0);
  setTextSize(2);
  //Go_L(); Go_R();
  //setservo();
 // Go_T(); Go_L(); Go_R();
  //while (1) qqq();
 //Go_T() ;
 //qqq();
}
void loop () {
    8checksonsor();
}
void qqq() {
  while (1) {
    while (Serial1.available() > 0)
      x = Serial1.read();
    if (x == 0xFF)//เดินหน้าเลี้ยงขวา
    {
      break;
    }
    else if (x == 0x10)//ถอยหลัง
    {
      fd2(60, 60);
    }
    else if (x == 0x80)//เดินหน้า
    {
      bk2(60, 60);
    }
    else if (x == 0xa0)//ถอยหลัง
    {
      bk2(20, 80);
    }
    else if (x == 0xc0)//ถอยหลัง
    {
      bk2(80, 20);
    }

    else if (x == 0x30)//ถอยหลัง
    {
      fd2(20, 80);
    }
    else if (x == 0x50)//ถอยหลัง
    {
      fd2(80, 20);
    }
    else if (x == 0x20)//เลี้ยงขวา
    {
      sr(50);
    }
    else if (x == 0x40)//เลี้ยงซ้าย
    {
      sl(50);
    }
    else if (x == 0x8)//ขึ้น
    {
      servo (1, 70);
      // delay (200);
      // servo (2, -1);
    }
    else if (x == 0x4)//ลง
    { servo (1, 0);
      // delay (200);
      //servo (2, -1);
    }
    else if (x == 0xFF)//เข้า auto
    {
      break;
    }
    else ao();

    /* glcd(0,0," %h ",x);
      glcdClear();*/
  }

  /// place automatic code here
  fd(50); delay(500);
  Go_T(); Go_L(); Go_R(); //Go_T(); Go_L(); Go_T(); Go_T();
}
