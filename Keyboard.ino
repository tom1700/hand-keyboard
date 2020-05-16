#define ACTIVE 1
#define INACTIVE 0

const int H1_INPUT = 2;
const int H2_INPUT = 3;
const int A1_INPUT = 4;
const int A2_INPUT = 5;
const int A3_INPUT = 6;
const int A4_INPUT = 7;

const int F_OUTPUT = 8;
const int A0_OUTPUT = 9;

int a1State = HIGH;
int a2State = HIGH;
int a3State = HIGH;
int a4State = HIGH;
int h1State = HIGH;
int h2State = HIGH;

int a0State = LOW;
int fState = LOW;

struct KeysStatuses {
  int a1 = INACTIVE;
  int a2 = INACTIVE;
  int a3 = INACTIVE;
  int a4 = INACTIVE;
  int h1 = INACTIVE;
  int h2 = INACTIVE;
  int a0 = INACTIVE;
  int f = INACTIVE;
};

struct KeysStatuses keysStatuses;

void setup() {
  Serial.begin(9600);
  pinMode(H1_INPUT, INPUT_PULLUP);
  pinMode(H2_INPUT, INPUT_PULLUP);
  pinMode(A1_INPUT, INPUT_PULLUP);
  pinMode(A2_INPUT, INPUT_PULLUP);
  pinMode(A3_INPUT, INPUT_PULLUP);
  pinMode(A4_INPUT, INPUT_PULLUP);

  pinMode(A0_OUTPUT, OUTPUT);
  pinMode(F_OUTPUT, OUTPUT);
//  Keyboard.begin();
}

bool isAnyActive() {
  return (
    a1State == LOW ||
    a2State == LOW ||
    a3State == LOW ||
    a4State == LOW ||
    h1State == LOW ||
    h2State == LOW
  );
}

void updateInputs() {
  a1State = digitalRead(A1_INPUT);
  a2State = digitalRead(A2_INPUT);
  a3State = digitalRead(A3_INPUT);
  a4State = digitalRead(A4_INPUT);
  h1State = digitalRead(H1_INPUT);
  h2State = digitalRead(H2_INPUT);
}

void loop() {  
  digitalWrite(A0_OUTPUT, LOW);
  digitalWrite(F_OUTPUT, LOW);
  
  updateInputs();
  
  if (isAnyActive() && keysStatuses.a0 == INACTIVE) {
     digitalWrite(A0_OUTPUT, HIGH);
     delay(10);
     updateInputs();

     if (!isAnyActive()) {
       digitalWrite(A0_OUTPUT, LOW);
       keysStatuses.a0 = ACTIVE;
       delay(10);
       updateInputs();
     } else {
       keysStatuses.a0 = INACTIVE;
     }
  } else if (!isAnyActive()) {
    keysStatuses.a0 = INACTIVE;
  }

  if (isAnyActive() && keysStatuses.f == INACTIVE) {   
    digitalWrite(F_OUTPUT, HIGH);
    delay(10);
    updateInputs();
    
    if (!isAnyActive()) {
      digitalWrite(F_OUTPUT, LOW);
      keysStatuses.f = ACTIVE;
      delay(10);
      updateInputs();
    } else {
      keysStatuses.f = INACTIVE;
    }
  } else if (!isAnyActive()) {
    keysStatuses.f = INACTIVE;
  }
  
  if (a1State == LOW && keysStatuses.a1 == INACTIVE) {
    keysStatuses.a1 = ACTIVE;
  } else if (a1State == HIGH && keysStatuses.a1 == ACTIVE) {
    keysStatuses.a1 = INACTIVE;
  }
  if (a2State == LOW && keysStatuses.a2 == INACTIVE) {
    keysStatuses.a2 = ACTIVE;
  } else if (a2State == HIGH && keysStatuses.a2 == ACTIVE) {
    keysStatuses.a2 = INACTIVE;
  }
  if (a3State == LOW && keysStatuses.a3 == INACTIVE) {
    keysStatuses.a3 = ACTIVE;
  } else if (a3State == HIGH && keysStatuses.a3 == ACTIVE) {
    keysStatuses.a3 = INACTIVE;
  }
  if (a4State == LOW && keysStatuses.a4 == INACTIVE) {
    keysStatuses.a4 = ACTIVE;
  } else if (a4State == HIGH && keysStatuses.a4 == ACTIVE) {
    keysStatuses.a4 = INACTIVE;
  }
    if (h1State == LOW && keysStatuses.h1 == INACTIVE) {
    keysStatuses.h1 = ACTIVE;
  } else if (h1State == HIGH && keysStatuses.h1 == ACTIVE) {
    keysStatuses.h1 = INACTIVE;
  }
  if (h2State == LOW && keysStatuses.h2 == INACTIVE) {
    keysStatuses.h2 = ACTIVE;
  } else if (h2State == HIGH && keysStatuses.h2 == ACTIVE) {
    keysStatuses.h2 = INACTIVE;
  }

  if (keysStatuses.a0 == ACTIVE) {
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('e'); }
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('t'); }
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('a'); }
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('o'); }
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('i'); }
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('n'); }
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('s'); }
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('r'); }
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('h'); }
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('d'); }
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('l'); }
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('u'); }
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('c'); }
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('m'); } 
  } else if (keysStatuses.f == ACTIVE) {
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('f'); } 
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('y'); } 
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('w'); } 
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('g'); } 
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('p'); }
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('b'); }
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('v'); }
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('k'); }
    if (keysStatuses.a1 == INACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('x'); }
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == INACTIVE) { Serial.print('q'); }
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == ACTIVE && keysStatuses.a3 == INACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('z'); }
    if (keysStatuses.a1 == ACTIVE && keysStatuses.a2 == INACTIVE && keysStatuses.a3 == ACTIVE && keysStatuses.a4 == ACTIVE) { Serial.print('j'); }
  }
   delay(200);
}
