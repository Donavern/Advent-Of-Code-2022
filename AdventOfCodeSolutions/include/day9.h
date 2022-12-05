enum class day9Info
{
};

void calculateDay9()
{
}

void day9()
{
	//Open file
	std::fstream input;
	input.open("data/day9.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}