#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
	std::vector<int>v = { 1,2,3,2, 5, 9, 8 , 6,2, 10 };
	int _count = std::count(v.begin(), v.end(), 2);
	std::cout << _count << std::endl;
	int _count_if = std::count_if(v.begin(), v.end(), [](int x) {return x % 9 == 0; });
	std::cout << _count_if;
	return 0;
}