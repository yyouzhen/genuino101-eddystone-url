#include <CurieBLE.h>
BLEService eddystoneService = BLEService("FEAA");
BLECharacteristic eddystoneCharacteristic("FEAA",BLEBroadcast,20);

void setup() {

  // Begin BLE
  BLE.begin();

  // Set the UUID for the service this peripheral advertises
  BLE.setAdvertisedService(eddystoneService);

  // Add the characteristic to the service
  eddystoneService.addCharacteristic(eddystoneCharacteristic);

  // Add service
  BLE.addService(eddystoneService);

  // Broadcast
  eddystoneCharacteristic.broadcast();

  // It was generated at https://www.mkompf.com/tech/eddystoneurl.html
  uint8_t advdata[] =
  {
    0x10,  // Frame type: URL
    0xF8, // Power
    0x01, // https://www.
    'g',
    'o',
    'o',
    'g',
    'l',
    'e',
    '.',
    'c',
    'o',
    '.',
    'j',
    'p',
  };

  // Set advertising data
  eddystoneCharacteristic.writeValue(advdata,sizeof(advdata));

  // Start advertising
  BLE.advertise();

}

void loop() {
  //empty
}
