enum class day12Info
{
};

void calculateDay12()
{
}

void day12()
{
	//Open file
	std::fstream input;
	input.open("data/day12.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}