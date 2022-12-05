enum class day23Info
{
};

void calculateDay23()
{
}

void day23()
{
	//Open file
	std::fstream input;
	input.open("data/day23.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}