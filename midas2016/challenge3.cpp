#include <iostream>
#include <map>

int factorization(std::map<int, int>& counter, int value)
{
    int m = 1;
    for (int i = 2; value > 1; i++) {
        for (; value % i == 0; counter[m = i]++, value /= i);
    }
    return m;
}
int main()
{
    int n;
    std::cin >> n;
    std::map<int, int> count;
    int m = 1;
    for (int i = 2, a = n - i + 1; a-- > 0; i++) {
        n = factorization(count, i);
        m = (m < n? n: m);
    }
    for (int i = 2, a = m + 1 - i;
        a-- > 0;
        (count[i] > 0) && (std::cout << i << "^" << count[i] << (a > 0? "*": "\n")), i++);
    return 0;
}
