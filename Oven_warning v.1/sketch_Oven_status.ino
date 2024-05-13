#include <Wire.h>
#include <SPI.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Ticker.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
int motion_pin=2;
int motion=0;
int Green=4;
int Red=15;
int Relay_pin=5;
int Buzzer_pin=16;
Ticker Read_sensor;
Ticker Display_RUNON;
double Temp_ambient;
double Temp_object;
int Oven_status=0;   //0 is oven off,1 is oven on
void setup() {
  Serial.begin(9600);

  Serial.println("Adafruit MLX90614 test");  
  pinMode(motion_pin,INPUT);
  pinMode(Relay_pin,OUTPUT);

  mlx.begin();  

  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
  display.clearDisplay(); // clears the screen and buffer
  display.drawPixel(127, 63, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(Oven_status);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Buzzer_pin, OUTPUT);
  Read_sensor.attach(1,read_oven_status);
  Display_RUNON.attach(1,Display_run);
  display.display();
}

void read_oven_status()
{
  motion = digitalRead(motion_pin);
  Serial.println(motion);
  Temp_ambient = mlx.readAmbientTempC();
  Temp_object = mlx.readObjectTempC();

  if(Temp_object>=50&&motion==1)
  {
    Oven_status=1;
    digitalWrite(Green,HIGH);
    digitalWrite(Red,LOW);
    Serial.println("oven status ON");
    Serial.println(motion);
    Serial.println("motion=ON");
    tone(Buzzer_pin,554);
    delay(1000);
    noTone(Buzzer_pin);
    Serial.println("Motion detect object");
  }
  else if(Temp_object>=55&&motion==0)
  {
    Oven_status=1;
    digitalWrite(Green,LOW);
    digitalWrite(Red,HIGH);
    Serial.println("oven status ON");
    Serial.println(motion);
    Serial.println("motion=OFF");
    Serial.println("Motion not detect object");
  }
  if(Temp_object<=30&&motion==1)
  {
    Oven_status=0;
    digitalWrite(Red,LOW);
    digitalWrite(Green,HIGH);
    Serial.println("Oven OFF");
    Serial.println(motion);
    Serial.println("motion=ON");
    Serial.println("Motion detect object");
    tone(Buzzer_pin,554);
    delay(1000);
    noTone(Buzzer_pin);

  }
  else
  {
    Oven_status=0;
    digitalWrite(Red,LOW);
    digitalWrite(Green,LOW);
    Serial.println("Oven LOW");
    Serial.println(motion);
    Serial.println("motion=LOW");
    Serial.println("Motion not detect object");
  }
}
void Cut_out()
{
  if(Temp_object>=50&&motion==1)
  {
    digitalWrite(Relay_pin,LOW);
    Serial.println("Relay=OFF");
  }
  else if(Temp_object>=55&&motion==0)
  {
    tone(Buzzer_pin,26);
    delay(1000);
    tone(Buzzer_pin,300);
    delay(1000);
    noTone(Buzzer_pin); 
    delay(50000);
    digitalWrite(Relay_pin,HIGH);
    Serial.println("Relay=ON");
    Serial.println("turn off power");
  }

  if(Temp_object<=30&&motion==0)
  {
    delay(300000);
    digitalWrite(Relay_pin,HIGH);
    Serial.println("Relay=ON");
  }
  else
  {
    Oven_status=0;
    digitalWrite(Red,LOW);
    digitalWrite(Green,LOW);
    Serial.println("Oven LOW");
    Serial.println(motion);
    Serial.println("motion=LOW");
    Serial.println("Motion not detect object");  
  }
}
void Display_run()
{
  display.setCursor(10,10);
  display.print("Temp_t=");
  display.println(Temp_object ,0);
  display.setCursor(10,20);
  display.print("Ambient=");
  display.println(Temp_ambient , 0);
  Serial.printf("Ambient=%.3f",Temp_ambient); 
  Serial.printf("object=%.3f",Temp_object );
  display.display();
 
}
void loop() 

{
  Cut_out();
}
