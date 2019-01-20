#include <iostream>
#include <dirent.h>

#include "DirectoryFinder.h"

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "Please add search text!\n";
    }

    std::string searchText = argv[1];
    std::string directory;
	
	if (argc <= 2) {
		directory = "./";
	}
	else {
		directory = argv[2];
	}
    std::cout << "Directory: " << directory << "\n";

    DirectoryFinder directoryFinder(searchText, directory);
    directoryFinder.search();

    return 0;
}