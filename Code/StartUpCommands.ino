/********************************************************
  Start Up Commands
********************************************************/
void StartUpCommands () {
  Serial.begin(115200);

  /********************************************************
    Start FreeTouch
  ********************************************************/
  if (! qt_1.begin())
    Serial.println("Failed to begin qt on pin A1");

  if (! qt_2.begin())
    Serial.println("Failed to begin qt on pin A2");

  /********************************************************
    These commands are associated with the low power sleep states
  ********************************************************/
  //FILL THIS IN LATER


  /********************************************************
     Start RTC
   ********************************************************/
  rtc.begin(); // initialize RTC
  delay (5000);  // wait for device boot

  /********************************************************
    Setting digital pin modes
  ********************************************************/
  pinMode (LeftSip, INPUT_PULLDOWN);
  pinMode (RightSip, INPUT_PULLDOWN);
  pinMode (RED_LED, OUTPUT);
  pinMode (GREEN_LED, OUTPUT);
  pinMode (buzzer, OUTPUT);

  /********************************************************
     Attach interrupts to wake the sipper device from sleep
   ********************************************************/
  //FILL THIS IN LATER


  /********************************************************
    Turn LEDs off
  ********************************************************/
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  /********************************************************
    SD Card setup function
  ********************************************************/
  CreateFile();
  DateTime now = rtc.now();
  StartTime = now.unixtime() ;  //StartTime for the file
  writeHeader();

  //Zero touch sensors
  delay (1000);
  zerosensors();
}
