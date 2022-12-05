enum class day2Info 
{
	Arock = 1,
	Bpaper = 2,
	Cscissors = 3,
	Xrock = 1,
	Ypaper = 2,
	Zscissors = 3,

	lose = 0,
	draw = 3,
	win = 6
};

int calculateDay2(char theirs, char resultState)
{
	int theirValue{}, myValue{};
	
	switch (theirs)
	{
	case 'A':
		theirValue = static_cast<int>(day2Info::Arock);
		break;
	case 'B':
		theirValue = static_cast<int>(day2Info::Bpaper);
		break;
	case 'C':
		theirValue = static_cast<int>(day2Info::Cscissors);
		break;
	}

	if (resultState == 'X') //Need to lose
	{
		if (theirValue == static_cast<int>(day2Info::Arock))
			myValue = theirValue + 2 + static_cast<int>(day2Info::lose);
		else
			myValue = theirValue - 1 + static_cast<int>(day2Info::lose);
	}
	else if (resultState == 'Y') //Need to draw
	{
		myValue = theirValue + static_cast<int>(day2Info::draw);
	}
	else //Need to win
	{
		if (theirValue == static_cast<int>(day2Info::Cscissors))
			myValue = theirValue - 2 + static_cast<int>(day2Info::win);
		else
			myValue = theirValue + 1 + static_cast<int>(day2Info::win);
	}

	return myValue;
}

void day2()
{
	//Open file
	std::fstream input;
	input.open("data/day2.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	int totalScore{};
	char theirPick{}, myPick{};

	//Main Code
	while (input >> theirPick >> myPick)
	{
		totalScore += calculateDay2(theirPick,myPick);
	}

	std::cout << "Total score: " << totalScore << "\n";
}