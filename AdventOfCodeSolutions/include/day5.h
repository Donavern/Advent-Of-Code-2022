enum class day5Info
{
};

void calculateDay5(std::vector<std::stack<char>>& stacks,int count,int from, int to)
{
	std::vector<char> tempStorage;

	for (int times{}; times < count; ++times)
	{
		tempStorage.emplace_back(stacks[from - 1].top());
		stacks[from - 1].pop();
	}

	for (int itemCounter{ static_cast<int>(tempStorage.size()) - 1 }; itemCounter >= 0; --itemCounter)
	{
		stacks[to - 1].push(tempStorage[itemCounter]);
	}
}

void day5()
{
	//Open file
	std::fstream input;
	input.open("data/day5.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};
	std::vector<std::stack<char>> stacks;
	std::vector<std::vector<char>> vectors;
	bool containersCreated{}, dataAdded{},dataSorted{};

	//Main code
	while (std::getline(input, line))
	{
		//Find the line that shows me how many stacks there are
		if (line.find_first_of("0123456789") != std::string::npos && containersCreated == false)
		{
			std::string token{};
			size_t pos{};

			//For each stack number, add a container
			while ((pos = line.find(" ")) != std::string::npos) 
			{
				token = line.substr(0, pos);

				if (token != "")
				{
					stacks.emplace_back(std::stack<char>());
					vectors.emplace_back(std::vector<char>());
				}

				line.erase(0, pos + 1);
			}

			//Rewind to start of file
			input.clear();
			input.seekg(0);
			containersCreated = true;
		}

		if (containersCreated)
		{
			//Still receiving data
			if (line.find_first_of("[]") != std::string::npos)
			{
				size_t spaceCounter{};

				for (char c : line)
				{
					++spaceCounter;
					if( c >='A' && c <='Z')
					{
						vectors[spaceCounter / 4].emplace_back(c);
					}
				}
				dataAdded = true;
			}
			else if (dataAdded && dataSorted == false)
			{
				for (size_t i{}; i < vectors.size(); ++i)
				{
					for (int v{static_cast<int>(vectors[i].size())-1}; v >= 0; --v)
					{
						stacks[i].push(vectors[i][v]);
					}
				}
				dataSorted = true;
			}
			else if (line.find("move") != std::string::npos) //Start moving
			{
				int count{}, from{}, to{};

				std::string token{};
				size_t pos{};

				//For each stack number, add a container
				while ((pos = line.find(" ")) != std::string::npos)
				{
					token = line.substr(0, pos);

					if (token.find_first_of("123456789")!=std::string::npos)
					{
						if (count == 0)
						{
							count = std::stoi(token);
						}
						else if (from == 0)
						{
							from = std::stoi(token);
						}
					}

					line.erase(0, pos + 1);
				}

				to = std::stoi(line);

				calculateDay5(stacks, count, from, to);
			}
		}
	}
	
	std::string result{};
	for (size_t s{}; s < stacks.size(); ++s)
	{
		result += stacks[s].top();
	}
	std::cout << "Top of Range: " << result << "\n";
}