#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

typedef struct __CIRCLE__ {
    int Num;
    float X;
    float Y;
    float Radius;
} Circle;

int main(void)
{
    std::vector<std::tuple<int, int> > Result;
    std::vector<Circle> Input;
    int sum = 0;
    int n;
    std::cin >> n;
    for (int a = n; a-- > 0; ) {
        Circle c;
        std::cin >> c.Num >> c.X >> c.Y >> c.Radius;
        Input.push_back(c);
    }
    std::sort(Input.begin(), Input.end(), [](Circle &c1, Circle &c2) {
        return (c1.Num < c2.Num);
    });
    for (auto& c1: Input) {
        for (auto& c2: Input) {
            if (c1.Num < c2.Num) {
                if (std::sqrt(std::pow(c1.X - c2.X, 2) + std::pow(c1.Y - c2.Y, 2)) < c1.Radius + c2.Radius) {
                    Result.push_back(std::make_tuple(c1.Num, c2.Num));
                }
            }
        }
    }
    for (auto& r: Result) {
        std::cout << std::get<0>(r) << " " << std::get<1>(r) << std::endl;
    }
    return 0;
}
