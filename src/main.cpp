#include <Arduino.h>
#include <TinyPICO.h>
#include <HardwareSerial.h>

#define RX_Serial_1 GPIO_NUM_21 // SDA, pin 21 -> connect to easyRadio pin 5
#define TX_Serial_1 GPIO_NUM_22 // SCL, pin 22 -> connect to easyRadio pin 6

TinyPICO tp = TinyPICO();

String command = "ER_CMD#T3";

void setup()
{
  Serial.begin(9600);
  HardwareSerial Serial1(1);
  Serial1.begin(19200, SERIAL_8N1, RX_Serial_1, TX_Serial_1);
}

void loop()
{
  tp.DotStar_CycleColor(25);
  Serial.println("Hello world");
  // get firmware revision
  Serial.print("sending command: ");
  Serial.println(command);
  Serial1.println(command);
  String result = Serial1.readString();
  Serial1.println("ACK");
  Serial.print("response: ");
  Serial.println(result);
  sleep(2);
}