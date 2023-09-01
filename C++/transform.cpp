#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
	std::vector<int> vec = { 4, 7, 8, 9, 10, 11 };
	std::vector<int> vec2;
	std::transform(vec.begin(), vec.end(),
                   std::back_inserter(vec2),
                   [](int x) {return x%2 ==0 ? x:0;});
	for (auto i : vec2)
		std::cout << i << std::endl;
	return 0;
}