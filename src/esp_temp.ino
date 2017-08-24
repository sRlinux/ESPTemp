#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>

#define ONE_WIRE_BUS 2

const char* ssid = "YOURSSID";
const char* password = "YOURPASSWORD";

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

WiFiClient serverClient;
WiFiServer server(1234);

void setup(void)
{
    WiFi.begin(ssid, password);
    sensors.begin();
    server.begin();
}

void loop(void)
{
    sensors.requestTemperatures();

    float temp1 = sensors.getTempCByIndex(0);
    float temp2 = sensors.getTempCByIndex(1);
    WiFiClient client = server.available();

    client.print(temp1, 2);
    client.print(" ");
    client.print(temp2, 2);
    delay(1);
}
