enum class day8Info
{
};

void calculateDay8()
{
}

void day8()
{
	//Open file
	std::fstream input;
	input.open("data/day8.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}