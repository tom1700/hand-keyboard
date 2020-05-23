#include <TinyUSB_Mouse_and_Keyboard.h>
#include <stdbool.h> 

struct Pin {
  /* Pin number on Arduino board */
  int NUMBER;
  bool isActive;
};

struct KeyStatuses {
  ctrl: false;
  shift: false; 
  alt: false;
  // command or windows 
  gui: false; 
  upArrow: false; 
  downArrow: false; 
  leftArrow: false; 
  rightArrow: false; 
  tab: false;
  enter: false;
  caps: false;
  esc: false;
  backspace: false; 
  space: false;
  E: false;
  T: false;
  A: false;
  O: false;
  I: false;
  N: false;
  S: false;
  R: false;
  H: false;
  D: false;
  L: false;
  U: false;
  C: false;
  M: false;
  F: false;
  Y: false;
  W: false;
  G: false;
  P: false;
  B: false;
  V: false;
  K: false;
  X: false;
  Q: false;
  Z: false;
  J: false;
  one: false;
  two: false;
  three: false;
  four: false;
  five: false;
  six: false;
  seven: false;
  eight: false;
  nine: false;
  zero: false;
  minus: false;
  equals: false;
  backQuote: false;
  openBracket: false;
  closeBracket: false;
  colon: false;
  singleQuote: false;
  backslash: false;
  comma: false;
  dot: false;
  forwardSlash: false;
  insert: false;
  delete: false;
  pageUp: false;
  pageeDown: false;
  home: false;
  end: false;
  f1: false;
  f2: false;
  f3: false;
  f4: false;
  f5: false;
  f6: false;
  f7: false;
  f8: false;
  f9: false;
  f10: false;
  f11: false;
  f12: false;
};

struct KeyStatuses keyStatuses;

// Negative inputs
struct Pin h1Input = { 2, false, false };
struct Pin h2Input = { 3, false, false };
struct Pin a1Input = { 4, false, false };
struct Pin a2Input = { 5, false, false };
struct Pin a3Input = { 6, false, false };
struct Pin a4Input = { 7, false, false };
struct Pin b1Input = { 8, false, false };
struct Pin b2Input = { 9, false, false };
struct Pin b3Input = { 10, false, false };
struct Pin b4Input = { 11, false, false };
struct Pin c1Input = { 12, false, false };
struct Pin c2Input = { 13, false, false };
struct Pin c3Input = { 14, false, false };
struct Pin c4Input = { 15, false, false };
// Positive inputs
struct Pin fOutput = { 16, false, false };
struct Pin a0Output = { 17, false, false };
struct Pin eOutput = { 18, false, false };
struct Pin gOutput = { 19, false, false };

void setup() {
  pinMode(h1Input.NUMBER, INPUT_PULLUP);
  pinMode(h2Input.NUMBER, INPUT_PULLUP);
  pinMode(a1Input.NUMBER, INPUT_PULLUP);
  pinMode(a2Input.NUMBER, INPUT_PULLUP);
  pinMode(a3Input.NUMBER, INPUT_PULLUP);
  pinMode(a4Input.NUMBER, INPUT_PULLUP);
  pinMode(b1Input.NUMBER, INPUT_PULLUP);
  pinMode(b2Input.NUMBER, INPUT_PULLUP);
  pinMode(b3Input.NUMBER, INPUT_PULLUP);
  pinMode(b4Input.NUMBER, INPUT_PULLUP);
  pinMode(c1Input.NUMBER, INPUT_PULLUP);
  pinMode(c2Input.NUMBER, INPUT_PULLUP);
  pinMode(c3Input.NUMBER, INPUT_PULLUP);
  pinMode(c4Input.NUMBER, INPUT_PULLUP);

  pinMode(fOutput.NUMBER, OUTPUT);
  pinMode(a0Output.NUMBER, OUTPUT);
  pinMode(eOutput.NUMBER, OUTPUT);
  pinMode(gOutput.NUMBER, OUTPUT);
}

bool isAnyTopFingerActive() {
  return (
    a1Input.isActive ||
    a2Input.isActive ||
    a3Input.isActive ||
    a4Input.isActive
  )
};

bool isAnyInputActive() {
  return (
    isAnyTopFingerActive() ||
    h1Input.isActive ||
    h2Input.isActive ||
    b1Input.isActive ||
    b2Input.isActive ||
    b3Input.isActive ||
    b4Input.isActive ||
    c1Input.isActive ||
    c2Input.isActive ||
    c3Input.isActive ||
    c4Input.isActive
  );
}

