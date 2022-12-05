enum class day20Info
{
};

void calculateDay20()
{
}

void day20()
{
	//Open file
	std::fstream input;
	input.open("data/day20.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}