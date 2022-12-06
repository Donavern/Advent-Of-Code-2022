enum class day6Info
{
};

void calculateDay6()
{
}

void day6()
{
	//Open file
	std::fstream input;
	input.open("data/day6.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");
	std::set<char> storage;

	//Setup
	char c{};
	int charCounter{}, uniqueCounter{};

	//Main code
	while (!input.eof())
	{
		input >> c;
		++charCounter;

		if (storage.count(c) == 0)
		{
			storage.emplace(c);
			++uniqueCounter;
		}
		else
		{
			input.clear();
			input.seekg(charCounter- uniqueCounter);

			charCounter -= uniqueCounter;
			uniqueCounter = 0;

			storage.clear();
		}

		if (uniqueCounter ==14)
		{
			break;
		}
	}

	std::cout << "Pos: " << charCounter << "\n";
}