enum class day18Info
{
};

void calculateDay18()
{
}

void day18()
{
	//Open file
	std::fstream input;
	input.open("data/day18.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}