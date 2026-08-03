#include <iostream>
#include <stdexcept>

double divide(int a, int b) {
    if (b == 0)
        throw std::runtime_error("division by zero");
    return a / b;
}

int main() {
    try {
        double result = divide(10, 1);   // 여기서 예외가 발생
        std::cout << result << std::endl; // 이 줄은 실행 안 됨
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }
}
