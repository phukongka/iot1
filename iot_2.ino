int led1_pin=25;
int led2_pin=27;
int led1= 0;
int led2= 0;
int speed1 = 300;
int speed2 = 200;
unsigned long t1 = 0;
unsigned long t2 = 0;

void setup() {
  // GPIO
  Serial.begin(115200);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  digitalWrite(led1_pin,led1); //0
  digitalWrite(led2_pin,led2); //0
}

void loop() { //HIGH = 1 LOW =0
  unsigned long t = millis();  //605
  if(t - t1 >= speed1){ //มีค่าเพิ่มขึ้นเรื่อยๆ 605 - 601 ==>4 >=600??
    t1 = t; // reset เวลา
    led1 = led1 == 0 ? 1 : 0; //toggle
    //digitalWrite(led1_pin, led1); 
    Serial.printf("LED1 =%d\n",led1);
    digitalWrite(led1_pin, digitalRead(led1_pin)==0 ? 1 :0);
     // led1 = (led1 + 1)%2;
    }
  if(t - t2 >= speed2){
    t2 = t; // reset เวลา
    led2 = led2 == 0 ? 1 :0; //toggle
    digitalWrite(led2_pin, led2); 
    Serial.printf("LED2 =%d\n",led2);
    Serial.printf("khukkhuk");
    }
}
