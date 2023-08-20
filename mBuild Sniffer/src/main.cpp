#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("---------------------------------------");
  Serial.println("[LOG] -> Welcome to mBuild Sniffer V1.0");
  Serial.println("[LOG] -> Written by Yanavut Rojanapron");

  Serial.println("[LOG] -> Configuring Serial Interfaces..");

  Serial1.setRX(1);
  Serial1.setTX(0);
  Serial1.begin(19200);

  Serial2.setRX(5);
  Serial2.setTX(4);
  Serial2.begin(19200);

  Serial.println("[LOG] -> Done!");
  Serial.println("[LOG] -> Entering Loop");
}

void loop()
{
  // if (Serial.available() > 0) {

  //   // say what you got:
  //   Serial.print("[SNIFF S0 (TERM)] -> ");
  //   Serial.println(Serial.read(), DEC);
  // }
  if (Serial1.available() > 0)
  {
    int content = Serial1.read();
    if (content == 255)
    {
      Serial.print("[SNIFF S1 (MASTER)] -> HOST BOOT");
    }
    else
    {
      // say what you got:
      Serial.print("[SNIFF S1 (MASTER)] ");
      Serial.print(Serial1.available());
      Serial.print(" -> ");
      Serial.println(content, DEC);
    }
  }

  if (Serial2.available() > 0)
  {

    // say what you got:
    Serial.print("[SNIFF S2 (SLAVE)] -> ");
    Serial.println(Serial2.read(), DEC);
  }
}