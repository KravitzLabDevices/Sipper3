/********************************************************
  Check Sippers
********************************************************/
void CheckSippers() {
  //If left sipper is triggered
  if ((qt_1.measure() - baseline1) > 50) {
    Click();
    unsigned long start = millis();
    LeftCount++;
    digitalWrite(RED_LED, HIGH);
    delay(50);
    digitalWrite(RED_LED, LOW);
    Serial.print("Left: ");
    Serial.print(LeftCount);
    while ((qt_1.measure() - baseline1) > 50) {
    }
    LeftDuration = millis() - start;
    RightDuration = 0;
    Serial.print("   Duration: ");
    Serial.println(LeftDuration);
    LogData();
  }

  //If right sipper is triggered
  if ((qt_2.measure() - baseline2) > 50) {
    Click2();
    unsigned long start = millis();
    RightCount++;
    digitalWrite(GREEN_LED, HIGH);
    delay(50);
    digitalWrite(GREEN_LED, LOW);
    Serial.print("Right: ");
    Serial.print(RightCount);
    while ((qt_2.measure() - baseline2) > 50) {
    }
    RightDuration = millis() - start;
    LeftDuration = 0;
    Serial.print("   Duration: ");
    Serial.println(RightDuration);
    LogData();
  }
}

void zerosensors () {
  baseline1 = qt_1.measure();
  baseline2 = qt_2.measure();
  resetsound();
}
