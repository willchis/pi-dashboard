#include <string>

float kelvin_to_f(float kelvin) {
    return (9.0 / 5) * (kelvin - 273.15) + 32;
}

class Weather {
    public:
        float temperature;
};