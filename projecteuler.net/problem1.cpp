#include <numeric>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> Number(1000);
    std::iota(Number.begin(), Number.end(), 0);
    int iResult = std::accumulate(Number.begin(), Number.end(), 0, [](int sum, int value) {
        if (value % 3 == 0 || value % 5 == 0) {
            sum += value;
        }
        return sum;    
    });
    std::cout << iResult << std::endl;
    return 0;
}
