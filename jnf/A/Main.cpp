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

 int _tmain(int argc, _TCHAR* argv[])
{
	int weight['z'] = {0};
	std::string input;
	std::cin >> input;
	for (auto& c: input) {
		weight[c]++;
	}
	std::sort(input.begin(), input.end(), [weight](char a, char b) {
		return (weight[b] > weight[a] || (weight[b] == weight[a] && a < b));
	});
	std::cout << input << std::endl;
	return 0;
}
