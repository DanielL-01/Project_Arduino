#include <LiquidCrystal_I2C.h>


int seconds = 25;
int button_pin = 7;
int buz_pin = 6;
bool buz_state = false;


LiquidCrystal_I2C lcd(0x27,  16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(buz_pin, OUTPUT);
  pinMode(button_pin, INPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press Button to start");
  lcd.setCursor(0,1);
  lcd.print("Timer: " + String(seconds));  
  if (digitalRead(button_pin) == 1){
    seconds = 25;
    while (seconds > 0){
      seconds --;
      Serial.println(seconds);
      
      lcd.setCursor(0,0);
      lcd.clear();
      print_time(seconds);
      delay(1000);
    }
    if (seconds == 0){
      while(digitalRead(button_pin) == 0){
      tone(buz_pin, 1000);
      delay(1000);
      noTone(buz_pin);
      }
      noTone(buz_pin);
      
    }

  }
    delay(1000);
}

void print_time(int a){
  int seconds = a;
  int minutes;
  int hours;
  if (seconds/60 > 0){
    minutes = seconds / 60;
    seconds = seconds - minutes*60;
    if (minutes/60 > 0){
      hours = minutes/60;
      minutes = minutes - hours*60;
      lcd.print(String(hours)+"H"+String(minutes)+"M"+String(seconds)+"S");
    }
    else{
      lcd.print(String(minutes)+"M"+String(seconds)+"S");
    }
  }
  else{
    lcd.print(String(seconds)+"S");
  }
}