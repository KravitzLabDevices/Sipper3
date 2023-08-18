void GoToSleep() {
  //USBDevice.detach();
  digitalWrite (A0, LOW);
  digitalWrite (13, LOW);
  //LowPower.sleep(10);
  delay (50);
  digitalWrite (13, HIGH);
  digitalWrite (A0, LOW);
  wakecounter ++;
  
  if ((wakecounter % 500) == 0) {
    Adafruit_FreeTouch qt_1 = Adafruit_FreeTouch(A1, OVERSAMPLE_64, RESISTOR_100K, FREQ_MODE_NONE);
    Adafruit_FreeTouch qt_2 = Adafruit_FreeTouch(A2, OVERSAMPLE_64, RESISTOR_100K, FREQ_MODE_NONE);
    zerosensors ();
  }
  
//  USBDevice.attach();
}
