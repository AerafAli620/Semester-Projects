#include <esp_now.h>
#include <WiFi.h>
#include "BluetoothSerial.h"
#define SEND 2
#define RECIEVE 18
#define SOUND 22
//////////////////////////////////////////
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif
//////////////////////////////////////////////////////////////////////
BluetoothSerial SerialBT;
uint8_t broadcastAddress[] = {0x34, 0x94, 0x54, 0x25, 0x0A, 0x14};
String SMS;
String inco_SMS;
String success;
//Structure example to send data
//Must match the receiver structure
typedef struct struct_message {
    char sms[40];
} struct_message;

struct_message Read_sms;
struct_message incoming_SMS;

esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
  if (status ==0){
    success = "Delivery Success :)";
  }
  else{
    success = "Delivery Fail :(";
  }
}

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  digitalWrite(RECIEVE,HIGH);
  digitalWrite(SOUND,HIGH);
  memcpy(&incoming_SMS, incomingData, sizeof(incoming_SMS));
  Serial.print("Bytes received: ");
  Serial.println(len);
   inco_SMS=incoming_SMS.sms;
  Serial.println(inco_SMS);
//  uint8_t buff[inco_SMS.length()];
//  memcpy(buff,inco_SMS.c_str(),inco_SMS.length());
//  SerialBT.write(buff,inco_SMS.length());
   Serial.print("Recieve: ");
   SerialBT.println(inco_SMS);
   delay(100);
   digitalWrite(SOUND,LOW);
  digitalWrite(RECIEVE,LOW);
}
 
void setup() {
  pinMode(SEND,OUTPUT);
  pinMode(RECIEVE,OUTPUT);
  pinMode(SOUND,OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP1"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

 // Init ESP-NOW
WiFi.mode(WIFI_STA);
if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;

 //Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(OnDataRecv);

}

void send_messege()
{
  strcpy(Read_sms.sms, SMS.c_str());
  digitalWrite(SEND,HIGH);
  // Set values to send
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &Read_sms, sizeof(Read_sms));
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  delay(100);
  digitalWrite(SEND,LOW);
}
void loop() {
    if (SerialBT.available()) {
    SMS =SerialBT.readString();
    send_messege();
}
//getReadings();
//send_messege();
}
//void getReadings(){
// Serial.println("Read Messege.");  
//    while (Serial.available() == 0)   
//    { }
//    SMS = Serial.readString();  
//    Serial.println(SMS);
//}
