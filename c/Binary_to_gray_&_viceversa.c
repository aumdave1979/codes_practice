#include <stdio.h>

// Binary to Gray
int binaryToGray(int num) {
    return num ^ (num >> 1);
}

// Gray to Binary
int grayToBinary(int gray) {
    int binary = gray;
    while (gray >>= 1) {
        binary ^= gray;
    }
    return binary;
}

int main() {
    int num;
    
    printf("Enter a binary number (as decimal): ");
    scanf("%d", &num);

    int gray = binaryToGray(num);
    printf("Gray code: %d\n", gray);

    int original = grayToBinary(gray);
    printf("Back to binary: %d\n", original);

    return 0;
}
