int calculateDay8Part1(int* data, int width, int height)
{
	int withinNumberCount{};
	bool visible{};

	//Check for each value
	for (int y{}; y < height; ++y)
	{
		for (int x{}; x < width; ++x)
		{
			//Start from left right up down
			int innerY{ y }, innerX{ x };

			visible = true;

			while (--innerX >= 0) //Check left
			{
				if (data[y * width + innerX] >= data[y * width + x])
				{
					visible = false;
					break;
				}
			}

			if (visible)
			{
				++withinNumberCount;
				continue;
			}

			visible = true;

			while (--innerY >= 0) //Check top
			{
				if (data[innerY * width + x] >= data[y * width + x])
				{
					visible = false;
					break;
				}
			}

			if (visible)
			{
				++withinNumberCount;
				continue;
			}

			innerY = y; innerX = x;

			visible = true;

			while (++innerX < width) //Check right
			{
				if (data[y * width + innerX] >= data[y * width + x])
				{
					visible = false;
					break;
				}
			}

			if (visible)
			{
				++withinNumberCount;
				continue;
			}

			visible = true;

			while (++innerY < height) //Check bottom
			{
				if (data[innerY * width + x] >= data[y * width + x])
				{
					visible = false;
					break;
				}
			}

			if (visible)
			{
				++withinNumberCount;
				continue;
			}
		}
	}

	return withinNumberCount ;
}

int calculateDay8Part2(int* data, int width, int height)
{
	int maxScore{}, topScore{}, leftScore{}, bottomScore{}, rightScore{};

	for (int y{}; y < height; ++y)
	{
		for (int x{}; x < width; ++x)
		{
			//Start from left right up down
			int innerY{ y }, innerX{ x };

			topScore = 0; leftScore = 0; bottomScore = 0; rightScore = 0;

			while (--innerX >= 0) //Check left
			{
				++leftScore;
				if (data[y * width + innerX] >= data[y * width + x])
				{
					break;
				}
			}

			while (--innerY >= 0) //Check top
			{
				++topScore;
				if (data[innerY * width + x] >= data[y * width + x])
				{
					break;
				}
			}

			innerY = y; innerX = x;

			while (++innerX < width) //Check right
			{
				++rightScore;
				if (data[y * width + innerX] >= data[y * width + x])
				{
					break;
				}
			}

			while (++innerY < height) //Check bottom
			{
				++bottomScore;

				if (data[innerY * width + x] >= data[y * width + x])
				{
					break;
				}
			}

			if (topScore * bottomScore * leftScore * rightScore > maxScore)
			{
				maxScore = topScore * bottomScore * leftScore * rightScore;
			}
		}
	}
	return maxScore;
}

void displayData(int* data, int width, int height)
{
	for (int y{}; y < height; ++y)
	{
		for (int x{}; x < width; ++x)
		{
			std::cout << data[y * width+x];
		}
		std::cout << "\n";
	}
}

void day8()
{
	//Open file
	std::fstream input;
	input.open("data/day8.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};
	bool firstLine{}, resetted{};

	int width{}, height{};
	int currentX{}, currentY{};
	int* data{};

	//Main code
	while (!input.eof())
	{
		std::getline(input, line);

		//Only after size is found
		if (resetted == true)
		{
			//Create container for data
			if (data == nullptr)
			{
				data = new int[height * width];
			}

			//Add in the data
			for (size_t i{}; i < line.length(); ++i)
			{
				data[currentY * width + currentX] = std::stoi(line.substr(i,1));
				++currentX;
			}

			currentX = 0;
			++currentY;
		}

		//Find size
		if (firstLine == false)
		{
			width = line.length();
			firstLine = true;
		}

		if (resetted == false)
			++height;

		if (resetted == false && input.eof())
		{
			input.clear();
			input.seekg(0);
			resetted = true;
		}
		//End finding size
	}

	//displayData(data, width, height);
	std::cout << "Visible (Part 1): " << calculateDay8Part1(data,width,height) << "\n";
	std::cout << "Max scene score (Part 2): " << calculateDay8Part2(data, width, height) << "\n";

	delete [] data;
}