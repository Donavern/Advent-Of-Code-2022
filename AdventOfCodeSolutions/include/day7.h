enum class day7Info
{
};

void calculateDay7()
{
}

void day7()
{
	//Open file
	std::fstream input;
	input.open("data/day7.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};

	//Main code
	while (std::getline(input, line))
	{
	}
	std::cout << ": " << "" << "\n";
}