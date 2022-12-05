enum class day16Info
{
};

void calculateDay16()
{
}

void day16()
{
	//Open file
	std::fstream input;
	input.open("data/day16.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}