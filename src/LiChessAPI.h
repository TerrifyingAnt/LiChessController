#include <Arduino.h>
#include <WiFiManager.h> 
#include <HTTPClient.h>
#include "Models/Request/GameBotPostRequest.h"
#include "Models/Response/GameBotPostResponse.h"
#include "Models/Response/CancelGameResponse.h"

#ifndef LICHESSAPI_H
#define LICHESSAPI_H

class LiChessAPI {

    private: 
        String CREATE_GAME_WITH_BOT_LINK = "https://lichess.org/api/challenge/ai";
        String CANCEL_GAME = "https://lichess.org/api/challenge/{challengeId}/cancel";
        String ACCOUNT_LINK = "https://lichess.org/api/account"; 

        HTTPClient http;

        String token = "lip_OZL9UqGyOSi3diqI455r";

    // TODO
        String CREATE_GAME_WITH_PLAYER_LINK = "https://lichess.org/api/account";


    public:
        void getAccount(); // метод для получения информации об аккаунте

        String createGameWithBot(); // метод дял создания игры с ботом

        String cancelGameWithBot(String uid); // метод для отмены игры с ботом


};

#endif

