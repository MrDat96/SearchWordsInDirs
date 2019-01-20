#ifndef DIRECTORY_FINDER_H
#define DIRECTORY_FINDER_H
#include <string>
#include <vector>
#include <algorithm>

class DirectoryFinder {
private:
    std::string m_directory;
    std::vector<std::string> m_words;

public:
    DirectoryFinder(std::string wordsString, std::string directory = "./")
        : m_directory(directory)
    {
        splitStringToWords(wordsString);
    }

    void splitStringToWords(std::string wordsString) {
        wordsString += "\n";
        std::string word = "";
        for (char c : wordsString) {
            if (c == ' ' || c == '\n' || c == '\0') {
                if (word != "" && std::find(m_words.begin(), m_words.end(), word) == m_words.end()) {
                    m_words.push_back(word);
                }
                word = "";
            }
            else {
                word += c;
            }
        }
    }

    bool isValidChar(char c);

    void search();

    void listFilesRecursively(std::string basePath, bool isRoot);

    void searchInFile(std::string path);

    bool checkWordsFound(bool* checkList, int length);
};
#endif // IRECTORY_FINDER_H
