enum class day11Info
{
};

void calculateDay11()
{
}

void day11()
{
	//Open file
	std::fstream input;
	input.open("data/day11.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}