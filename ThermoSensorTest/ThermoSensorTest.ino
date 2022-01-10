#include <Wire.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  mlx.begin();
}

void loop() {
  Serial.print("Object: ");
  Serial.println(mlx.readObjectTempC());
  delay(500);

}
