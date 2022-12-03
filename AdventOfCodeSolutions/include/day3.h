enum class day3Info 
{
};

int calculateDay3(std::string& first,std::string& second, 
	std::set<char>& firstMap,std::set<char>& secondMap,
	std::map<char,int>& priorities)
{
	//Add all left side letters first
	for (char c : first)
	{
		firstMap.insert(c);
	}

	//Find the first letter in right side that exists in left
	for (char c : second)
	{
		//Found existing
		if (firstMap.count(c) != 0)
		{
			return priorities.find(c)->second;
		}
	}
	return 0;
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

	//Init data
	std::string line{};
	std::string firstCompartment{}, secondCompartment{};
	std::set<char> firstCompartmentLetters, secondCompartmentLetters;
	int prioritySum{};

	//Main code
	while (std::getline(input,line))
	{
		std::istringstream iss(line);
		int lengthOfString = iss.str().length();
		firstCompartment = iss.str().substr(0, lengthOfString / 2);
		secondCompartment = iss.str().substr(lengthOfString / 2);

		prioritySum+=calculateDay3(firstCompartment, secondCompartment,
			firstCompartmentLetters, secondCompartmentLetters, priorities);

		firstCompartmentLetters.clear();
		secondCompartmentLetters.clear();
	}

	std::cout << "Total sum: " << prioritySum << "\n";
}