void updateInputsActivity() {
  h1Input.isActive = digitalRead(h1Input.NUMBER) == LOW ? true : false;
  h2Input.isActive = digitalRead(h2Input.NUMBER) == LOW ? true : false;
  a1Input.isActive = digitalRead(a1Input.NUMBER) == LOW ? true : false;
  a2Input.isActive = digitalRead(a2Input.NUMBER) == LOW ? true : false;
  a3Input.isActive = digitalRead(a3Input.NUMBER) == LOW ? true : false;
  a4Input.isActive = digitalRead(a4Input.NUMBER) == LOW ? true : false;
  b1Input.isActive = digitalRead(b1Input.NUMBER) == LOW ? true : false;
  b2Input.isActive = digitalRead(b2Input.NUMBER) == LOW ? true : false;
  b3Input.isActive = digitalRead(b3Input.NUMBER) == LOW ? true : false;
  b4Input.isActive = digitalRead(b4Input.NUMBER) == LOW ? true : false;
  c1Input.isActive = digitalRead(c1Input.NUMBER) == LOW ? true : false;
  c2Input.isActive = digitalRead(c2Input.NUMBER) == LOW ? true : false;
  c3Input.isActive = digitalRead(c3Input.NUMBER) == LOW ? true : false;
  c4Input.isActive = digitalRead(c4Input.NUMBER) == LOW ? true : false;
}

// This is temporary change caused by turning off the specific output
bool wasTemporarilyTurnedOff(struct Pin * pin) {
  return (pin->isActive && digitalRead(pin->NUMBER) === HIGH);
}

bool wasAnyTopFingerDeactivated() {
  return (
    wasTemporarilyTurnedOff(&a1Input) ||
    wasTemporarilyTurnedOff(&a2Input) ||
    wasTemporarilyTurnedOff(&a3Input) ||
    wasTemporarilyTurnedOff(&a4Input)
  );
}

bool wasAnyInputDeactivated() {
  return (
    wasAnyTopFingerDeactivated() ||
    wasTemporarilyTurnedOff(&h1Input) ||
    wasTemporarilyTurnedOff(&h2Input) ||
    wasTemporarilyTurnedOff(&b1Input) ||
    wasTemporarilyTurnedOff(&b2Input) ||
    wasTemporarilyTurnedOff(&b3Input) ||
    wasTemporarilyTurnedOff(&b4Input) ||
    wasTemporarilyTurnedOff(&c1Input) ||
    wasTemporarilyTurnedOff(&c2Input) ||
    wasTemporarilyTurnedOff(&c3Input) ||
    wasTemporarilyTurnedOff(&c4Input)
  )
}

bool isOutputActive(struct Pin * pin) {
  digitalWrite(pin.NUMBER, HIGH);
  delay(5);

  if (wasAnyInputDeactivated()) {
    digitalWrite(a0Output.NUMBER, LOW);
    delay(5);

    return true;
  }

  return false;
}

void updateOutputsActivity() {
  if (isAnyInputActive()) {
    /* a0 can be paired with a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4, h1, h2 */
    if (isOutputActive(a0Output)) {
      a0Output.isActive = true;    
    } else {
      a0Output.isActive = false;
    }

    if (isAnyTopFingerActive()) {
      /* f can be paired with a1, a2, a3, a4 */
      if (isOutputActive(fOutput)) {
        fOutput.isActive = true;    
      } else {
        fOutput.isActive = false;
      }
      /* g can be paired with a1, a2, a3, a4 */
      if (isOutputActive(gOutput)) {
        gOutput.isActive = true;    
      } else {
        gOutput.isActive = false;
      }
      /* e can be paired with a1, a2, a3, a4 */
      if (isOutputActive(eOutput)) {
        eOutput.isActive = true;    
      } else {
        eOutput.isActive = false;
      }
    } else {
      eOutput.isActive = false;
      fOutput.isActive = false;
      gOutput.isActive = false;
    }
  } else {
    a0Output.isActive = false;
  }
}

void updateKey(int keyCode, bool keyStatus, bool shouldBePressed) {
  if (!keyStatus && shouldBePressed) {
    Serial.println(keyCode);
    Keyboard.press(keyCode);
  } else if (keyStatus && !shouldBePressed) {
    Serial.println(keyCode);
    Keyboard.release(keyCode);
  }
}

