#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
int a=0;
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.write("Device Ready!");
}

void loop() {
  
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
   a=SerialBT.read();
   Serial.write(a);
   if(a=='1')
   Serial.write("\nMask detected --> Door unlocked\n");
   else
   Serial.write("Mask not detected --> Door locked\n");
   
  } 
  delay(1000);
}
