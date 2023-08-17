void GoToSleep() {
  USBDevice.detach();
  digitalWrite (A0, LOW);
  digitalWrite (13, LOW);
  LowPower.sleep(100);
  digitalWrite (13, HIGH);
  digitalWrite (A0, LOW);
  wakecounter ++;
  if ((wakecounter % 20) == 0) {
    zerosensors ();
  }
  USBDevice.attach();
}
