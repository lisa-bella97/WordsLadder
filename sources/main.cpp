#include <iostream>
#include <fstream>
#include "WordsGraph.hpp"

int main(int argc, char* argv[])
{
    if (argc != 3 && argc != 4)
    {
        std::cerr << "Wrong number of command arguments.\n";
        return 0;
    }

    WordsGraph g;
    auto i = argc == 3 ? 2 : 3;

    try
    {
        if (argc == 3)
            g.buildGraph(argv[1], "../sources/words.txt");
        else
            g.buildGraph(argv[1], argv[2]);
    }
    catch(const std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 0;
    }

    g.buildWordsLadder();
    g.writeLadderInFile(argv[i]);
    return 0;
}