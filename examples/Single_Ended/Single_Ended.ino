/*******************************************************
 * @file Single_Ended.ino
 *
 * @brief Example demonstrating single-ended analog readings
 *        using the 7Semi ADS7830 8-bit ADC module.
 *
 * This sketch reads analog voltages from all 8 input channels
 * (CH0 to CH7) in single-ended mode over I2C and converts the
 * values into voltages using the internal 2.5V reference.
 *
 * Key features demonstrated:
 * - Single-ended channel reads
 * - 8-bit ADC resolution (0–2.5V scale)
 *
 * Connections:
 * - VCC  -> 3.3V or 5V
 * - GND  -> GND
 * - SDA  -> A4 (Uno)
 * - SCL  -> A5 (Uno)
 *
 * @section author Author
 * Written by 7Semi
 *
 * @section license License
 * @license MIT
 * Copyright (c) 2025 7Semi
 *******************************************************/
 
 #include <7semi_ADS7830.h>

ADS7830_7semi adc;  // Create ADS7830 object

void setup() {
  Serial.begin(115200);
  Wire.begin();

  if (adc.begin()) {
    Serial.println("ADS7830 initialized");
  } else {
    Serial.println("ADS7830 not found!");
    while (1);
  }

  // Enable internal 2.5V reference voltage
  // Use DISABLE to use external voltage via VREF pin
  adc.intRef(ENABLE);
}

void loop() {
  // Array to hold readings from CH0 to CH7
  uint8_t values[8];

  // Read all 8 channels using loop
  for (uint8_t i = 0; i < 8; i++) {
    values[i] = adc.readSingleCh(i);
  }

  // Convert ADC reading (0–255) to voltage using scale factor
  float scale = 2.5 / 255.0;

  Serial.println("=== Single-Ended Readings (in Volts) ===");
  for (uint8_t i = 0; i < 8; i++) {
    Serial.print("CH");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(values[i] * scale, 3);  // Print 3 decimal places
  }
  Serial.println("========================================");
  Serial.println();

  delay(1000);
}
