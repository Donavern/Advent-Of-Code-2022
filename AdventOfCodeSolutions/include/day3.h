enum class day3Info 
{
};

int calculateDay3(std::string& first,std::string& second, std::string& third,
	std::map<char,int>& uniqueMap, std::map<char,int>& priorities)
{
	//Add unique letters from first string to the set only once
	for (char c : first)
	{
		if (uniqueMap.find(c) == uniqueMap.end())
		{
			uniqueMap.emplace(std::pair<char,int>(c,1));
		}
	}

	//Add unique letters from second string to the set only once
	for (char c : second)
	{
		if (uniqueMap.find(c) != uniqueMap.end() && uniqueMap.find(c)->second == 1)
		{
			uniqueMap.find(c)->second = 2;
		}
	}

	for (char c : third)
	{
		if (uniqueMap.find(c) != uniqueMap.end() && uniqueMap.find(c)->second == 2)
		{
			uniqueMap.find(c)->second = 3;
		}
	}

	//find the only char that has 3
	char c = std::max_element(uniqueMap.begin(), uniqueMap.end(),
		[](const std::pair<char, int>& lhs, const std::pair<char, int>& rhs) {
			return lhs.second < rhs.second; })->first;

	uniqueMap.clear();
	return priorities.find(c)->second;
}

void day3()
{
	//Open file
	std::fstream input;
	input.open("data/day3.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::map<char, int> priorities;
	int priorityValue{0};

	for (char c = 'a'; c < 'z' + 1; ++c)
	{
		priorities.emplace(std::pair<char,int>(c, ++priorityValue));
	}

	for (char c = 'A'; c < 'Z' + 1; ++c)
	{
		priorities.emplace(std::pair<char, int>(c, ++priorityValue));
	}

	std::string line{};
	std::string firstBag{}, secondBag{}, thirdBag{};
	std::map<char,int> uniqueMap;
	int prioritySum{};
	int patternCounter{0};

	//Main code
	while (std::getline(input,line))
	{
		std::istringstream iss(line);
		++patternCounter;

		if (patternCounter == 1)
		{
			firstBag = iss.str();
		}
		else if (patternCounter == 2)
		{
			secondBag = iss.str();
		}
		else if (patternCounter == 3)
		{
			thirdBag = iss.str();

			prioritySum+=calculateDay3(firstBag, secondBag,thirdBag,
				uniqueMap, priorities);

			patternCounter = 0;
		}
	}

	std::cout << "Total sum: " << prioritySum << "\n";
}