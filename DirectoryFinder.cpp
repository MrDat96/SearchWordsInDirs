#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>

#include "DirectoryFinder.h"

void DirectoryFinder::search() {
    listFilesRecursively(m_directory, true);
}

bool DirectoryFinder::isValidChar(char c) {
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

bool DirectoryFinder::checkWordsFound(bool* checkList, int length) {
    for (int i = 0; i < length; i++) {
        if (!checkList[i])
            return false;
    }
    return true;
}

void DirectoryFinder::searchInFile(std::string file_path) {
    std::ifstream ifs(file_path);
    if (!ifs) {
        return;
    }

    char c;
    std::string word = "";
    bool checkList[m_words.size()]{};
    while (true) {
        bool check = static_cast<bool>(ifs.get(c));
        if (c == ' ' || c == '\n' || !check || !isValidChar(c)) {
            for (int i = 0; i < m_words.size(); i++) {
                if (word == m_words[i]) {
                    checkList[i] = true;
                    break;
                }
            }
            if (checkWordsFound(checkList, m_words.size())) {
                std::cout << "Found: " << file_path << "\n";
                break;
            }
            word = "";
        }
        else {
            word += c;
        }
        if (!check)
            break;
    }
    ifs.close();
}

void DirectoryFinder::listFilesRecursively(std::string basePath, bool isRoot = false) {
    struct dirent* dp;
    DIR* dir = opendir(basePath.c_str());

    if (!dir) {
        if (isRoot) {
            std::cerr << "Cannot reach directory \"" << basePath << "\"\n";
        }
        else {
            searchInFile(basePath);
        }
        return;
    }

    while ((dp = readdir(dir)) != NULL) {
        std::string path = dp->d_name;
        if (path != "." && path != "..") {
            if (basePath != "." && basePath != "./")
                path = basePath + "/" + path;
            listFilesRecursively(path);
        }
    }
    closedir(dir);
}
