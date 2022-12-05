enum class day17Info
{
};

void calculateDay17()
{
}

void day17()
{
	//Open file
	std::fstream input;
	input.open("data/day17.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}