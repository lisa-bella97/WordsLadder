#include <iostream>
#include <fstream>
#include "WordsGraph.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2 && argc != 3)
    {
        std::cerr << "Wrong number of command arguments.\n";
        return 0;
    }

    WordsGraph g;

    try
    {
        if (argc == 2)
            g.buildGraph(argv[1], "../sources/words.txt");
        else
            g.buildGraph(argv[1], argv[2]);
    }
    catch(const std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
        g.writeLadderInFile("../ladder.txt");
        return 0;
    }

    g.buildWordsLadder();
    g.writeLadderInFile("../ladder.txt");
    return 0;
}