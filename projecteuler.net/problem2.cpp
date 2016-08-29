#include <iostream>

class Pibo
{
private:
    int FNumber1;
    int FNumber2;
public:
    Pibo(void)
        : FNumber1(0)
        , FNumber2(1)
    {
    }
    int Next(void)
    {
        int iResult = FNumber1 + FNumber2;
        FNumber1 = FNumber2;
        FNumber2 = iResult;
        return iResult;
    }
};

int main()
{
    Pibo p;
    int sum = 0;
    for (int i = p.Next(); i <= 4000000; i = p.Next()) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
