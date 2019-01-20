# SearchWordsInDirs (C++, g++ complier)
## This is small program works with print all the files that contain a list of words, the words do not need to appear in any particular order, but they must be complete words

### Build g++:
```g++ -o program main.cpp DirectoryFinder.cpp```
### Run:
```program "search text" ./path/to/directory```

#### If [path to directory] ommited, program works on current directory
#### Example with current directory:
```program "search text" ./```
#### Or
```program "search text"```

## Note: Din to subdirectories also