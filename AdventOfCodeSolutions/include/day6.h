enum class day6Info
{
};

void calculateDay6()
{
}

void day6()
{
	//Open file
	std::fstream input;
	input.open("data/day6.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}