#include <fstream>
#include "WordsGraph.hpp"
#include "catch.hpp"

SCENARIO("Test 05")
{
    GIVEN("2 input files and the correct answer")
    {
        std::string file1 = "../tests/05_1.dat";
        std::string file2 = "../tests/05_2.dat";
        std::string answer = "Cannot build a ladder of words";

        WHEN("build words ladder")
        {
            WordsGraph graph;
            graph.buildGraph(file1, file2);
            graph.buildWordsLadder();
            graph.writeLadderInFile("../tests/05.ans");
            std::ifstream ifs("../tests/05.ans");
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