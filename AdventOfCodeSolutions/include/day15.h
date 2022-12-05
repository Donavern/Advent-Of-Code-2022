enum class day15Info
{
};

void calculateDay15()
{
}

void day15()
{
	//Open file
	std::fstream input;
	input.open("data/day15.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}