int trigsensor = 9;//ultrasonic sensor trig declaration
int echosensor = 10;//ultrasonicsensor declaration for measuring the distance between obstacle and sensor
int revofrightmotor = 4;      //motor parts declaration
int fwofleftmotor = 7;      
int revofleftmotor= 6;       
int fwdofrightmotor= 5;       


void setup() {
  Serial.begin(9600); 
  pinMode(trigsensor, OUTPUT);
  pinMode(echosensor, INPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(7, OUTPUT);
   

}
void tyre(float distance){
  
  if(distance>20)//moves straight forward if ultrasonic sensor doesn't sense the obstacle
 {
  digitalWrite(5,HIGH);                                    
   digitalWrite(4,LOW);                              
   digitalWrite(6,LOW);                              
   digitalWrite(7,HIGH);                           
 }
 
  else if(distance<20)  //changes the direction of the motor if robot sense obstacle
 {
   digitalWrite(4,HIGH);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);                                 
   digitalWrite(7,LOW);
   delay(700);
                                       
 
 }
 }
 
void loop() {
  float distance1, distance;
  digitalWrite(trigsensor,LOW);
  delayMicroseconds(2);
  digitalWrite(trigsensor, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigsensor,LOW);
  distance1=pulseIn(echosensor, HIGH);//measures the distance between obstacle and sensor
  distance =(distance1/2)/39.1;
  Serial.println(distance);
  
 tyre(distance); //function call for moving the robot
}
