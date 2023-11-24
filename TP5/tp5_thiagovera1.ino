int buzzerPin = 9;

int melody[] = {
  587, 587, 659, 587, 784, 698,
  587, 587, 659, 587, 880, 784,
  587, 587, 622, 932, 784, 698, 659,
  587, 587, 659, 587, 784, 698,
  587, 587, 659, 587, 880, 784,
};

int duracion[] = {
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2,
};

int notas = sizeof(melody) / sizeof(melody[0]);

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < notas; i++) {
    int duracionNota = 1000 / duracion[i];
    tone(buzzerPin, melody[i], duracionNota);
    delay(duracionNota * 1.3);
    noTone(buzzerPin);
  }

  delay(2000);
}
