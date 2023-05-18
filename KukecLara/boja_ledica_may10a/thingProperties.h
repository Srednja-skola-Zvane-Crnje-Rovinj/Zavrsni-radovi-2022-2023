
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)

void onBojaLedChange();
void onSvjetlinaLedChange();
void onFade1Change();
void onPowerOnOffChange();

CloudColor bojaLed;
int svjetlinaLed;
bool fade1;
bool powerOnOff;

void initProperties(){

  ArduinoCloud.addProperty(bojaLed, READWRITE, ON_CHANGE, onBojaLedChange);
  ArduinoCloud.addProperty(svjetlinaLed, READWRITE, ON_CHANGE, onSvjetlinaLedChange, 100);
  ArduinoCloud.addProperty(fade1, READWRITE, ON_CHANGE, onFade1Change);
  ArduinoCloud.addProperty(powerOnOff, READWRITE, ON_CHANGE, onPowerOnOffChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
