#include <CurieBLE.h>

void setup() {

  BLEService eddystoneService = BLEService("FEAA");
  BLECharacteristic eddystoneCharacteristic("FEAA",BLERead|BLEBroadcast,20);

  BLE.begin();
  BLE.setAdvertisedService(eddystoneService);
  eddystoneService.addCharacteristic(eddystoneCharacteristic);
  BLE.addService(eddystoneService);
  eddystoneCharacteristic.broadcast();

  // It was generated at https://www.mkompf.com/tech/eddystoneurl.html
  uint8_t advdata[] =
  {
    0x10,  // Frame type: URL
    0xF8, // Power
    /** Google Japan
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
    **/
    0x02, // http://
    'x',
    0x01, // .org/
  };
  eddystoneCharacteristic.writeValue(advdata,sizeof(advdata));

  BLE.advertise();

}

void loop() {
  //empty
}
