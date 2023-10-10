#include <Mouse.h>
#include <Keyboard.h>
#include <hiduniversal.h>
#include "hidmouserptparser.h"

USB Usb;
HIDUniversal Hid(&Usb);
HIDMouseReportParser Mou(nullptr);

bool on_left;
bool on_right;

void setup() {
  Mouse.begin();
  Serial.begin(128000);
  Serial.println("Start");
  Usb.Init();
  Hid.SetReportParser(0, &Mou);
}

void loop() {
  Usb.Task();
  //int chance = random(280);
  int chance = random(170);

switch (chance) {
  case 100:
    if (on_left) {
      Mouse.click(MOUSE_LEFT);
    }
  case 105:
      if (false) {
      Keyboard.write('s');
    }
    break;
  case 108:
      if (false) {
    Mouse.click(MOUSE_RIGHT);
    }
  case 109:
      if (false) {
    Mouse.click(MOUSE_RIGHT);
    }
}
  if (on_right) {
    Mouse.click(MOUSE_RIGHT);
    }
}

bool m_left(){
  Mouse.click(MOUSE_LEFT);
  on_left = true;
  return on_left;
}

bool m_right(){
  Mouse.click(MOUSE_RIGHT);
  on_right = true;
  return on_right;
}

void onButtonDown(uint16_t buttonId) {
  Mouse.press(buttonId);
  switch (buttonId) {
    case MOUSE_BUTTON5:
      m_left();
      break;
    case MOUSE_BUTTON4:
      m_right();
      break;
  }
}

void onButtonUp(uint16_t buttonId) {
  Mouse.release(buttonId);
  switch (buttonId) {
    case MOUSE_BUTTON5:
      on_left = false;
      break;
    case MOUSE_BUTTON4:
      on_right = false;
      break;
  }
}

void onTiltPress(int8_t tiltValue) {
  Serial.print("Tilt pressed: ");
  Serial.println(tiltValue);
}

void onMouseMove(int8_t xMovement, int8_t yMovement, int8_t scrollValue) {
  Mouse.move(xMovement, yMovement, scrollValue);
}
