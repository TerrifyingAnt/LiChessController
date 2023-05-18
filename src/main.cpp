#include <Arduino.h>
#include <WiFiManager.h> 
#include <HTTPClient.h>
#include "LiChessAPI.h"


String val = "";
LiChessAPI liChessAPI;
String gameID = "";

void setup() {
  Serial.begin(9600);
  WiFi.begin("TP-Link_10DC", "37163006");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  pinMode(2, OUTPUT);

  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {

  if (Serial.available()) 
  { 
    val = Serial.read(); 
  }
  if (val == "1")  {
    String gameBotPostResponse = liChessAPI.createGameWithBot();
    gameID = gameBotPostResponse.substring(gameBotPostResponse.indexOf("id") + 5, gameBotPostResponse.indexOf("id") + 13);
    Serial.print("GAME_ID: " + gameID);
    digitalWrite(2, HIGH); // turn the LED on
    val = "";
    
  }
  else
  if (val == "2")  {
    liChessAPI.cancelGameWithBot(gameID);
    val = "";
    digitalWrite(2, LOW); 
  }
  else
  if (val == "3")
  { 
    digitalWrite(2, HIGH); 
  } else {
    digitalWrite(2, LOW); 
  }
  delay(10); 
}

// TODO
void initNetwork() {
  
}
