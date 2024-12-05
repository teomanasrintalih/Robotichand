// Esnek sensörün bağlı olduğu pin numarası
const int flexPin = A4;

void setup() {
  // Seri haberleşmeyi başlat
  Serial.begin(9600);
}

// Elastik sensör değerini açıya dönüştürmek için fonksiyon
float mapFlexToAngle(int flexValue) {
  // Sensör değeri 0 ile 1023 arasında değişir
  // Bu örnekte, 0 bükülmemiş, 1023 tamamen bükülmüş kabul edilir.
  // Ancak gerçek değerler sensörün özelliklerine bağlı olacaktır.
  return map(flexValue, 0, 1023, 0, 90); // 0-1023 arasındaki değeri 0-90 dereceye dönüştürür.
}

void loop() {
  // Esnek sensörden gelen değeri oku
  int flexValue = analogRead(flexPin);
  
  // Sensör değerini açıya dönüştür
  float angle = mapFlexToAngle(flexValue);
  
  // Açıyı ve sensör değerini seri monitöre yazdır
  Serial.print("Açı: ");
  Serial.print(angle);
  Serial.print(" derece, Sensör Değeri: ");
  Serial.println(flexValue);
  
  // Kısa bir bekleme süresi
  delay(1000);
}
