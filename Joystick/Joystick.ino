#include <ipst.h>
#define L 3
#define R 4 
/*#define vl 415
#define vr 670*/
#define vl 630
#define vr 630
byte x;
void setup() {
  OK();
  Serial1.begin(9600);
  //fd2(50, 50); delay(500); ao();
  servo(2,0);
  setTextSize(2);
  /*Go_Right();
  Go_To_Keep();*/
  
  qqq();
  
}
void loop () {
  //fff();
}

void Go_To_Keep(){
   while(1){
    if(analog(1) < vl && analog(R) <vr ){
          break;
      } 
    else if (analog(1) < vl && analog(R) > vr){ sl(50); } 
    else if (analog(1) > vl && analog(R) < vr){sr(50);} 
    else if (analog(1) > vl && analog(R) > vr){ bk(70);} 
    }
   ao(); bk(50); delay(200); ao();
   servo(2,105);
  /*fd(50); delay(1000); ao();
  sr(50); delay(1000);ao();
  sr(50);
    while(analog(R)>vr) ; ao();
     sr(50);
    while(analog(L)< vl || analog(R)< vr ) ; ao();
    sr(50);delay(100); ao();
  servo (2,105);
  fd(50);
  while(analog(1) > 500 || analog(2) > 500);
  ao(); 
  bk(40);
  while(analog(3) > 500||analog(4) >500); ao();
  //bk(50); delay(1000);  ao();

  servo(2,105);*/
   
}


void Go_Track(){
    while(1){
    if(analog(L) < vl && analog(R) <vr ){
         ao(); break;
      } 
    else if (analog(L) < vl && analog(R) > vr){ sl(50); } 
    else if (analog(L) > vl && analog(R) < vr){sr(50);} 
    else if (analog(L) > vl && analog(R) > vr){ fd(70);} 
    }
   ao();  fd(50); delay(200); ao();
}
void Go_Left(){ 
    while(1){
    if(analog(L) < vl && analog(R) <vr ){
         ao(); break;
      } 
    else if (analog(L) < vl && analog(R) > vr){ sl(50); } 
    else if (analog(L) > vl && analog(R) < vr){sr(50);} 
    else if (analog(L) > vl && analog(R) > vr){ fd(70);} 
    }
    fd(65); delay(200);
    sl(50); delay(100);
    sl(50);
    while(analog(L)>vl) ; ao();
     sl(50);
    while(analog(L)< vl || analog(R)< vr) ; ao();
    sl(50); delay(100);ao();
}
void Go_Right(){
    while(1){
    if(analog(L) < vl && analog(R) <vr ){
         ao(); break;
      } 
    else if (analog(L) < vl && analog(R) > vr){ sl(50); } 
    else if (analog(L) > vl && analog(R) < vr){sr(50);} 
    else if (analog(L) > vl && analog(R) > vr){ fd(70);} 
    }
    fd(65); delay(200);
    sr(50); delay(100);
    sr(50);
    while(analog(R)>vr) ; ao();
     sr(50);
    while(analog(L)< vl || analog(R)< vr ) ; ao();
    sr(50);delay(100); ao();
}

void qqq() {
  while(1){
  while (Serial1.available() > 0)
    x = Serial1.read();

  
  if (x == 0xFF)//เดินหน้าเลี้ยงขวา
  {
    break;
   }
  else if (x == 0x10)//ถอยหลัง
  {
      fd2(80, 80);
  }
  

  else if (x == 0x80)//เดินหน้า
  {
      bk2(80, 80);
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
     sr(75);
  }
  else if (x == 0x20)//เลี้ยงขวา
  {
     sr(75);
  }
  
  else if (x == 0x40)//เลี้ยงซ้าย
  {
     sl(75);
  }
  else if (x == 0x8)//ขึ้น
  {
    servo (2,105);
   // delay (200);
   // servo (2, -1);
  }
  else if (x == 0x4)//ลง
  { servo (2,0);
   // delay (200);
    //servo (2, -1);
   
    
  }

  
  else if (x == 0xFF)//เข้า auto
  {
    break;
  }
  else ao();

    glcd(0,0," %h ",x);
    glcdClear();
  }

  //Go_Track();
}

void fff(){
  glcd(0,0,"A1 = %d ",analog(1));
  glcd(1,0,"A2 = %d",analog(2));
}
