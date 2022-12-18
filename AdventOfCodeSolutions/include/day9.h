enum class cellState
{
};

class cellInfo
{
	bool traversedByTails{};
};

int calculateDay9Part1(bool* data, int widthORheight)
{
	int result{};

	for (int i{}; i < widthORheight*widthORheight; ++i)
	{
		if (data[i] == true)
		{
			++result;
		}
	}
	return result+1; //For the starting
}

void day9()
{
	//Open file
	std::fstream input;
	input.open("data/day9.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{}, type{}, value{};
	std::vector<std::pair<std::string, int>> instructions;
	bool* data{};

	//Main code
	while (std::getline(input, line))
	{
		//Get instructions
		type = line.substr(0, line.find_first_of(" "));
		value = line.substr(line.find_first_of(" ")+1);
		instructions.emplace_back(std::pair<std::string,int>(type,std::stoi(value)));
	}
	input.close();

	//More setup
	int currHeadPosX{}, currHeadPosY{}, currTailPosX{ currHeadPosX }, currTailPosY{ currHeadPosY };
	int prevHeadPosX{}, prevHeadPosY{};
	std::set<std::pair<int, int>> tailLocations;

	//Start moving
	for (size_t i{}; i < instructions.size();++i)
	{
		for (int counter{}; counter < instructions[i].second; ++counter)
		{
			prevHeadPosX = currHeadPosX;
			prevHeadPosY = currHeadPosY;

			switch (instructions[i].first[0])
			{
			case 'L':
				--currHeadPosX;
				break;
			case 'R':
				++currHeadPosX;
				break;
			case 'U':
				++currHeadPosY;
				break;
			case 'D':
				--currHeadPosY;
				break;
			}

			//Check if need to move
			if (std::abs(currHeadPosX - currTailPosX) == 2 || std::abs(currHeadPosY - currTailPosY) == 2)//Check if too far
			{
				currTailPosX = prevHeadPosX;
				currTailPosY = prevHeadPosY;
				tailLocations.insert(std::make_pair(currTailPosX, currTailPosY));
			}
		}
	}

	std::cout << "Part 1: " << tailLocations.size()+1<< "\n";
	std::cout << "Part 2: " << "" << "\n";
}