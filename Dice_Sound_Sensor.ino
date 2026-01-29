/************* PINI *************/
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int pinDP = 10; // Pinul pentru PUNCT

int buzzerPin = 9;  
int D3 = 11; // Zarul 1 (stânga)
int D4 = 12; // Zarul 2 (dreapta)
int soundPin = 13;

/************* VARIABILE JOC *************/
int valoareZar1 = 0;
int valoareZar2 = 0;
bool esteInAnimatie = false;

void setup() {
  pinMode(pinA, OUTPUT); pinMode(pinB, OUTPUT); pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT); pinMode(pinE, OUTPUT); pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT); // Setăm punctul ca ieșire

  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(soundPin, INPUT);

  randomSeed(analogRead(A0));
  
  valoareZar1 = 0;
  valoareZar2 = 0;
}

void loop() {
  if (digitalRead(soundPin) == HIGH && !esteInAnimatie) {
    lanseazaZarurile();
  }

  // AFIȘARE ZAR 1 (cu punct)
  afiseazaPeDigit(D3, valoareZar1, true); // true = punct aprins
  delay(5); 
  
  // AFIȘARE ZAR 2 (fără punct)
  afiseazaPeDigit(D4, valoareZar2, false); // false = punct stins
  delay(5);
}

void lanseazaZarurile() {
  esteInAnimatie = true;
  for (int i = 0; i < 15; i++) {
    valoareZar1 = random(1, 7);
    valoareZar2 = random(1, 7);
    digitalWrite(buzzerPin, HIGH);
    for(int j=0; j<5; j++) {
      afiseazaPeDigit(D3, valoareZar1, true); delay(5);
      afiseazaPeDigit(D4, valoareZar2, false); delay(5);
    }
    digitalWrite(buzzerPin, LOW);
  }
  valoareZar1 = random(1, 7);
  valoareZar2 = random(1, 7);
  tone(buzzerPin, 1000, 300);
  esteInAnimatie = false;
}

void afiseazaPeDigit(int digit, int numar, bool punct) {
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  
  afiseazaCifra(numar);
  
  // Controlul punctului: HIGH îl aprinde (la Catod Comun)
  if (punct) digitalWrite(pinDP, HIGH);
  else digitalWrite(pinDP, LOW);
  
  digitalWrite(digit, LOW);
}

void afiseazaCifra(int n) {
  switch (n) {
    case 0: afiseaza0(); break;
    case 1: afiseaza1(); break;
    case 2: afiseaza2(); break;
    case 3: afiseaza3(); break;
    case 4: afiseaza4(); break;
    case 5: afiseaza5(); break;
    case 6: afiseaza6(); break;
  }
}

/************* CIFRELE TALE *************/
void afiseaza0() {
  digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}
void afiseaza1() {
  digitalWrite(pinA, LOW); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
void afiseaza2() {
  digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}
void afiseaza3() {
  digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}
void afiseaza4() {
  digitalWrite(pinA, LOW); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
void afiseaza5() {
  digitalWrite(pinA, HIGH); digitalWrite(pinB, LOW); digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
void afiseaza6() {
  digitalWrite(pinA, HIGH); digitalWrite(pinB, LOW); digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}