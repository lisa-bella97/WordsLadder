#include <iostream>
#include "WordsGraph.hpp"

void test(const std::string& inpFile1, const std::string& inpFile2, const std::string& outpFile);

int main(int argc, char* argv[])
{
    test("../examples/1_1.dat", "../examples/1_2.dat", "../examples/1.ans");

    test("../examples/3_1.dat", "../examples/3_2.dat", "../examples/3.ans");

    return 0;
}

void test(const std::string& inpFile1, const std::string& inpFile2, const std::string& outpFile)
{
    WordsGraph g;

    try
    {
        g.buildGraph(inpFile1, inpFile2);
    }
    catch(const std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
        g.writeLadderInFile(outpFile);
        return;
    }

    g.buildWordsLadder();
    g.writeLadderInFile(outpFile);
}