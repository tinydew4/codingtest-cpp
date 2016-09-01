#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::cin >> input;
    std::string::size_type nPosT = 0;
    std::string::size_type nPosM = 0;
    bool bMatched = true;
    std::string match[] = {"MM", "TT"};
    for (int a = 2; a-- > 0 && bMatched; ) {
        bMatched = false;
        for (std::string::size_type nPos = 0;
            (nPos = input.find(match[a])) != std::string::npos;
            input.erase(nPos, 2), bMatched = true);
    }
    return 0;
}

