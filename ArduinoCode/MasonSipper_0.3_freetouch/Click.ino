void Click() {
  tone (buzzer, 800, 8);
}

void Click2() {
  tone (buzzer, 2000, 8);
}

void resetsound() {
  tone (buzzer, 3000, 4);
  delay (100);
  tone (buzzer, 3000, 4);
  delay (100);
  tone (buzzer, 3000, 4);
  delay (100);
}
