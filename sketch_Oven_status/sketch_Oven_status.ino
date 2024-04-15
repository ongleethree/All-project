#include <Wire.h>
#include <SPI.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
double Temp_ambient;
double Temp_object;
int Oven_status=0;   //0 is oven off,1 is oven on
void setup() {
  Serial.begin(9600);

  Serial.println("Adafruit MLX90614 test");  

  mlx.begin();  

  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
  display.clearDisplay(); // clears the screen and buffer
  display.drawPixel(127, 63, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(Oven_status);
  display.display();
}

void read_oven_status()
{
  Temp_ambient = mlx.readAmbientTempC();
  Temp_object = mlx.readObjectTempC();

  if(Temp_object>=50)
  {
    Oven_status=1;
    Serial.println("oven status ON");
  }
  if(Temp_object<=40)
  {
    Oven_status=0;
    Serial.println("oven status OFF");
  }
}

void loop() {
  read_oven_status();
  display.setCursor(10,10);
  display.print("Temp_t=");
  display.println(Temp_object , 2);
  display.setCursor(10,20);
  display.print("Ambient");
  display.println(Temp_ambient , 2);
  Serial.printf("Ambient=%.3f ",Temp_ambient); 
  Serial.printf("object=%.3f ",Temp_object );
  Serial.println();
  display.setCursor(10,30);
  display.println("By cecilia");
  display.display();
 
  delay(500);
}
