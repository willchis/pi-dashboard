# pi-dashboard
LCD dashboard with weather, time, stock prices.

- Clone wiringPi repo: https://github.com/WiringPi/WiringPi
- Install libcurl: `sudo apt-get update; sudo apt-get install curl; sudo apt-get install libcurl3`
- Compile with linked libs: `g++ -o main main.cpp -lwiringPi -lwiringPiDev -lcurl`
