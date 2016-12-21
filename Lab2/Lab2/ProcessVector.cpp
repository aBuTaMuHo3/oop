#include "stdafx.h"
void ProcessVector(std::vector<double> &numbers)
{
	auto min = min_element(numbers.begin(), numbers.end());
	auto max = max_element(numbers.begin(), numbers.end());
	auto IsNegative = [](double number) {return number < 0; };
	auto mult = *min**max;
	for (auto &number : numbers)
	{
		number = (IsNegative(number)) ? number * mult : number;
	}
}