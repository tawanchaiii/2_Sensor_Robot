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
