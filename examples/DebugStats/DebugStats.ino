//
// Debug tool sample
// 2017 F.Cerbelle
//

// Configuration
#define DEBUG
#define PROF
#define STATS
//#define STATS_MEM
#define STATS_HOOK digitalWrite(LED_BUILTIN,((digitalRead(LED_BUILTIN)==HIGH)?LOW:HIGH))
#define STATS_PERIOD 1000

#include "fcdebug.h"

unsigned long lastTime = 0;
unsigned long firstTime = 0;

/********/
/* Main */
/********/
void setup() {
  Serial.begin(115200);
  while (!Serial);
  DEBUG_PRINTLN("Serial initialized.");

  DEBUG_PRINT("Initializing LED...");
  pinMode(LED_BUILTIN, OUTPUT);
  DEBUG_PRINTLN("OK");

  firstTime = millis();
}

void loop() {
  STATS_LOOP

  PROF_START(MyLoop);
  if ((millis() - lastTime) > 1000) {
    PROF_START(Point);
    Serial.print(".")
    PROF_STOP(Point);
    lastTime = millis();
  }
  PROF_STOP(MyLoop);

  if ((millis() - firstTime) > 10000) {
    DEBUG_STOP;
  }
}
