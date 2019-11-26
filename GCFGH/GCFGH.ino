//IcCoBoDeCrAnE Coding
#include <ESP8266WiFi.h>
 
const char* ssid = "WIFI NAME"; // SSID i.e. Service Set Identifier is the name of your WIFI
const char* password = "PASSWORD"; // Your Wifi password, in case you have open network comment the whole statement.
 
int ledPin1 = x; // GPIO13 or for NodeMCU you can directly write D7
int ledPin2 = x;   //------------------------------------------------------------------->>>
int ledPin2 = x;                    //ADD LED PINS HERE
int ledPin2 = x;   //------------------------------------------------------------------->>
WiFiServer server(80); // Creates a server that listens for incoming connections on the specified port, here in this case port is 80.
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin1, OUTPUT);
  digitalWrite(ledPin1, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP()); //Gets the WiFi shield's IP address and Print the IP address of serial monitor
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  {
    Serial.println("led 1 on");
    digitalWrite(ledPin1, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
        Serial.println("led 1 off");
     digitalWrite(ledPin1, LOW);
    value = LOW;
  }
  if (request.indexOf("/LED2=ON") != -1)  {
    Serial.println("led 2 on");
    digitalWrite(ledPin2, HIGH);           
    value = HIGH;                          
  }
  if (request.indexOf("/LED2=OFF") != -1)  {               //-------------------------------------------------------------------->>>>
    Serial.println("led 2 off");
    digitalWrite(ledPin2, LOW);              
    value = LOW;                            
  }
  if (request.indexOf("/LED3=ON") != -1)  {
    Serial.println("led 3 on");
    digitalWrite(ledPin3, HIGH);           
    value = HIGH;                          
  }
  if (request.indexOf("/LED3=OFF") != -1)  {                                  // MODIFIY THEES SCOPES TOOO
   
    Serial.println("led 3 off");
    digitalWrite(ledPin3, LOW);              
    value = LOW;                            
  }
  if (request.indexOf("/LED4=ON") != -1)  {
    Serial.println("led 4 on");
    digitalWrite(ledPin4, HIGH);           
    value = HIGH;                          
  }
  if (request.indexOf("/LED4=OFF") != -1)  {             //---------------------------------------------------------------------->>
    Serial.println("led 4 off");
    digitalWrite(ledPin4, LOW);              
    value = LOW;                            
  }
 
 
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");
 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");                       // modified lines ----------------------------------------------------------->>>
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");  
  client.println("<a href=\"/LED2=ON\"\"><button>Turn Off </button></a><br />");  
  client.println("<a href=\"/LED2=OFF\"\"><button>Turn Off </button></a><br />");                  // MODIFY THIS AS WE NEED
  client.println("<a href=\"/LED3=ON\"\"><button>Turn Off </button></a><br />");  
  client.println("<a href=\"/LED3=OFF\"\"><button>Turn Off </button></a><br />"); 
  client.println("<a href=\"/LED4=ON\"\"><button>Turn Off </button></a><br />");  
  client.println("<a href=\"/LED4=OFF\"\"><button>Turn Off </button></a><br />");             //----------------------------------------------------------------------------->>>

  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
