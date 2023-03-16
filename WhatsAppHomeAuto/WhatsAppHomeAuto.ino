#include <ESP8266WiFi.h>
#include <ThingESP.h>

ThingESP8266 thing("name", "HomeAutomation", "whatsAppControlled");

// int LED = D2;
  int LED1 = D6;  //  D6    12 pin 
  int LED2 = D2;  //  D2    14 pin 
  int LED3 = D1;   // D1    4 pin  
  int LED4 = D5;   // D5    5 pin 

unsigned long previousMillis = 0;
const long INTERVAL = 6000;  

void setup() 
{
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  thing.SetWiFi("wifi-name", "wifi-password");
  thing.initDevice();
}
String HandleResponse(String query)
{
  if (query == "on light 1") {
    digitalWrite(LED1, LOW);
    return "Light 1 is turned ON";
  }
  else if (query == "off light 1") {
    digitalWrite(LED1, HIGH);
    return "Light 1 is turned OFF";
  }
// Second
  else if (query == "on light 2") {
    digitalWrite(LED2, LOW);
    return "Light 2 is turned ON";
  }
  else if (query == "off light 2") {
    digitalWrite(LED2, HIGH);
    return "Light 2 is turned OFF";
  }
// Third
  else if (query == "on fan") {
    digitalWrite(LED3, LOW);
    return "Fan is turned ON";
  }
  else if (query == "off fan") {
    digitalWrite(LED3, HIGH);
    return "Fan is turned OFF";
  }
  // Fourth
   else if (query == "on charger") {
    digitalWrite(LED4, LOW);
    return "Charger is turned ON";
  }
  else if (query == "off charger") {
    digitalWrite(LED4, HIGH);
    return "Charger is turned OFF";
  }
  else if (query == "all on") {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    return "All devices turned ON";
  }
    else if (query == "all off") {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    return "All devices turned OFF";
  }
  
  else return "Invalid command";
}
void loop()
{
  thing.Handle();
}