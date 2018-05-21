#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define ONE_WIRE_BUS 2

#define mqtt_server "serverip"
#define mqtt_user "user"
#define mqtt_password "pass"
#define temp0 "sensor0_temp0"
#define temp1 "sensor0_temp1"

const char* ssid = "SSID";
const char* password = "PW"; 

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

WiFiClient espClient;
PubSubClient client(espClient);

void setup(void)
{
    WiFi.begin(ssid, password);
    client.setServer(mqtt_server, 1883);
    sensors.begin();

    sensors.requestTemperatures();

    float temps0 = sensors.getTempCByIndex(0);
    float temps1 = sensors.getTempCByIndex(1);

    client.connect("sensor0", mqtt_user, mqtt_password);
    client.publish(temp0, String(temps0).c_str() , true);
    client.publish(temp1, String(temps1).c_str() , true);
    client.disconnect();
    ESP.deepSleep(600000000); // 10 minutes.
}

void loop(void)
{
}
