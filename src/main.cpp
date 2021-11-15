#include <Arduino.h>
#include <sample.h>
#define MICRO 1000000

const int sample_rate = 8000;
const int bit_depth = 8;

const float _delay = (1.0 / sample_rate) * MICRO; 

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (int i = 0; i < sizeof(Sample::audio_sample); i++){
    dacWrite(DAC1, Sample::audio_sample[i]);
    delayMicroseconds(_delay);
  }
}
