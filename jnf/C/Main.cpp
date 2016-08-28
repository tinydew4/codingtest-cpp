#include <climits>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

typedef std::tuple<int, int> location;
typedef std::vector<location> locations;
typedef std::tuple<locations, float> output;

void trace(locations path)
{
	int i = 0;
	for (auto& loc: path) {
		if (i++) {
			std::cout << " -> ";
		}
		std::cout << "(" << std::get<0>(loc) << "," << std::get<1>(loc) << ")";
	}
	std::cout << std::endl;
}

output eval(locations input, locations path = locations{std::make_tuple(0, 0)}, float length = 0)
{
	if (input.size() <= 0) {
		return std::make_tuple(path, length);
	}

	auto get_length = [](location a, location b) -> float {
		return std::sqrt(std::pow(std::get<0>(a) - std::get<0>(b), 2) + std::pow(std::get<1>(a) - std::get<1>(b), 2));
	};
	output result(std::make_tuple(locations(), std::numeric_limits<int>::max()));
	for (int i = 0, a = input.size(); a-- > 0; i++) {
		locations sub_input = input;
		locations sub_path = path;
		float sub_length = length + get_length(sub_path.back(), sub_input[i]);
		sub_path.push_back(sub_input[i]);
		sub_input.erase(sub_input.begin() + i);

		output sub_result = eval(sub_input, sub_path, sub_length);
		if (std::get<1>(result) > std::get<1>(sub_result)) {
			result = sub_result;
		}
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	locations input;
	int count;
	int x, y;
	std::cin >> count;
	for (int a = count; a-- > 0; input.push_back(std::make_tuple(x, y))) {
		std::cin >> x >> y;
	}
    input.push_back(std::make_tuple(10, 10));
	output output = eval(input);
	trace(std::get<0>(output));
	return 0;
}
