enum class day21Info
{
};

void calculateDay21()
{
}

void day21()
{
	//Open file
	std::fstream input;
	input.open("data/day21.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}