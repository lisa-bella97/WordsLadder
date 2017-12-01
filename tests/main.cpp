#include <iostream>
#include "WordsGraph.hpp"

void test(const std::string& inpFile1, const std::string& inpFile2, const std::string& outpFile);
void test(const std::string& inpFile, const std::string& outpFile);

int main(int argc, char* argv[])
{
    test("../tests/01_1.dat", "../tests/01_2.dat", "../tests/01.ans");
    test("../tests/02_1.dat", "../tests/02_2.dat", "../tests/02.ans");
    test("../tests/03_1.dat", "../tests/03_2.dat", "../tests/03.ans");
    test("../tests/04_1.dat", "../tests/04_2.dat", "../tests/04.ans");
    test("../tests/05_1.dat", "../tests/05_2.dat", "../tests/05.ans");
    test("../tests/06_1.dat", "../tests/06_2.dat", "../tests/06.ans");
    test("../tests/07.dat", "../tests/07.ans");
    test("../tests/08.dat", "../tests/08.ans");
    test("../tests/09.dat", "../tests/09.ans");
    test("../tests/10.dat", "../tests/10.ans");
    
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

void test(const std::string& inpFile, const std::string& outpFile)
{
    test(inpFile, "../sources/words.txt", outpFile);
}