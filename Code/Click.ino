void Click() {
  tone (buzzer, 1600, 20);
}

void Click2() {
  tone (buzzer, 800, 20);
}

void resetsound() {
  tone (buzzer, 3000, 4);
  delay (100);
  tone (buzzer, 3000, 4);
  delay (100);
  tone (buzzer, 3000, 4);
  delay (100);
}
