#include <fstream>
#include "WordsGraph.hpp"
#include "catch.hpp"

SCENARIO("Test 04")
{
    GIVEN("2 input files (second of them is empty) and the correct answer")
    {
        std::string file1 = "../tests/04_1.dat";
        std::string file2 = "../tests/04_2.dat";
        std::string answer = "Cannot build a ladder of words";

        WHEN("build words ladder")
        {
            WordsGraph graph;
            graph.buildGraph(file1, file2);
            graph.buildWordsLadder();
            graph.writeLadderInFile("../tests/04.ans");
            std::ifstream ifs("../tests/04.ans");
            std::string res;
            std::getline(ifs, res);
            ifs.close();

            THEN("output file must contain the correct answer")
            {
                REQUIRE(res == answer);
            }
        }
    }
}