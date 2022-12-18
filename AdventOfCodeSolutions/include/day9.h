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

	//More setup for part 2
	std::vector<std::pair<int, int>> currTailPos(9, std::pair<int,int>(currHeadPosX,currHeadPosY));
	std::set<std::pair<int, int>> tailLocationNinth;

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

			//Check if need to move - Part 1
			if (std::abs(currHeadPosX - currTailPosX) == 2 || std::abs(currHeadPosY - currTailPosY) == 2)//Check if too far
			{
				currTailPosX = prevHeadPosX;
				currTailPosY = prevHeadPosY;
				tailLocations.insert(std::make_pair(currTailPosX, currTailPosY));
			}

			std::pair<int, int> dirOfPrevTailMovement{};

			//For part 2
			for (size_t t{}; t < currTailPos.size(); ++t)
			{
				//If first tail
				if (t == 0)
				{
					//If first tail "1" is too far from head
					if (std::abs(currHeadPosX - currTailPos[t].first) == 2
						|| std::abs(currHeadPosY - currTailPos[t].second) == 2)
					{
						dirOfPrevTailMovement.first = prevHeadPosX - currTailPos[t].first;
						dirOfPrevTailMovement.second = prevHeadPosY - currTailPos[t].second;
						currTailPos[t].first = prevHeadPosX;
						currTailPos[t].second = prevHeadPosY;
					}
				}
				else
				{
					if (std::abs(currTailPos[t-1].first - currTailPos[t].first) == 2
						|| std::abs(currTailPos[t-1].second - currTailPos[t].second) == 2)
					{	
						currTailPos[t].first += dirOfPrevTailMovement.first;
						currTailPos[t].second += dirOfPrevTailMovement.second;

						if (t == currTailPos.size() - 1)
						{
							tailLocationNinth.insert(currTailPos[t]);
						}
					}
				}
			}
		}
	}

	std::cout << "Part 1: " << tailLocations.size()<< "\n";
	std::cout << "Part 2: " << tailLocationNinth.size()+1 << "\n";
}