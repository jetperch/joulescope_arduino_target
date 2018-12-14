/*
   Joulescope low-power demonstration Arduino Pro Mini target.
   (c) 2018 Jetperch LLC
   This code is released into the public domain code.
   Only AVR nano-power devices will be under 1 uA sleep current.
*/

#include <avr/sleep.h>
#define INTERRUPT_PIN (2)  // pin 2 connects to interrupt 0
#define BLINK_COUNT (10)
#define BLINK_ON_DURATION_MS   (100) // milliseconds
#define BLINK_OFF_DURATION_MS  (100) // milliseconds
#define TEST_WAIT_DURATION_MS  (100) // milliseconds
#define PULSE_WAIT_DURATION_MS (100) // milliseconds

void setup() {
  Serial.begin(115200);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Pin 2 connects to interrupt 0.
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);

  // disable ADC
  ADCSRA &= ~(1 << ADEN);
}

void sleep_enter() {
  attachInterrupt(0, wake_up, LOW);
  sleep_enable();
  cli();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_bod_disable();
  sei();
  sleep_cpu();
  sleep_disable();
  sei();
  detachInterrupt(0);
}

void wake_up() {
  // wakeup pin triggered!
}

void loop() {
  delay(TEST_WAIT_DURATION_MS);
  Serial.println("blink");
  for (int i = 0; i < BLINK_COUNT; ++i) {
    Serial.println("on");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(BLINK_ON_DURATION_MS);
    Serial.println("off");
    digitalWrite(LED_BUILTIN, LOW);
    delay(BLINK_OFF_DURATION_MS);
  }

  delay(TEST_WAIT_DURATION_MS);
  Serial.println("pulse");
  for (int i = 10; i > 0; --i) {
    int width = 1 << i;
    for (int j = 0; j < width; ++j) {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    digitalWrite(LED_BUILTIN, LOW);
    delay(PULSE_WAIT_DURATION_MS);
  }

  delay(TEST_WAIT_DURATION_MS);
  Serial.println("toggle");
  for (int i = 10; i > 0; --i) {
    int width = 1 << i;
    for (int j = 0; j < width; ++j) {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    for (int j = 0; j <= width; ++j) {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }


  delay(TEST_WAIT_DURATION_MS);
  Serial.println("min pulse");
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_BUILTIN, LOW);
  delay(TEST_WAIT_DURATION_MS);
  
  Serial.println("sleep");
  delay(TEST_WAIT_DURATION_MS);
  sleep_enter();
}

