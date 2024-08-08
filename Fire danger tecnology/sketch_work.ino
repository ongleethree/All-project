#include <DHT.h>
#define DHTPIN 4 
#define DHTTYPE DHT11 

int voc=2;
int reading;
int relay=19;
int buzzer_pin=18;
int red=16;
int green=17;
int yellow=5;

DHT dht(DHTPIN, DHTTYPE);


void setup() 
{

  Serial.begin(115200);
  //...............Test...............//
  Serial.println(F("DHTxx test!"));

  pinMode(relay,OUTPUT);
  pinMode(buzzer_pin,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  dht.begin();
}
// ...........Wifi setuup.............











// ...........Wifi setuup.............

void loop() 
{

  reading = analogRead(voc);
  Serial.println("gas=");
  Serial.println(voc);
  
  delay(2000);  

  // Reading temperature and humidity
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

   if(t>90&&h>=40)
   {
    Serial.print("Temperature HIGH");
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
    
    for (int i = 0; i < 3; i++) 
      {
        tone(buzzer_pin,26);
        delay(1000);
        tone(buzzer_pin,300);
        delay(1000);
        noTone(buzzer_pin);
      } 

    digitalWrite(relay,HIGH);
    Serial.print("Water ON");

   }

   else if (t>=50&&h<=30)
   {
    Serial.print("Temperature meduim");
    Serial.print("Water OFF");
    digitalWrite(red,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(green,LOW);
    tone(buzzer_pin,26);
    delay(1000);
    tone(buzzer_pin,300);
    delay(1000);
    noTone(buzzer_pin);
    digitalWrite(relay,LOW);
   }

   else
   {
    Serial.print("Temperature LOW");
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
    digitalWrite(relay,LOW);
    Serial.print("Water OFF");
   }


  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Celsius (the default)
  float heatIndex = dht.computeHeatIndex(t, h);
  // Compute heat index in Fahrenheit (isFahrenheit = true)
  float fHeatIndex = dht.computeHeatIndex(f, h, true);
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(heatIndex);
  Serial.print(F("°C "));
  Serial.print(fHeatIndex);
  Serial.println(F("°F"));
  read_sensor() ;

}
void read_sensor()
{
  if(voc>=50)
  {
   Serial.print("gas C02 HIGH");
   digitalWrite(relay,HIGH);
  }
  else if(voc>=40)
  {
    Serial.print("gas C02 Meduim");
    digitalWrite(relay,LOW);
  }
  else
  {
     Serial.print("gas C02 LOW");
     digitalWrite(relay,LOW);
  } 
}

