void Click() {
  tone (buzzer, 1600, 2);
}

void Click2() {
  tone (buzzer, 800, 2);
}

void resetsound() {
  tone (buzzer, 3000, 4);
  delay (100);
  tone (buzzer, 3000, 4);
  delay (100);
  tone (buzzer, 3000, 4);
  delay (100);
}
