#include "LiChessAPI.h"

// метод создания игры 
// TODO сделать не строки, а объекты
String LiChessAPI::createGameWithBot() {
    GameBotPostRequest gameBotPostRequest(5, 10800, 60, 1);
    String xd = gameBotPostRequest.toString();
    http.begin(CREATE_GAME_WITH_BOT_LINK); 
    http.addHeader("Authorization", "Bearer " + token);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    http.addHeader("charset", "utf-8");
    http.addHeader("Accept-Encoding", "gzip, deflate, br");
    http.addHeader("Content-Length", String(xd.length()));
    Serial.println(xd);
    int httpResponseCode = http.POST(xd); 


    String response = "";
    if(httpResponseCode>0){
        response = http.getString();  
        Serial.println(httpResponseCode);  
        Serial.println(response);         
    } else {
        Serial.print("Error on sending POST: ");
        Serial.println(httpResponseCode);
        String response = http.getString();
        Serial.println(response);
        http.end();
    }

    return response;
}


String LiChessAPI::cancelGameWithBot(String uid) {
    CANCEL_GAME.replace("{challengeId}", uid);
    http.begin(CANCEL_GAME); 
    Serial.println(CANCEL_GAME);
    http.addHeader("Authorization", "Bearer " + token);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    http.addHeader("charset", "utf-8");
    http.addHeader("Accept-Encoding", "gzip, deflate, br");
    int httpResponseCode = http.POST(""); 

    String response = "";
    if(httpResponseCode>0){
        response = http.getString();  
        Serial.println(httpResponseCode);  
        Serial.println(response);         
    } else {
        Serial.print("Error on sending POST: ");
        Serial.println(httpResponseCode);
        String response = http.getString();
        Serial.println(response);
        http.end();
    }

    return response;
}