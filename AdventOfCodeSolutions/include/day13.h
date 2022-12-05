enum class day13Info
{
};

void calculateDay13()
{
}

void day13()
{
	//Open file
	std::fstream input;
	input.open("data/day13.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}