enum class day4Info
{
};

int calculateDay4(int firstRangeLeft, int firstRangeRight, int secondRangeLeft, int secondRangeRight)
{
	if ((firstRangeLeft >= secondRangeLeft && firstRangeRight <= secondRangeRight) ||
		(secondRangeLeft >= firstRangeLeft && secondRangeRight <= firstRangeRight))
	{
		return 1;
	}
	return 0;
}

void day4()
{
	//Open file
	std::fstream input;
	input.open("data/day4.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	int firstRangeLeft{}, firstRangeRight{}, secondRangeLeft{}, secondRangeRight{};
	size_t currentPos{}, prevPos{};
	int totalFullOverlap{};
	std::string line{};

	//Main code
	while (std::getline(input,line))
	{
		//Get data
		currentPos = line.find_first_of('-');
		firstRangeLeft = std::stoi(line.substr(0, currentPos));
		prevPos = currentPos;

		currentPos = line.find_first_of(',');
		firstRangeRight = std::stoi(line.substr(prevPos+1, currentPos));
		prevPos = currentPos;

		currentPos = line.find_last_of('-');
		secondRangeLeft = std::stoi(line.substr(prevPos+1, currentPos-prevPos));
		prevPos = currentPos;

		secondRangeRight = std::stoi(line.substr(currentPos+1));

		totalFullOverlap+= calculateDay4(firstRangeLeft, firstRangeRight, secondRangeLeft, secondRangeRight);
	}

	std::cout << "Total full overlapping ranges: " << totalFullOverlap << "\n";
}