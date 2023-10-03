#include <iostream>
#include <cmath>

int digits(int a) {
    if (a == 0) {
        return 0;
    }
    return 1 + digits(a / 10);
}

int splitAt(int x, int d) {
    return x / static_cast<int>(pow(10, d));
}

int karatsuba(int a, int b) {
    if (a < 10 && b < 10) {
        return a * b;
    }
    int digitMax = static_cast<int>(std::max(digits(a), digits(b)) / 2);

    int a1 = splitAt(a, digitMax);
    int a2 = a % static_cast<int>(pow(10, digitMax));
    int b1 = splitAt(b, digitMax);
    int b2 = b % static_cast<int>(pow(10, digitMax));

    int x = karatsuba(a1, b1);
    int y = karatsuba(a2, b2);
    int z = karatsuba((a1 + a2), (b1 + b2)) - x - y;

    return x * static_cast<int>(pow(10, 2 * digitMax)) + z * static_cast<int>(pow(10, digitMax)) + y;
}

int main() {
    int result = karatsuba(12354, 65435);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
