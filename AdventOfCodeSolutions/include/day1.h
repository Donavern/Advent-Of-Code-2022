void calculateDay1(std::vector<int>& currentElfBag, std::vector<int>& maxTotalCalories)
{
	int currentTotal{};

	//Add total
	for (size_t i{}; i < currentElfBag.size(); ++i)
	{
		currentTotal += currentElfBag[i];
	}

	//Replace next biggest
	std::sort(maxTotalCalories.begin(), maxTotalCalories.end());

	for (size_t i{}; i < maxTotalCalories.size(); ++i)
	{
		if (currentTotal > maxTotalCalories[i])
		{
			maxTotalCalories[i] = currentTotal;
			break;
		}
	}
	currentElfBag.clear();
}

void day1()
{
	std::fstream input;
	input.open("data/day1.txt", std::fstream::in);

	assertm(input.is_open() == true,"Failed to open file");
	
	std::vector<int> currentElfBag(100);
	std::vector<int> maxTotalCalories(3);
	std::string line{};

	while (std::getline(input,line))
	{
		std::istringstream iss(line);
		
		//If new line
		if (std::strcmp("", iss.str().c_str())==0)
		{
			calculateDay1(currentElfBag,maxTotalCalories);
		}
		else
		{
			currentElfBag.emplace_back(std::stoi(iss.str()));
		}
	}

	calculateDay1(currentElfBag,maxTotalCalories);

	std::cout << "Total calories held by top 3 elves are " << maxTotalCalories[0]+maxTotalCalories[1]+maxTotalCalories[2] << "\n";
}