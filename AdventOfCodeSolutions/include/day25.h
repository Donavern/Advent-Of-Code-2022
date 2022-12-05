enum class day25Info
{
};

void calculateDay25()
{
}

void day25()
{
	//Open file
	std::fstream input;
	input.open("data/day25.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}