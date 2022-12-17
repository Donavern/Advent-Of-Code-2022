enum class EntryType
{
	file = 0,
	directory = 1
};

class Entry
{
public:
	Entry() {};
	Entry(std::string s) { dirName=s; type = EntryType::directory; };
	Entry(std::string s, int i) { fileName=s; fileSize=i; type = EntryType::file; };

	EntryType type;

	//file
	std::string fileName{};
	int fileSize{};

	//Directory
	std::vector<Entry> files;
	std::string dirName{};
	float directoryTotalSize{};
};

//Start from system, find the dir
Entry* findDirectory(Entry& currentEntry, std::string& name)
{
	if (std::strcmp(currentEntry.dirName.c_str(), name.c_str()) == 0)
	{
		return &currentEntry;
	}

	for (Entry& e : currentEntry.files)
	{
		Entry* tempEntry = findDirectory(e, name);

		if (tempEntry)
			return tempEntry;
	}

	return nullptr;
}

//Start from system, find the dir before given dir
Entry* findDirectoryBefore(Entry& currentEntry, std::string& name)
{
	//This means we want to dir to root
	if (std::strcmp(currentEntry.dirName.c_str(), name.c_str()) == 0)
	{
		return &currentEntry;
	}

	for (Entry& e : currentEntry.files)
	{
		if (std::strcmp(e.dirName.c_str(), name.c_str()) == 0)
		{
			return &currentEntry;
		}
	}

	for (Entry& e : currentEntry.files)
	{
		Entry* tempEntry = findDirectoryBefore(e, name);
		if (tempEntry)
			return tempEntry;
	}

	return nullptr;
}

void printEverything(Entry& currentEntry, int currentLevel)
{
	for (int levelCounter{}; levelCounter < currentLevel; ++levelCounter)
	{
		std::cout << "\t";
	}

	if (currentEntry.type == EntryType::directory)
	{
		std::cout << "-" << currentEntry.dirName << " (dir, size=" << currentEntry.directoryTotalSize << ")" << "\n";
	}
	else
	{
		std::cout << "-" << currentEntry.fileName << " (file, size=" << currentEntry.fileSize << ")" << "\n";
	}

	for (size_t counter{}; counter < currentEntry.files.size(); ++counter)
	{
		printEverything(currentEntry.files[counter], currentLevel+1);
	}
}

void calculateDay7Part1(Entry& entry,int& sum, int givenMaxValue)
{
	if (entry.type == EntryType::directory)
	{
		if(entry.directoryTotalSize<= givenMaxValue)
			sum += static_cast<int>(entry.directoryTotalSize);
	}

	for (size_t counter{}; counter < entry.files.size(); ++counter)
	{
		calculateDay7Part1(entry.files[counter], sum, givenMaxValue);
	}
}

void day7()
{
	//Open file
	std::fstream input;
	input.open("data/day7.txt", std::fstream::in);

	assertm(input.is_open() == true, "Failed to open file");

	//Setup
	std::string line{};
	float currentDirDepth{};

	Entry system("/");
	Entry* currentDir{ &system };

	//Main code
	while (std::getline(input, line))
	{
		if (line.find("$ cd ..") != std::string::npos)	//Move out 1 level
		{
			currentDir = findDirectoryBefore(system, currentDir->dirName);
		}
		else if (line.find("$ cd /") != std::string::npos) //Switch to outermost dir
		{
			currentDir = &system;
		}
		else if (line.find("$ cd ") != std::string::npos) //Move in 1 level
		{
			std::string dirToMoveTo = line.substr(line.find("$ cd ") + 5);

			//Find dir to search in
			Entry* foundDir = findDirectory(system, currentDir->dirName);

			//Find dir to move to within this dir
			for (size_t i{}; i < foundDir->files.size(); ++i)
			{
				if (std::strcmp(foundDir->files[i].dirName.c_str(), dirToMoveTo.c_str()) == 0)
				{
					currentDir = &foundDir->files[i];
					break;
				}
			}
		}
		else if (line.find("$ ls") != std::string::npos) //Print out files/dir
		{
		}
		else if (line.find("dir ") != std::string::npos) //current dir contains this folder
		{
			std::string dirToAdd = line.substr(line.find("dir ") + 4);

			//Just incase
			if (currentDir != nullptr)
			{
				currentDir->files.emplace_back(Entry(dirToAdd));
			}
		}
		else if (line.find_first_of("0123456789") != std::string::npos) //current dir contains this file
		{
			std::string size{}, name{};
			size = line.substr(0, line.find_first_of(" "));
			name = line.substr(line.find_first_of(" ")+1);

			if (currentDir != nullptr)
			{
				currentDir->files.emplace_back(Entry(name,std::stoi(size)));
				currentDir->directoryTotalSize += std::stoi(size);

				Entry* tempDir{ currentDir };
				while (tempDir != &system)
				{
					tempDir = findDirectoryBefore(system, tempDir->dirName);
					if (tempDir == nullptr)
						break;
					tempDir->directoryTotalSize += std::stoi(size);
				}
			}
		}
	}
	
	printEverything(system, 0);

	int totalSum{};
	calculateDay7Part1(system, totalSum, 100000);
	std::cout << "Total Sum Part 1: " << totalSum << "\n";
}