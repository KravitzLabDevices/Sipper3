void LogData() {
  Serial.println("Logging data");
  ReadBatteryLevel();  //Read battery level
  WriteToSD();
  logfile.flush();
  digitalWrite(RED_LED, HIGH);  //blink while logging
  delay(25);
  digitalWrite(RED_LED, LOW);  //blink while logging
}

void LogData_test() {
  Serial.println("Logging data");
  ReadBatteryLevel();  //Read battery level
  WriteToSD_test();
  logfile.flush();
  digitalWrite(RED_LED, HIGH);  //blink while logging
  delay(25);
  digitalWrite(RED_LED, LOW);  //blink while logging
}

// Create new file on uSD incrementing file name as required
void CreateFile() {
  Serial.println("Starting up....");

  //put this next line *Right Before* any file open line:
  SdFile::dateTimeCallback(dateTime);

  // see if the card is present and can be initialized:
  if (!SD.begin(cardSelect, SPI_HALF_SPEED)) {
    Serial.println("Card not found");
  }

  // Name filename in format MAS###_MMDDYY_NN, where MM is month, DD is day, YY is year, and NN is an incrementing number for the number of files initialized each day
  strcpy(filename, "MAS_____________.CSV");  // placeholder filename
  getFilename(filename);
  Serial.print("Filename: ");
  Serial.println(filename);

  //See if we can open the file
  logfile = SD.open(filename, FILE_WRITE);
  if (!logfile) {
    Serial.println("Could not open log file on SD card.  ***NOT LOGGING DATA***");
  }
}

// Write data header to file of uSD.
void writeHeader() {
  logfile.println("MM:DD:YYYY hh:mm:ss,ElapsedSecs,Device,LeftCount,RightCount,LeftDuration(ms),RightDuration(ms),Temperature(C),BatteryVoltage(V),Mag1,Mag2,Mag3,Mag4,Mag5,Mag6,Mag7,Mag8");
  ReadBatteryLevel();
  WriteToSD();  //Write one line of zeros to logfile to note start of session
  Serial.println("Ready to go!");
}

void writeHeader_test() {
  logfile.println("MM:DD:YYYY hh:mm:ss,ElapsedSecs,Device,LeftCap,RightCap,Temperature(C),BatteryVoltage(V)");
  ReadBatteryLevel();
  WriteToSD_test();  //Write one line of zeros to logfile to note start of session
  Serial.println("Ready to go!");
}

// Write data to SD
void WriteToSD() {
  DateTime now = rtc.now();
  logfile.print(now.month());
  logfile.print("/");
  logfile.print(now.day());
  logfile.print("/");
  logfile.print(now.year());
  logfile.print(" ");
  logfile.print(now.hour());
  logfile.print(":");
  if (now.minute() < 10) {
    logfile.print('0');  // Trick to add leading zero for formatting
  }

  logfile.print(":");
  if (now.second() < 10) {
    logfile.print('0');  // Trick to add leading zero for formatting
  }
  logfile.print(now.second());
  logfile.print(",");
  logfile.print(now.unixtime() - StartTime);  //elapsed time
  logfile.print(",");
  logfile.print(Sip);  // Print device name
  logfile.print(",");
  logfile.print(LeftCount);
  logfile.print(",");
  logfile.print(RightCount);
  logfile.print(",");
  if (LeftDuration > 0) {
    logfile.print(LeftDuration);
  }
  else {
    logfile.print("-");
  }
  logfile.print(",");
  if (RightDuration > 0) {
    logfile.print(RightDuration);
  }
  else {
    logfile.print("-");
  }
  logfile.print(",");

  logfile.print(rtc.getTemperature());
  logfile.print(",");
  logfile.print(measuredvbat);  // Print battery voltage
  logfile.print(",");

  //Print Tubetrode sensor data
  for (int i = 0; i < 8; i++)
  {
    logfile.print(sensorValues[i]);
    logfile.print(",");
  }
  
  //go to next line
  logfile.println();
}

// Write data to SD
void WriteToSD_test() {
  DateTime now = rtc.now();
  logfile.print(now.month());
  logfile.print("/");
  logfile.print(now.day());
  logfile.print("/");
  logfile.print(now.year());
  logfile.print(" ");
  logfile.print(now.hour());
  logfile.print(":");
  if (now.minute() < 10) {
    logfile.print('0');  // Trick to add leading zero for formatting
  }
  logfile.print(now.minute());
  logfile.print(":");
  if (now.second() < 10) {
    logfile.print('0');  // Trick to add leading zero for formatting
  }
  logfile.print(now.second());
  logfile.print(",");
  logfile.print(now.unixtime() - StartTime);  //elapsed time
  logfile.print(",");
  logfile.print(Sip);  // Print device name
  logfile.print(",");
  logfile.print(qt_1.measure() - baseline1);
  logfile.print(",");
  logfile.print(qt_2.measure() - baseline2);
  logfile.print(",");
  logfile.print(rtc.getTemperature());
  logfile.print(",");
  logfile.println(measuredvbat);  // Print battery voltage
}

void getFilename(char *filename) {
  DateTime now = rtc.now();
  filename[3] = (Sip / 100) % 10 + '0';
  filename[4] = (Sip / 10) % 10 + '0';
  filename[5] = Sip % 10 + '0';
  filename[7] = now.month() / 10 + '0';
  filename[8] = now.month() % 10 + '0';
  filename[9] = now.day() / 10 + '0';
  filename[10] = now.day() % 10 + '0';
  // filename[11] = now.year() / 10 + '0'; //comments this out because I was getting weird characters here
  filename[11] = '2';  //hardcode this, should be good for 7 years :)
  filename[12] = now.year() % 10 + '0';
  filename[16] = '.';
  filename[17] = 'C';
  filename[18] = 'S';
  filename[19] = 'V';
  for (uint8_t i = 0; i < 100; i++) {
    filename[14] = '0' + i / 10;
    filename[15] = '0' + i % 10;
    // create if does not exist, do not open existing, write, sync after write
    if (!SD.exists(filename)) {
      break;
    }
  }
  return;
}
