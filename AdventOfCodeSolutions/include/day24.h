enum class day24Info
{
};

void calculateDay24()
{
}

void day24()
{
	//Open file
	std::fstream input;
	input.open("data/day24.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}