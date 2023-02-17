//defining delay and pulse number parameters

//ward 4,1,9,4      rem(4/4)+1 = mode 1
#define a 400       //4*100uS
#define b 100       //1*100uS
#define c 13        //9+4
#define d 2000      //4*500uS
#define reg 50      //regular interval 50uS

//defining constant input and output pins
const int s1 = 1;   //switch 1 pin
const int s2 = 2;   //switch 2 pin
const int sigA = 4; //signal A pin
const int sigB = 6; //signal B pin

//integers used later for checking switch states and altering pulse number for Mode 1
int pulse;
int s1State;
int s2State;

//setup function
void setup() {

  //initialise input pins for switch 1 and 2
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  
  //initialise output pins for signal A and B
  pinMode(sigA,OUTPUT);
  pinMode(sigB,OUTPUT);
}

//main loop
void loop() {

  //read switch high or low
  s1State = digitalRead(s1);
  s2State = digitalRead(s2);

  //switch 2 high - enable mode 1 signal (pulse number - 3)
  if(s2State == HIGH){
    pulse = c-3;
    SigAB();
  }
  
  //switch 1 low - enable signal A and B 
  else if(s1State == LOW && s2State == LOW){
    pulse = c;
    SigAB();
  } 
  //s1State == HIGH not defined, meaning a HIGH state will do nothing, ie will disable pulse stream
}

//signal A and B
void SigAB(){
  
  //signal B initial pulse
  digitalWrite(sigB, HIGH);
  delay(reg);
  digitalWrite(sigB, LOW); 
  
  //signal A for loop
  for(int i = 0; i < pulse; i++){
    digitalWrite(sigA, HIGH);
    delay(a+reg*i);
    digitalWrite(sigA, LOW);
    delay(b);   
   }

  //delay d between cycles 
  delay(d);
}