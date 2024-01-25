/********************************************************
  Check Sippers
********************************************************/
void CheckSippers() {
  //If left sipper is triggered
  if ((qt_1.measure() - baseline1) > sensitivity) {
    Click();
    unsigned long start = millis();
    LeftCount++;
    digitalWrite(RED_LED, HIGH);
    delay(50);
    digitalWrite(RED_LED, LOW);
    Serial.print("Left: ");
    Serial.print(LeftCount);
    Serial.print("   Capacitance Reading: ");
    Serial.print(qt_1.measure() - baseline1);
    while ((qt_1.measure() - baseline1) > sensitivity) {
    }
    LeftDuration = millis() - start;
    RightDuration = 0;
    Serial.print("   Duration: ");
    Serial.println(LeftDuration);
    LogData();
  }

  //If right sipper is triggered
  if ((qt_2.measure() - baseline2) > sensitivity) {
    tubetrode.readRawSensors(sensorValues, true); // Convert to volts
    Click2();
    unsigned long start = millis();
    RightCount++;
    digitalWrite(GREEN_LED, HIGH);
    delay(50);
    digitalWrite(GREEN_LED, LOW);
    Serial.print("Right: ");
    Serial.print(RightCount);
    Serial.print("   Capacitance Reading: ");
    Serial.print(qt_2.measure() - baseline2);

    while ((qt_2.measure() - baseline2) > sensitivity) {
    }
    RightDuration = millis() - start;
    LeftDuration = 0;
    Serial.print("   Duration: ");
    Serial.println(RightDuration);
    Serial.println("***************");
    for (int i = 0; i < 8; i++)
    {
      Serial.print(sensorValues[i]);
      Serial.print("\t"); // Tab space for better readability
    }
    Serial.println();
    Serial.println("***************");
    LogData();
  }
}

void zerosensors () {
  baseline1 = qt_1.measure();
  baseline2 = qt_2.measure();
  resetsound();
}
