#include "HX711.h"
#define calibration_factor -400000
#define DOUT 3
#define CLK 2


HX711 scale = HX711();

void setup() {

  scale.begin(DOUT, CLK);
  Serial.begin(9600);
  Serial.println("HX711 scale TEST");
  scale.set_scale(calibration_factor);
  scale.tare();
  Serial.println("Readings:");
}
void loop() {
  Serial.print("weight:");
  Serial.print(scale.get_units(), 1);
  Serial.println("kg");
  Serial.println();
}