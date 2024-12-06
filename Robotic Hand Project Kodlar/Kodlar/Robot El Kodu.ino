#include <Servo.h>

// Servo motor nesneleri
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  // Servo motorların bağlı olduğu analog pinleri tanımlama
  servo1.attach(A1);
  servo2.attach(A2);
  servo3.attach(A3);
  servo4.attach(A4);
  servo5.attach(A5);

  // Başlangıçta tüm servoları 0 dereceye ayarla
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
  servo5.write(0);
}

void loop() {
  // 1. Servo hareketleri
  servo1.write(90);
  delay(2000);

  // 2. Servo hareketleri
  servo2.write(90);
  delay(2000);

  // 3. Servo hareketleri
  servo3.write(0);
  delay(2000);

  // 4. Servo hareketleri
  servo4.write(90);
  delay(2000);

  // 5. Servo hareketleri
  servo5.write(90);
  delay(2000);

  // 5. Servo geri dönüş
  servo5.write(0);
  delay(2000);

  // 4. Servo geri dönüş
  servo4.write(0);
  delay(2000);

  // 3. Servo geri dönüş
  servo3.write(90);
  delay(2000);

  // 2. Servo geri dönüş
  servo2.write(0);
  delay(2000);

  // 1. Servo geri dönüş
  servo1.write(0);
  delay(2000);

  // Tüm servolar 90 dereceye
  delay(2000);
  servo1.write(90);
  servo2.write(90);
  servo3.write(0);
  servo4.write(90);
  servo5.write(90);

  // Tüm servolar 0 dereceye
  delay(2000);
  servo1.write(0);
  servo2.write(0);
  servo3.write(90);
  servo4.write(0);
  servo5.write(0);

  // Başlangıç pozisyonuna dönüş
  delay(2000);
}
