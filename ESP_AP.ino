#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// SSID dan Password untuk AP Mode
const char *ssid = "ESP32-Access-Point";
const char *password = "12345678";

// Inisialisasi server di port 80
AsyncWebServer server(80);

// HTML form untuk memasukkan username dan password
const char* loginPage = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP32 Setup</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
  <h2>ESP32 Login</h2>
  <form action="/login" method="post">
    <label for="username">Username:</label><br>
    <input type="text" id="username" name="username"><br>
    <label for="password">Password:</label><br>
    <input type="password" id="password" name="password"><br><br>
    <input type="submit" value="Submit">
  </form>
</body>
</html>
)rawliteral";

// Halaman untuk pengaturan setelah login
const char* settingsPage = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP32 Settings</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
  <h2>ESP32 Settings</h2>
  <p>Welcome to the settings page!</p>
</body>
</html>
)rawliteral";

// Function untuk menangani permintaan login
void handleLoginRequest(AsyncWebServerRequest *request) {
  if (request->hasParam("username", true) && request->hasParam("password", true)) {
    String username = request->getParam("username", true)->value();
    String password = request->getParam("password", true)->value();

    // Cek username dan password
    if (username == "admin" && password == "admin") {
      request->send(200, "text/html", settingsPage);
    } else {
      request->send(401, "text/html", "Login Failed");
    }
  } else {
    request->send(400, "text/html", "Bad Request");
  }
}

void setup() {
  // Mengatur mode AP
  WiFi.softAP(ssid, password);

  // Menampilkan IP Address
  Serial.begin(115200);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  // Mengatur route untuk halaman login
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", loginPage);
  });

  // Mengatur route untuk menangani login request
  server.on("/login", HTTP_POST, handleLoginRequest);

  // Memulai server
  server.begin();
}

void loop() {
  // Tidak ada yang dilakukan di loop()
}
