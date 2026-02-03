#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "motors.h"

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

// get incoming commands and call respective functions

class CommandCallbacks: public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    std::string value = pCharacteristic->getValue();

    if (value.length() == 0) return;

    char command = value[0];

    Serial.print("Received command: ");
    Serial.println(command);

    switch (command) {
      case 'F':
        Serial.println("Move Forward");
        moveForward();
        break;

      case 'B':
        Serial.println("Move Back");
        moveBack();
        break;

      case 'L':
        Serial.println("Turn Left");
        turnLeft();
        break;

      case 'R':
        Serial.println("Turn Right");
        turnRight();
        break;

      case 'S':
        Serial.println("Stop");
        stopMotors();
        break;

      default:
        Serial.println("Unknown command");
        break;
    }
  }
};

void setup() {
  Serial.begin(115200);
  pinMode(rightPin1, OUTPUT);
  pinMode(rightPin2, OUTPUT);
  pinMode(leftPin1, OUTPUT);
  pinMode(leftPin2, OUTPUT);

  // setting motors to not run on setup 
  digitalWrite(rightPin1, LOW);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, LOW);
  Serial.println("Starting BLE work!");

  BLEDevice::init("ListToMaybes"); // haskell reference :)
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );
  
  pCharacteristic->setCallbacks(new CommandCallbacks());

  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
}