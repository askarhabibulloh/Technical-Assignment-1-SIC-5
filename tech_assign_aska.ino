#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// Definisikan pin yang digunakan untuk sensor DHT11 dan MQ
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define MQPIN 5
#define MQPIND 19
const char* ssid = "Ngomah";
const char* password = "penginapan";
const char* serverName = "http://192.168.1.8:5001/api/data";

void setup() {
  pinMode(MQPIND, INPUT);
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Menghubungkan ke WiFi...");
  }

  Serial.println("Terhubung ke WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Baca data dari sensor DHT11
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Baca data dari sensor MQ
    int gas = analogRead(MQPIN);
    int gasd = digitalRead(MQPIND);


    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Gagal membaca data dari DHT11!");
      return;
    }

    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    // Buat payload JSON
    String payload = "{\"temperature\":";
    payload += String(temperature);
    payload += ",\"humidity\":";
    payload += String(humidity);
    payload += ",\"gas\":";
    payload += String(gasd);
    payload += "}";

    int httpResponseCode = http.POST(payload);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error pada pengiriman POST: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("Tidak terhubung ke WiFi");
  }


  delay(3000); // Kirim data setiap 60 detik
}
