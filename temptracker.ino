
#include <Grove_Temperature_And_Humidity_Sensor.h>
#include <JsonParserGeneratorRK.h>

#define DELAY_TIME 30000 //30 Sec
#define DHT_PIN D3

DHT dht(DHT_PIN);

double temp;

void postEventPayload(double temp)
{
    JsonWriterStatic<256>jw;
    {
        JsonWriterAutoObject obj(&jw);
        jw.insertKeyValue("temp", temp);

    }
    Particle.publish("temp", String(temp), PRIVATE);
}

void setup(){
    dht.begin();
    pinMode(DHT_PIN, INPUT);
}

void loop(){
    temp = dht.getTempCelcius();
    postEventPayload(temp);
    delay(DELAY_TIME);
}
