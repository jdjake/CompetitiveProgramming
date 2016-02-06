#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    long long minutes, hours;
    while (true) {
        scanf("%lld:%lld", &hours, &minutes);
        if (hours == 0 && minutes == 0) return 0;

        double hour_angle = 30*hours + (double)minutes/2;
        double minute_angle = (double)minutes*6;

        double output = hour_angle - minute_angle;
        while (output < 0) output += 360;
        while (output >= 360) output -= 360;
        if (output > 180) output = 360 - output;

        printf("%.3lf\n", output);
    }
}