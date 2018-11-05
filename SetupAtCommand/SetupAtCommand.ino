/**
 * Bluetooth HC-06
 * This project show with make setup the bluetooth module using command AT
 * List the comand basic AT
 * AT+VERSION   OKlinvorV1.8       The firmware version     
\* AT+NAMExyz  OKsetname     Sets the module name to “xyz”
 * AT+PIN1234  OKsetPIN            Sets the module PIN to 1234
 * AT+BAUD1  OK1200            Sets the baud rate to 1200
 * AT+BAUD2  OK2400            Sets the baud rate to 2400
 * AT+BAUD3  OK4800            Sets the baud rate to 4800
 * AT+BAUD4  OK9600            Sets the baud rate to 9600
 * AT+BAUD5  OK19200             Sets the baud rate to 19200
 * AT+BAUD6  OK38400             Sets the baud rate to 38400
 * AT+BAUD7  OK57600             Sets the baud rate to 57600
 * AT+BAUD8  OK115200    Sets the baud rate to 115200
 * AT+BAUD9  OK230400    Sets the baud rate to 230400
 * AT+BAUDA  OK460800    Sets the baud rate to 460800  
 * AT+BAUDB  OK921600      Sets the baud rate to 921600
 * AT+BAUDC  OK1382400     Sets the baud rate to 1382400 
 */

//Load lib to communication bluetooth 
#include <SoftwareSerial.h>

#define RX_PIN 6
#define TX_PIN 7

SoftwareSerial SerialCommunication(RX_PIN, TX_PIN);
String commandAT = "";

void setup() {
  Serial.begin(11600);
  Serial.println("typing AT a command");

  SerialCommunication.begin(9600);
}

void loop() {
  if(SerialCommunication.available()) {
    while(SerialCommunication.available()) {
     commandAT += (char)SerialCommunication.read();
   }
   Serial.println(commandAT);
   commandAT = "";
  }

  if(Serial.available()) {
    delay(10);
    SerialCommunication.write(Serial.read());
  }
  
}
