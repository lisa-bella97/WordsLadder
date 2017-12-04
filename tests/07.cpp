#include "WordsGraph.hpp"
#include "catch.hpp"

SCENARIO("Test 07")
{
    GIVEN("1 input file and the correct answer")
    {
        std::string file = "../tests/07.dat";

        std::list<std::string> answer = {"dog", "dog"};

        WHEN("build words ladder")
        {
            WordsGraph graph;
            graph.buildGraph(file, "../sources/words.txt");
            graph.buildWordsLadder();
            graph.writeLadderInFile("../tests/07.ans");
            auto res = graph.getLadder();

            THEN("result and the correct answer must be equal")
            {
                REQUIRE(res == answer);
            }
        }
    }
}