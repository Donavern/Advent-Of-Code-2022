enum class day22Info
{
};

void calculateDay22()
{
}

void day22()
{
	//Open file
	std::fstream input;
	input.open("data/day22.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}