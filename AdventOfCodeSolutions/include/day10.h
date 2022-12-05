enum class day10Info
{
};

void calculateDay10()
{
}

void day10()
{
	//Open file
	std::fstream input;
	input.open("data/day10.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}