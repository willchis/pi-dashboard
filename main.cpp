#include <iostream>
#include <fstream>
#include <ctime>
#include "request.cpp"
#include "lcd.cpp"

// arm-linux-gnueabihf-g++ -O3 -g3 -Wall -c -o -fPIC "main.o" -lcurl -lwiringPi -lwiringPiDev -lpthread -lcrypt -lrt "main.cpp"

void padText(char text[], int textLength, char padCharacter, int padCount) {
    char tempText[textLength];
    char tempChar = text[0];

    for (int i = 0; i < textLength; i++) {
        tempText[i] = text[i];
        if (i < padCount) {
            text[i] = padCharacter;
        }
    }

    for (int i = 0; i < textLength; i++) {
        if (i == textLength - 1) {
            text[i] = '\0';
        } else if (i >= padCount) {
            if (tempText[i - padCount] == '\0') {
                break;
            }
            text[i] = tempText[i - padCount];
        }

    }
}

Weather refreshData() {
    char* appId = getenv("APPID");
    if (appId == NULL) {
        std::string error = "Weather API key not found in APPID env variable";
        std::cout << error << std::endl;
        throw error;
    }
    return get_request("https://api.openweathermap.org/data/2.5/weather?lat=40.002538&lon=-105.1399453&appId=" + std::string(appId));
}

int main()
{
    std::time_t time = std::time(0);
    std::tm* now = std::localtime(&time);
    std::string today = std::to_string(now->tm_year + 1900) 
        + '-' + std::to_string(now->tm_mon + 1) 
        + '-' + std::to_string(now->tm_mday);

    //char test[] = "tesonetw";
    //int length = sizeof(test) / sizeof(char);

    //padText(test, length, ' ', 5);

    //setupAndPrint(&refreshData);
    //printDataTime(0, "UTC");
    //printDataTime(-7, "MDT");
    refreshData();
    return 0;
}

