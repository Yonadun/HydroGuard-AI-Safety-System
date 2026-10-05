#define BLYNK_TEMPLATE_ID "TMPL6UYYGfPL1"
#define BLYNK_TEMPLATE_NAME "Hydrogen Safety System"
#define BLYNK_AUTH_TOKEN "IboktRfFD4Z0WJnPG78KfDB4Vt1eLyhp"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <WebSocketsClient.h>

// Pin Definitions
#define GAS_SENSOR_PIN 34
#define VALVE_RELAY_PIN 23     // Emergency Isolation Valve (LED)
#define HARDWARE_BUZZER_PIN 19 // Hardware Alarm Buzzer

const char* ssid = "Wokwi-GUEST";
const char* password = "";

WebSocketsClient webSocket;
bool alertSent = false; 

void setup() {
  Serial.begin(115200);

  pinMode(VALVE_RELAY_PIN, OUTPUT);
  pinMode(HARDWARE_BUZZER_PIN, OUTPUT);

  digitalWrite(VALVE_RELAY_PIN, LOW);
  noTone(HARDWARE_BUZZER_PIN);

  // Connect to Wokwi Virtual Wi-Fi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected successfully!");

  // Initialize Blynk Cloud
  Blynk.config(BLYNK_AUTH_TOKEN, "blynk.cloud", 80);

  
  webSocket.begin("ws.postman-echo.com", 80, "/raw");
}

void loop() {
  Blynk.run();        
  webSocket.loop();    

  int analogValue = analogRead(GAS_SENSOR_PIN);
  int gasPpm = map(analogValue, 0, 4095, 200, 3000);

  // --- HARDWARE LOGIC & BLYNK NOTIFICATION LOGIC ---
  if (gasPpm >= 2000) { 
    digitalWrite(VALVE_RELAY_PIN, HIGH);     
    tone(HARDWARE_BUZZER_PIN, 1000);         
    
    if (!alertSent) {
      Serial.println(">>> ALERT: Critical Gas Level Exceeded! Sending Blynk Notification... <<<");
      Blynk.logEvent("gas_leak", "Critical Hydrogen Leak Detected! Level: " + String(gasPpm) + " PPM");
      alertSent = true; 
    } else {
      Serial.println("Gas Level: " + String(gasPpm) + " PPM | Status: [CRITICAL LEAK - ALREADY ALERTED]");
    }
  } else {
    digitalWrite(VALVE_RELAY_PIN, LOW);      
    noTone(HARDWARE_BUZZER_PIN);             
    Serial.println("Gas Level: " + String(gasPpm) + " PPM | Status: [NORMAL]");
    
    alertSent = false; 
  }

  // Send Gas PPM Data to Blynk App
  Blynk.virtualWrite(V0, gasPpm);

  // Send Telemetry Payload to Web Dashboard
  String payload = "{\"ppm\":" + String(gasPpm) + "}";
  webSocket.sendTXT(payload);

  delay(500);
}