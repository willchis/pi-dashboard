#include <iostream>
#include <curl/curl.h>
#include "json.hpp"
#include "weather.cpp"

struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *data)
{
    ssize_t realsize = size * nmemb;

    std::string* mem = reinterpret_cast<std::string*>(data);
    mem->append(static_cast<char*>(contents), realsize);

    return realsize;
}

// TODO return object with weather data
Weather get_request(std::string url) {
    CURLcode res;
    Weather weather;

    CURL *curl = curl_easy_init();
    if(curl) {
        std::string data;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        std::cout << data << std::endl;

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            if (data.size() > 0) {
                nlohmann::json weather_data = nlohmann::json::parse(data);
                //std::string temperature = weather_data["main"]["temp"];
                weather.temperature = kelvin_to_f(weather_data["main"]["temp"]);
                std::cout << weather.temperature << std::endl;
                printf("%f", weather.temperature);

            }
        }
        curl_easy_cleanup(curl);
    }
    return weather;
}