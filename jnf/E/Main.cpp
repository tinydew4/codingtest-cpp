#include <algorithm>
#include <iostream>
#include <string>
#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

int eval(std::string source, std::string target)
{
	int count = 0;
	if (source.length() > 0) {
		for (auto& c: source) {
			auto finded = std::find(target.begin(), target.end(), c);
			if (finded != target.end()) {
				count += (std::distance(target.begin(), finded));
				target.erase(target.begin(), finded + 1);
			} else {
				count++;
				target.erase(0, 1);
			}
		}
	} else {
		count = target.length();
	}
	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::string input;
	std::string value = "JENNIFERSOFT";
	std::cin >> input;
	for (; input.front() == value.front(); input.erase(0, 1), value.erase(0, 1));
	for (; input.back() == value.back(); input.pop_back(), value.pop_back());
	int result[] = {eval(value, input), eval(input, value)};
	std::sort(result, result + 2, [](int a, int b) { return a < b; });
	std::cout << result[0] << std::endl;
	return 0;
}

