#include <string>

float kelvin_to_f(float kelvin) {
    return (9.0 / 5) * (kelvin - 273.15) + 32;
}

class Weather {
    public:
        float temperatureF();
        void setTemperatureK(float temperature) {
            temperatureK = temperature;
        }
    private:
        float temperatureK;
};

float Weather::temperatureF() {
    return (9.0 / 5) * (temperatureK - 273.15) + 32;
}