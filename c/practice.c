#include <stdio.h>

int main() {
    float sum = 0.0;

    for (float i = 1; i <= 9; i++) {
        sum += i / (i + 1);
    }
    printf("Sum = %f", sum);

    return 0;
}
