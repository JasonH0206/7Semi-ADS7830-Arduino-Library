/*******************************************************
 * @file Differential.ino
 *
 * @brief Example demonstrating differential analog readings
 *        using the 7Semi ADS7830 8-bit ADC module.
 *
 * This sketch reads voltage differences between adjacent
 * channels using internal differential mode and prints
 * scaled values (assuming 2.5V internal reference).
 *
 * Key features demonstrated:
 * - Differential pair reading (CH0–CH1, CH1–CH0, etc.)
 * - 8-bit resolution scaling with internal Vref
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
  // Read all 8 differential pairs
  uint8_t val_0_1 = adc.readDiffCh(DIFF_CH0_CH1);  // CH0 - CH1
  uint8_t val_2_3 = adc.readDiffCh(DIFF_CH2_CH3);  // CH2 - CH3
  uint8_t val_4_5 = adc.readDiffCh(DIFF_CH4_CH5);  // CH4 - CH5
  uint8_t val_6_7 = adc.readDiffCh(DIFF_CH6_CH7);  // CH6 - CH7
  uint8_t val_1_0 = adc.readDiffCh(DIFF_CH1_CH0);  // CH1 - CH0
  uint8_t val_3_2 = adc.readDiffCh(DIFF_CH3_CH2);  // CH3 - CH2
  uint8_t val_5_4 = adc.readDiffCh(DIFF_CH5_CH4);  // CH5 - CH4
  uint8_t val_7_6 = adc.readDiffCh(DIFF_CH7_CH6);  // CH7 - CH6

  // Convert to voltage (assuming internal 2.5V ref)
  float scale = 2.5 / 255.0;

  Serial.println("=== Differential Readings (in Volts) ===");
  Serial.print("CH0 - CH1: "); Serial.println(val_0_1 * scale, 3);
  Serial.print("CH2 - CH3: "); Serial.println(val_2_3 * scale, 3);
  Serial.print("CH4 - CH5: "); Serial.println(val_4_5 * scale, 3);
  Serial.print("CH6 - CH7: "); Serial.println(val_6_7 * scale, 3);
  Serial.print("CH1 - CH0: "); Serial.println(val_1_0 * scale, 3);
  Serial.print("CH3 - CH2: "); Serial.println(val_3_2 * scale, 3);
  Serial.print("CH5 - CH4: "); Serial.println(val_5_4 * scale, 3);
  Serial.print("CH7 - CH6: "); Serial.println(val_7_6 * scale, 3);
  Serial.println("========================================");
  Serial.println();

  delay(1000);
}
