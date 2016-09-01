#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n;
    int sum = 0;
    std::vector<int> input;
    std::cin >> n;
    for (int a = n, t; a-- > 0; ) {
        std::cin >> t;
        sum += t;
        input.push_back(t);
    }
    std::cin >> n;
    sum /= n;
    for (int s = sum; s > 0 && input.size() > 0; s--) {
        auto it1 = std::find(input.begin(), input.end(), s);
        if (it1 != input.end()) {
            if (sum != s) {
                auto it2 = std::find(input.begin(), input.end(), sum - s);
                if (it2 != input.end()) {
                    input.erase(it1);
                    input.erase(it2);
                    n--;
                }
            } else {
                input.erase(it1);
                n--;
            }
        }
    }
    std::cout << (n == 0? "True": "False") << std::endl;
    return 0;
}

