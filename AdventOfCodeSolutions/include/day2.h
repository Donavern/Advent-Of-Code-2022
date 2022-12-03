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

int calculateDay2(char theirs, char mine)
{
	int theirValue{}, myValue{}, resultState{};
	
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

	switch (mine)
	{
	case 'X':
		myValue = static_cast<int>(day2Info::Xrock);
		break;
	case 'Y':
		myValue = static_cast<int>(day2Info::Ypaper);
		break;
	case 'Z':
		myValue = static_cast<int>(day2Info::Zscissors);
		break;
	}

	int difference = myValue - theirValue;

	if (difference ==0) //Draw
	{
		resultState = static_cast<int>(day2Info::draw);
	}
	else if (difference == 1 || difference == -2)
	{
		resultState = static_cast<int>(day2Info::win);
	}
	else
	{
		resultState = static_cast<int>(day2Info::lose);
	}

	return myValue + resultState;
}

void day2()
{
	std::fstream input;
	input.open("data/day2.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	int totalScore{};
	char theirPick{}, myPick{};

	while (input >> theirPick >> myPick)
	{
		totalScore += calculateDay2(theirPick,myPick);
	}

	std::cout << "Total score: " << totalScore << "\n";
}