#include <DHT.h>
#define DHTPIN 4 
#define DHTTYPE DHT11 
#include <WiFi.h>
#include <PubSubClient.h>

void read_sensor();
void sent_mqtt_data();
int voc=35;
int reading;
char msg[100];
int relay=19;
int buzzer_pin=18;
int red=16;
int green=17;
int yellow=5;

DHT dht(DHTPIN, DHTTYPE);

float t,h,f;

//...........Wifi setup................//
const char* myssid = "BANONGLEE_2.4G";
const char* mypassword = "WANVIM27";
//.............Mqtt......................//
const char* mqtt_server = "broker.netpie.io";
const int mqtt_port = 1883;
const char* mqtt_Client = "87d1f414-2bcc-48b9-beec-51ef807a0f25";
const char* mqtt_username = "enB4p8ZW2oqB5AKjfCNtDvi291mWt3s9";
const char* mqtt_password = "i7kUnuf2HMYuZTs9u7i7QHtzXLaRqDJE";

// ...anoucement the mqtt function...//
WiFiClient espClient;
PubSubClient client(espClient);

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

  //.....connect wifi.....//
  Serial.print("Connecting to "); 
  Serial.println(myssid);
  WiFi.begin(myssid, mypassword);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqtt_server, mqtt_port);//ให้ทำการสร้างพอร์ต mqtt
//.....connect wifi.....//
}

void reconnect() 
{
  while (!client.connected()) //! mean not
  {
    Serial.print("Sensor MQTT connection…");
    if (client.connect(mqtt_Client, mqtt_username,mqtt_password)) 
    {
      Serial.println("connected");
      client.subscribe("@msg/OUT1");
    }
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println("try again in 5 seconds");
      delay(5000);
    }
  }
}









void loop() 
{
  
  reading = analogRead(voc);
  Serial.println("gas=");
  Serial.println(reading);
  
  delay(2000);  

  // Reading temperature and humidity
   h = dht.readHumidity();
  // Read temperature as Celsius (the default)
   t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
   f = dht.readTemperature(true);

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
  sent_mqtt_data();
}
void read_sensor()
{
  if(reading>=1500)
  {
   Serial.print("gas C02 HIGH");
   digitalWrite(relay,HIGH);
  }
  else if(reading<=900)
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


void sent_mqtt_data()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  String data = "{\"data\": {\"Temperature\":" + String(t) +",\"Huminity\":" + String(h)+",\"gas_raw_ADC\":" + String(reading)+"}}";
  Serial.println(data);
  data.toCharArray(msg, (data.length() + 1));
  client.publish("@shadow/data/update", msg);
  delay(5000);
}
