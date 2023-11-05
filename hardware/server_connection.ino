#include <WiFi.h>
#include <esp_wifi.h>
#include <ESP32_Supabase.h> 

//MAC ADD: 08:B6:1F:6F:2F:18

//Supabase Setup
Supabase db;

//Wifi Setup
const char* ssid = "ufguest";
const char* wifi_password = "";

//Sever Setup
/*const char* serverAddress = "";  // e.g., "192.168.1.100" or "www.example.com"
const int serverPort = 80;  // Port number to connect*/

// Put your supabase URL and Anon key here...
// Because Login already implemented, there's no need to use secretrole key
String supabase_url = "https://xzissfgunvpzgocavmvi.supabase.co";
String anon_key = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6Inh6aXNzZmd1bnZwemdvY2F2bXZpIiwicm9sZSI6ImFub24iLCJpYXQiOjE2OTkwMzY5MjYsImV4cCI6MjAxNDYxMjkyNn0.yimNI3OEgNYs5dvwwcdO4Lr41yGEj-FE1c-tzofI4AM";

// Put Supabase account credentials here
const String email = "hello@sproutscouts.com";
const String password = "test1234";

void setup() {

  Serial.begin(115200);
    WiFi.begin(ssid, wifi_password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

}

WiFiClient client;

/*void connectToServer() {
    if (client.connect(serverAddress, serverPort)) {
        Serial.println("Connected to server");
        // You're connected - do whatever you need here, like sending or receiving data
    } else {
        Serial.println("Connection to server failed");
    }
}*/

/*void sendDataToServer() {
    if (client.connected()) {
        // Data to be sent
        String data = "SensorValue=100"; // Replace this with your data
        
        // Make an HTTP GET request to the server
        client.print("GET /your_endpoint?");  // Replace /your_endpoint with the specific endpoint on your server
        client.print(data);
        client.println(" HTTP/1.1");
        client.print("Host: ");
        client.println(serverAddress);
        client.println("Connection: close");
        client.println();
    }
}*/

void loop() {
  //CODE TO TEST WIFI
  /*while(WiFi.status() == WL_CONNECTED){ 

      digitalWrite(2, HIGH); // turn the LED on (HIGH is the voltage level) 

      delay(1000); // wait for a second 

      digitalWrite(2, LOW); // turn the LED off by making the voltage LOW 

      delay(1000); // wait for a second 

  } 

  WiFi.disconnect(); 

  digitalWrite(2, LOW);   

  while(WiFi.status() != WL_CONNECTED){ 

      WiFi.reconnect(); 

      delay(500); 

  } */

  /*if (!client.connected()) {
    connectToServer();
  }*/
  // Handle other tasks or data exchange with the server here

   // Beginning Supabase Connection
  /*db.begin(supabase_url, anon_key);

  // Logging in with your account you made in Supabase
  db.login_email(email, password);

  // Select query with filter and order, limiting the result is mandatory here
  String read = db.from("plants").select("*").limit(1).doSelect();
  
  //.eq("name", "value").order("name", "asc", true).limit(1).doSelect();
  Serial.println(read);*/

  /*if (client.connected()) {
      // Data to be sent
      String data = "SensorValue=100"; // Replace this with your data
      
      // Make an HTTP GET request to the server
      client.print("GET /your_endpoint?");  // Replace /your_endpoint with the specific endpoint on your server
      client.print(data);
      client.println(" HTTP/1.1");
      client.print("Host: ");
      client.println(serverAddress);
      client.println("Connection: close");
      client.println();
  }*/

} 

