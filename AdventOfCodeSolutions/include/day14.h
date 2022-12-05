enum class day14Info
{
};

void calculateDay14()
{
}

void day14()
{
	//Open file
	std::fstream input;
	input.open("data/day14.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}