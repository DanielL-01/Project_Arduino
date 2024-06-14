
int notes[] = { 
  440, 440, 440, 349, 523, 440, 349, 523, 440, 0, 659, 659, 659, 698, 523,
  415, 349, 523, 440
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.
int duration[] = {
  500, 500, 500, 350, 150, 500, 350, 150, 1000, 500, 500, 500, 350, 150,
  500, 350, 150, 1000, 500
};

int prev_state = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light_sensor = analogRead(A0);
  //Serial.println(light_sensor);
  
  if(light_sensor < 300){
    Serial.print(prev_state);
    digitalWrite(6, HIGH);
    if (prev_state == 0){
      tone(7, 1000);
      delay(1000);
      noTone(7);
      prev_state = 1;
      
    }
    else{
      noTone(7);
    }
  }
  else{
    digitalWrite(6, LOW);
    if (prev_state == 1 ){
      tone(7, 1000);
      delay(1000);
      noTone(7);
      prev_state = 0;
    }
    else {
      noTone(7);
    }
  }

  delay(3000);
}
