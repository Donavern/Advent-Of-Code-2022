enum class day19Info
{
};

void calculateDay19()
{
}

void day19()
{
	//Open file
	std::fstream input;
	input.open("data/day19.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}