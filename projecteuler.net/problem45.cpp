#include <iostream>

template <typename T, typename F = T(*)(T)>
struct factor {
    T index, value;
    F calc;
    factor(F _calc) : calc(_calc), index(0), value(0) { next(); }
    virtual void next() { value = calc(++index); }
    bool operator<(const factor & rhs) { return value < rhs.value; }
};

template <typename T>
inline T & min_ref(T & t, T & f, T & s) {
    return (t < f ? (t < s ? t : (f < s ? f : s)) : (f < s ? f : (t < s ? t : s)));
};

int main() {
    for (factor<uint64_t> t{ [](uint64_t n) { return n * (n + 1) / 2; } },
        f{ [](uint64_t n) { return n * (n * 3 - 1) / 2; } },
        s{ [](uint64_t n) { return n * (n * 2 - 1); } }; 1;) {
        if (t.value != f.value || f.value != s.value) {
            min_ref(t, f, s).next();
        }
        else {
            std::cout << 'T' << t.index << " = P" << f.index << " = H" << s.index << " = " << f.value << '\n';
            t.next();
            f.next();
            s.next();
        }
    }
    return 0;
}
