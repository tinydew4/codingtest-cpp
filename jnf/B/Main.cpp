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
	std::string input;
	int length;
	int count = 0;
	std::cin >> length;
	for (int state = 0; length-- > 0; state = 0) {
		std::cin >> input;
		for (auto& c: input) {
			if (c == '.') {
				count += state;
				state = 1;
			} else {
				state = 0;
			}
		}
	}
	std::cout << count << std::endl;
	return 0;
}
