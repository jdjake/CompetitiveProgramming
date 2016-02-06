#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    char binary[200];
    for (int i = 0; i < 200; i++) binary[i] = '\0';

    int i = 0;
    while (N != 0) {
//        printf("%d\n", N);
        binary[i] = (N % 2 == 0) ? '0' : '1';
        N = N >> 1;
        i++;
    }

    int length = strlen(binary);

    char reversed_binary[200];
    for (int i = 0; i < 200; i++) reversed_binary[i] = '\0';

//    printf("LENGTH: %d\n", strlen(binary));

    for (int i = 0; i < strlen(binary); i++) {
        reversed_binary[strlen(binary) - i - 1] = binary[i];
    }

//    printf("%s\n", binary);
//    printf("%s\n", reversed_binary);

    // make number
    int num = 0;
    for(int i = 0; i < strlen(reversed_binary); i++) {
        num += (1 << i)*((reversed_binary[i] == '1') ? 1 : 0);
    }

    printf("%d\n", num);
}