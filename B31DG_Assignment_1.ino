//ward 4,1,9,4    rem(4/4)+1 = mode 1
#define a 400     //4*100uS
#define b 100     //1*100uS
#define c 13      //9+4
#define d 2000    //4*500uS
#define reg 50    //regular interval 50uS
#define s1 34     //switch 1 pin 
#define s2 14     //switch 2 pin 
#define sigA 2    //signalA pin 
#define sigB 5    //signalB pin 

int pulse;
int s1State;
int s2State;

void setup() {

  //initialise input pins for switch 1 and 2
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  
  //initialise output pins for signal A and B
  pinMode(sigA,OUTPUT);
  pinMode(sigB,OUTPUT);
}

void loop() {
  //read switch high or low
  s1State = digitalRead(s1);
  s2State = digitalRead(s2);

  //switch 2 high - enable mode 1 signal
  if(s2State == HIGH){
    pulse = c-3;
    SigAB();
  }
  
  //switch 1 low - enable signal A and B 
  else if(s1State == LOW && s2State == LOW){
    pulse = c;
    SigAB();
  } 
}

//signal A and B
void SigAB(){
  //signal B
  digitalWrite(sigB, HIGH);
  delay(reg);
  digitalWrite(sigB, LOW); 
  //signal A
  for(int i = 0; i < pulse; i++){
    digitalWrite(sigA, HIGH);
    delay(a+reg*i);
    digitalWrite(sigA, LOW);
    delay(b);   
   }
  //delay d between cycles 
  delay(d);
}
