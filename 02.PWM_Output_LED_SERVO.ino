#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "NNu3Ic4pAQtOgqlQsxmHQp_TrC93KBj2";
char ssid[] = "mecha";
char pass[] = "mechatronic";
int LED1 = D7;
Servo myservo;
int servopin = D5;

// From blynk --> To hardware (NodeMCU)
// Virtual Pin
BLYNK_WRITE(V0){ 
  int value = param.asInt(); // Get value as integer
  Serial.println(value);
  analogWrite(LED1,value); // Write PWM value to LED1 pin
}

// From blynk --> To hardware (NodeMCU)
BLYNK_WRITE(V1){
  int value = param.asInt(); // Get value as integer
  Serial.println(value);
  myservo.write(value);
}
void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(servopin, OUTPUT);
  myservo.attach(servopin);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
}

void loop()
{
  Blynk.run();
}
