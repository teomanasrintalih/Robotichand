#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN         
const byte address[6] = "00001";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.
int button_pin = 2;
boolean button_state = 0;

int msg[5]; //Total number of data to be sent (data package)

//define the flex sensor input pins
int flex_5 = A5;//SERCE
int flex_4 = A4;//yüzük
int flex_3 = A3;//BAS
int flex_2 = A2;//işaret
int flex_1 = A1;//ORTA

//define variables for flex sensor values
int flex_5_val;
int flex_4_val;
int flex_3_val;
int flex_2_val;
int flex_1_val;




void setup() {
  Serial.begin(9600);
pinMode(button_pin, INPUT);
radio.begin();                  //Starting the Wireless communication
radio.openWritingPipe(address); //Setting the address where we will send the data
radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
radio.stopListening();          //This sets the module as transmitter
}
void loop()
{
  flex_5_val = analogRead(flex_5); 
  flex_5_val = map(flex_5_val, 590, 700, 0, 110);
  
  flex_4_val = analogRead(flex_4);
  flex_4_val = map(flex_4_val, 630, 770, 116, 0);
 
  flex_3_val = analogRead(flex_3);
  flex_3_val = map(flex_3_val, 1010, 1017, 0, 130);
 
  flex_2_val = analogRead(flex_2);
  flex_2_val = map(flex_2_val, 670, 820, 0, 105);
  
  flex_1_val = analogRead(flex_1);
  flex_1_val = map(flex_1_val, 1010, 1015, 180 ,0);//orta parmak
  
  msg[0] = flex_5_val;
  msg[1] = flex_4_val;
  msg[2] = flex_3_val;
  msg[3] = flex_2_val;
  msg[4] = flex_1_val;
  radio.write(msg, sizeof(msg));

/*
button_state = digitalRead(button_pin);
if(button_state == HIGH)
{
const char text[] = "gonderildi";
radio.write(&text, sizeof(text));                  //Sending the message to receiver
}
else
{
const char text[] = "Your Button State is LOW";
radio.write(&text, sizeof(text));                  //Sending the message to receiver 
}
radio.write(&button_state, sizeof(button_state));  //Sending the message to receiver 

*/
 //int flex_1_val = analogRead(flexPin); // Flex sensöründen okunan değer
  


  
  // Açıyı ve sensör değerini seri monitöre yazdır
  Serial.print("Açı: ");
  Serial.print(flex_3);
  Serial.print(" derece, Sensör Değeri: ");
  Serial.println(flex_3_val);

  delay(1000); // 0.5 saniye bekleme

}
