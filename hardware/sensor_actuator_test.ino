#include "DHT.h"

#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#define waterRelay 21
#define moistSensor 36 // NEEDS TO BE 36
#define lightSensor 15
#define lightRelay 23

DHT dht(DHTPIN, DHTTYPE);

int lightInit;  // initial value
int lightVal;

void setup() {
  Serial.begin(115200);
  pinMode(waterRelay, OUTPUT);
  pinMode(lightRelay, OUTPUT);
  pinMode(lightRelay, OUTPUT);

  lightInit = analogRead(lightSensor);
  //we will take a single reading from the light sensor and store it in the lightCal        
  //variable. This will give us a prelinary value to compare against in the loop
  digitalWrite(waterRelay, HIGH);
  digitalWrite(lightRelay, HIGH);
  dht.begin();
}

void loop() {
  int moisture = analogRead(moistSensor); // lower is wetter, higher is dryer about 1000-3000
  Serial.print("Moisture: ");
  Serial.println(moisture);
  if (moisture < 2500) { // more wet
    digitalWrite(waterRelay, LOW);
    //Serial.println("Relay on");
  } else {
    digitalWrite(waterRelay, HIGH);
    //Serial.println("Relay off");
  }
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F")); 

  int lightVal = analogRead(lightSensor);
  Serial.print("Light diff: ");
  Serial.println(lightVal - lightInit);
  if(lightVal - lightInit <  50)
  {
    digitalWrite(lightRelay, LOW); // turn on light
  }
  else
  {
    digitalWrite(lightRelay, HIGH); // turn off light
  }
}