void loop() {
  digitalWrite(fOutput.NUMBER, LOW);
  digitalWrite(a0Output.NUMBER, LOW);
  digitalWrite(eOutput.NUMBER, LOW);
  digitalWrite(gOutput.NUMBER, LOW);
  
  updateInputsActivity();
  updateOutputsActivity();

  bool _isAnyTopFingerActive = isAnyTopFingerActive();

  updateKey(KEY_LEFT_CTRL, keyStatuses.ctrl, a1Input.isActive && gOutput.isActive);
  updateKey(KEY_LEFT_SHIFT, keyStatuses.shift, a2Input.isActive && gOutput.isActive);
  updateKey(KEY_LEFT_ALT, keyStatuses.alt, a3Input.isActive && gOutput.isActive);
  updateKey(KEY_LEFT_GUI, keyStatuses.gui, a4Input.isActive && gOutput.isActive);
  updateKey(KEY_UP_ARROW, keyStatuses.upArrow, b1Input.isActive && a0Output.isActive);
  updateKey(KEY_DOWN_ARROW, keyStatuses.downArrow, b2Input.isActive && a0Output.isActive);
  updateKey(KEY_LEFT_ARROW, keyStatuses.leftArrow,b3Input.isActive && a0Output.isActive);
  updateKey(KEY_RIGHT_ARROW, keyStatuses.rightArrow, b4Input.isActive && a0Output.isActive);
  updateKey(KEY_TAB, keyStatuses.tab, c1Input.isActive && a0Output.isActive);
  updateKey(KEY_RETURN, keyStatuses.enter, c2Input.isActive && a0Output.isActive);
  updateKey(KEY_CAPS_LOCK, keyStatuses.caps, c3Input.isActive && a0Output.isActive);
  updateKey(KEY_ESC, keyStatuses.esc, c4Input.isActive && a0Output.isActive);
  updateKey(KEY_BACKSPACE, keyStatuses.backspace, h1Input.isActive && a0Output.isActive && !_isAnyTopFingerActive);
  updateKey(' ', keyStatuses.space, h2Input.isActive && a0Output.isActive && !_isAnyTopFingerActive);
  updateKey('e', keyStatuses.E, a0Output.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey('t', keyStatuses.T, a0Output.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey('a', keyStatuses.A, a0Output.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey('o', keyStatuses.O, a0Output.isActive && !a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey('i', keyStatuses.I, a0Output.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey('n', keyStatuses.N, a0Output.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey('s', keyStatuses.S, a0Output.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey('r', keyStatuses.R, a0Output.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey('h', keyStatuses.H, a0Output.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey('d', keyStatuses.D, a0Output.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey('l', keyStatuses.L, a0Output.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey('u', keyStatuses.U, a0Output.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey('c', keyStatuses.C, a0Output.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey('m', keyStatuses.M, a0Output.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey('f', keyStatuses.M, a0Output.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey('y', keyStatuses.F, !a0Output && eOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey('w', keyStatuses.Y, !a0Output && eOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey('g', keyStatuses.W, !a0Output && eOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey('p', keyStatuses.G, !a0Output && eOutput.isActive && !a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey('b', keyStatuses.P, !a0Output && eOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey('v', keyStatuses.B, !a0Output && eOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey('k', keyStatuses.V, !a0Output && eOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey('x', keyStatuses.K, !a0Output && eOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey('q', keyStatuses.X, !a0Output && eOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey('j', keyStatuses.Q, !a0Output && eOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey('z', keyStatuses.Z, !a0Output && eOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey('1', keyStatuses.one, !a0Output && eOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey('2', keyStatuses.two, !a0Output && eOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey('3', keyStatuses.three, !a0Output && eOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey('4', keyStatuses.four, !a0Output && eOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey('5', keyStatuses.five, !a0Output && fOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey('6', keyStatuses.six, !a0Output && fOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey('7', keyStatuses.seven, !a0Output && fOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey('8', keyStatuses.eight, !a0Output && fOutput.isActive && !a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey('9', keyStatuses.nine, !a0Output && fOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey('0', keyStatuses.zero, !a0Output && fOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey('-', keyStatuses.minus, !a0Output && fOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey('=', keyStatuses.equals, !a0Output && fOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey('`', keyStatuses.backQuote, !a0Output && fOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey('[', keyStatuses.openBracket, !a0Output && fOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey(']', keyStatuses.closeBracket, !a0Output && fOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey(';', keyStatuses.colon, !a0Output && fOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey('\'', keyStatuses.singleQuote, !a0Output && fOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey('\\', keyStatuses.backslash, !a0Output && fOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey(',', keyStatuses.comma, !a0Output && fOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey('.', keyStatuses.dot, h2Input.isActive && eOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey('/', keyStatuses.forwardSlash, h2Input.isActive && eOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey(KEY_INSERT, keyStatuses.insert, h2Input.isActive && eOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey(KEY_DELETE, keyStatuses.delete, h2Input.isActive && eOutput.isActive && !a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey(KEY_PAGE_U, keyStatuses.pageUp, h2Input.isActive && eOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey(KEY_PAGE_D, keyStatuses.pageeDown, h2Input.isActive && eOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey(KEY_HOME, keyStatuses.home, h2Input.isActive && eOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey(KEY_END , keyStatuses.end, h2Input.isActive && eOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey(KEY_F1, keyStatuses.f1, h2Input.isActive && eOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey(KEY_F2, keyStatuses.f2, h2Input.isActive && eOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey(KEY_F3, keyStatuses.f3, h2Input.isActive && eOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey(KEY_F4, keyStatuses.f4, h2Input.isActive && eOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey(KEY_F5, keyStatuses.f5, h2Input.isActive && eOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey(KEY_F6, keyStatuses.f6, h2Input.isActive && eOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey(KEY_F7, keyStatuses.f7, h2Input.isActive && eOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive);
  updateKey(KEY_F8, keyStatuses.f8, h1Input.isActive && eOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey(KEY_F9, keyStatuses.f9, h1Input.isActive && eOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  updateKey(KEY_F10, keyStatuses.f10, h1Input.isActive && eOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  updateKey(KEY_F11, keyStatuses.f11, h1Input.isActive && eOutput.isActive && !a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  updateKey(KEY_F12, keyStatuses.f12, h1Input.isActive && eOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  // unused
  // updateKey(,,h1Input.isActive && eOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive)
  // updateKey(,,h1Input.isActive && eOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && eOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive)
  // updateKey(,,h1Input.isActive && eOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && eOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && eOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive)
  // updateKey(,,h1Input.isActive && eOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && eOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && eOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && eOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive)
  // updateKey(,,h2Input.isActive && fOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  // updateKey(,,h2Input.isActive && fOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  // updateKey(,,h2Input.isActive && fOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  // updateKey(,,h2Input.isActive && fOutput.isActive && !a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  // updateKey(,,h2Input.isActive && fOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  // updateKey(,,h2Input.isActive && fOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive)
  // updateKey(,,h2Input.isActive && fOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive)
  // updateKey(,,h2Input.isActive && fOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive)
  // updateKey(,,h2Input.isActive && fOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive)
  // updateKey(,,h2Input.isActive && fOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive)
  // updateKey(,,h2Input.isActive && fOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive)
  // updateKey(,,h2Input.isActive && fOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive)
  // updateKey(,,h2Input.isActive && fOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive)
  // updateKey(,,h2Input.isActive && fOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive)
  // updateKey(,,h2Input.isActive && fOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && fOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  // updateKey(,,h1Input.isActive && fOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  // updateKey(,,h1Input.isActive && fOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive);
  // updateKey(,,h1Input.isActive && fOutput.isActive && !a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive);
  // updateKey(,,h1Input.isActive && fOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && !a4Input.isActive);
  // updateKey(,,h1Input.isActive && fOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive)
  // updateKey(,,h1Input.isActive && fOutput.isActive && !a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && fOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && !a4Input.isActive)
  // updateKey(,,h1Input.isActive && fOutput.isActive && !a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && fOutput.isActive && a1Input.isActive && !a2Input.isActive && !a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && fOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && !a4Input.isActive)
  // updateKey(,,h1Input.isActive && fOutput.isActive && !a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && fOutput.isActive && a1Input.isActive && a2Input.isActive && !a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && fOutput.isActive && a1Input.isActive && !a2Input.isActive && a3Input.isActive && a4Input.isActive)
  // updateKey(,,h1Input.isActive && fOutput.isActive && a1Input.isActive && a2Input.isActive && a3Input.isActive && a4Input.isActive)
  delay(10);
}
