#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

struct char_container {
	char digit;
	int count;
};

int count_char_of_string(std::string str, char c);

int main()
{
	std::string target_str;

	std::cin >> target_str;

	std::set<char> set;

	std::for_each(target_str.begin(), target_str.end(), [](char & c) {
        c = ::toupper(c);
    });

	for (int i = 0; i < target_str.length(); i++)
	{
		set.insert(target_str.at(i));
	}


	std::vector<char_container> cc;
	int max_num = 0;
	for (auto iter = set.begin(); iter != set.end(); iter++)
	{
		int count = count_char_of_string(target_str, *iter);
		char_container temp = {*iter, count};
		cc.push_back(temp);

		if (count > max_num)
		{
			max_num = count;
		}
	}

	int max_num_count = 0;
	for (auto iter = cc.begin(); iter != cc.end(); iter++)
	{
		if ((*iter).count == max_num)
		{
			max_num_count += 1;
		}
	}

	if (max_num_count == 1)
	{
		auto iter = std::find_if(cc.begin(), cc.end(), [max_num](const char_container& data) -> bool {
				return max_num == data.count;
				});
		
		std::cout << (*iter).digit << std::endl;
	}
	else
	{
		std::cout << "?" << std::endl;
	}

	return 0;
}

int count_char_of_string(std::string str, char c) {
	int count = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) == c)
		{
			count++;
		}
	}

	return count;
}
