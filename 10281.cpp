#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string line;

    double current_speed = 0;
    double km_travelled = 0;

    int last_hour = 0;
    int last_minute = 0;
    int last_second = 0;

    while(getline(cin, line)) {
        stringstream ss(line);

        string colon_time;
        ss >> colon_time;

        int colon_1 = colon_time.find(':');
        int colon_2 = colon_time.substr(colon_1 + 1).find(':');

        int hour = stoi(colon_time.substr(0,colon_1), nullptr);
        int minute = stoi(colon_time.substr(colon_1 + 1, colon_2), nullptr);
        int second = stoi(colon_time.substr(colon_1 + colon_2 + 2), nullptr);

        int current_time = 3600*hour + 60*minute + second;
        int last_time = 3600*last_hour + 60*last_minute + last_second;

        km_travelled += (current_time - last_time)*(current_speed/3600);

        int speed_change;
        if (!ss.eof()) ss >> current_speed;
        else printf("%02d:%02d:%02d %.2lf km\n", hour, minute, second, km_travelled);

        last_hour = hour;
        last_minute = minute;
        last_second = second;
    }
}