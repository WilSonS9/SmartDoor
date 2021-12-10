#include <ESP8266WiFi.h>
#include <PubSubClient.h>

int transistor = 2;

const char* ssid = "ABB_Gym_IOT";
const char* password = "Welcome2abb";
const char* mqttServer = "maqiatto.com";
const int mqttPort = 1883;
const char* mqttUser = "g3.vibestol@gmail.com";
const char* mqttPassword = "G3Vibestol2020";

String pay;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
    Serial.begin(115200);
    pinMode(12, INPUT_PULLUP);         //Set Pin6 as output
    pinMode(transistor, OUTPUT);
    
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the WiFi network");
    client.setServer(mqttServer, mqttPort);
    client.setCallback(callback);
    while (!client.connected()) {
      Serial.println("Connecting to MQTT...");
      if (client.connect("pubsubjoel", mqttUser, mqttPassword )) {
        Serial.println("connected");
      } 
      else {
        Serial.print("failed with state ");
        Serial.print(client.state());
        delay(2000);
    }
  }
  client.publish("g3.vibestol@gmail.com/joel", "Hello from ESP8266");
  client.subscribe("g3.vibestol@gmail.com/joel");
}
void loop() {
  client.loop();
  if (pay == "Joel")
  {
    int singal = digitalRead(12);
    Serial.println(singal);
    digitalWrite(transistor, HIGH);
  }
  else if (pay == "NJoel")
  {
    digitalWrite(transistor, LOW);
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  pay = "";
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
  pay += (char)payload[i];
  }
  Serial.println(pay);
  Serial.println();
  Serial.println("-----------------------");
}
