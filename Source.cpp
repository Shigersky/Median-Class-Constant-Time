#include <iostream>
#include <set>

class Median
{
	
	std::set <int> Numbers;

	std::set<int> ::iterator it = Numbers.end();

public:

	void Insert(int num)
	{
	
		if (Numbers.end() == Numbers.find(num))
		{
			Numbers.insert(num);

			if (Numbers.size() == 1)
				it = Numbers.begin();

			else if (Numbers.size() % 2 != 0)
			{

				std::advance(it, 1);
			}
		}
	}

	void Delete(int num)
	{
		if (Numbers.end() != Numbers.find(num))
		{

		
			if (Numbers.size() % 2 != 0)
				std::advance(it, -1);

			Numbers.erase(num);

		}
	}

	int FindMedian()
	{
		if (it != Numbers.end())
			return *it;
		
		return -1;
	}
};


int main()
{
	Median test;

	/*for (size_t i = 0; i < 23; i++)
	{

	test.Insert(i);

	} */

	test.Insert(11);

	test.Delete(11);

	std::cout << test.FindMedian();
	return 0;
}