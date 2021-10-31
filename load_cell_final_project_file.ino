#include <HX711.h>

HX711 scale;
float calibration_factor =-7050.0;
#define DOUT  3   //constant value
#define CLK  2    //constant value



void setup() {
  Serial.begin(9600);
  Serial.println("HX711 scale demo");

  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); 
  scale.tare(); 
  Serial.println("Readings:");
}

void loop() {
  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1); //scale.get_units() returns a float
  Serial.print(" lbs"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.println();
  delay(1000);
}
