uint8_t command = 0;
float val1;
float val2;

uint8_t coilPin1 = 3;
uint8_t coilPin2 = 4;
uint8_t directionPin1 = 5;
uint8_t directionPin2 = 6;

uint32_t PWMfrew = 125e6; // max pwm clock 125MHz
uint32_t freq = 100e3; // Hz
uint32_t range = floor(PWMfrew/freq);

int32_t myRound(float val){
  if (val>=0){
    return val + .5;
  }
  else{
    return val - .5;
  }
}

void setup() {

  Serial.begin();
  pinMode(0, OUTPUT);  // sets the pin as output
  pinMode(1, OUTPUT);  // sets the pin as output
  pinMode(2, OUTPUT);  // sets the pin as output
  digitalWrite(0, 0);
  digitalWrite(1, 0);
  digitalWrite(2, 0);

  pinMode(coilPin1, OUTPUT);  // sets the pin as output
  pinMode(coilPin2, OUTPUT);  // sets the pin as output
  pinMode(directionPin1, OUTPUT);  // sets the pin as output
  pinMode(directionPin2, OUTPUT);  // sets the pin as output

  analogWriteFreq(freq);
  analogWriteRange(range);
  analogWrite(coilPin1, 0);
  digitalWrite(directionPin1, LOW);
  analogWrite(coilPin2, 0);
  digitalWrite(directionPin2, HIGH);

}

void loop() {
    if(Serial.available()>0){
    String input_str = Serial.readStringUntil('\n');
    int num_par = input_str.toInt();
        
    for (int i=0; i<num_par; i++){
      String input_str = Serial.readStringUntil('\n');
      if (i == 0){
        command = input_str.toInt();
      }
      if (i == 1){
        val1 = input_str.toFloat();
      }
      if (i == 2){
        val2 = input_str.toFloat();
      }
    }
    // SET REFERENCE POSITION
    if (command == 1){
      if(val1>1){val1 = 1.;}
      if(val2>1){val2 = 1.;}
      if(val1<-1){val1 = -1.;}
      if(val2<-1){val2 = -1.;}

      bool dir1 = val1<0; // 0 forward - 1 reverse
      bool dir2 = val2<0; // 0 forward - 1 reverse

      uint16_t I1 = abs(myRound(val1*range));
      uint16_t I2 = abs(myRound(val2*range));
      
      // analogWriteFreq(freq);
      // analogWriteRange(range);
      analogWrite(coilPin1, I1);
      digitalWrite(directionPin1, dir1);

      // analogWriteFreq(freq);
      // analogWriteRange(range);
      analogWrite(coilPin2, I2);
      digitalWrite(directionPin2, dir2);
    }
  }
}
