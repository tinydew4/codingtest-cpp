#include <iostream>

int main(void)
{
    int input;
    int sum = 0;
    for (int a = 2; a-- > 0; ) {
        std::cin >> input;
        sum += input;
    }
    std::cout << sum << std::endl;
    return 0;
}
