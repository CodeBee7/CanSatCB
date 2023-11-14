// Basic demo for pressure readings from Adafruit LPS2X
#include <Wire.h>
#include <Adafruit_LPS2X.h>
#include <Adafruit_Sensor.h>

// For SPI mode, we need a CS pin
#define LPS_CS 10
// For software-SPI mode we need SCK/MOSI/MISO pins
#define LPS_SCK 13
#define LPS_MISO 12
#define LPS_MOSI 11

Adafruit_LPS25 lps;

void setup(void) {
  SerialUSB.begin(115200);
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  SerialUSB.println("Adafruit LPS25 test!");

  // Try to initialize!
  if (!lps.begin_I2C()) {
  //if (!lps.begin_SPI(LPS_CS)) {
  //if (!lps.begin_SPI(LPS_CS, LPS_SCK, LPS_MISO, LPS_MOSI)) {
    SerialUSB.println("Failed to find LPS25 chip");
    while (1) { delay(10); }
  }
  SerialUSB.println("LPS25 Found!");

//  lps.setDataRate(LPS25_RATE_12_5_HZ);
  SerialUSB.print("Data rate set to: ");
  switch (lps.getDataRate()) {
    case LPS25_RATE_ONE_SHOT: SerialUSB.println("One Shot"); break;
    case LPS25_RATE_1_HZ: SerialUSB.println("1 Hz"); break;
    case LPS25_RATE_7_HZ: SerialUSB.println("7 Hz"); break;
    case LPS25_RATE_12_5_HZ: SerialUSB.println("12.5 Hz"); break;
    case LPS25_RATE_25_HZ: SerialUSB.println("25 Hz"); break;

  }
}

void loop() {
  sensors_event_t temp;
  sensors_event_t pressure;
  lps.getEvent(&pressure, &temp);// get pressure
  SerialUSB.print("Temperature: ");SerialUSB.print(temp.temperature);SerialUSB.println(" degrees C");
  SerialUSB.print("Pressure: ");SerialUSB.print(pressure.pressure);SerialUSB.println(" hPa");
  SerialUSB.println("");
  delay(100);
}