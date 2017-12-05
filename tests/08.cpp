#include "WordsGraph.hpp"
#include "catch.hpp"

SCENARIO("Test 08")
{
    GIVEN("1 input file and the correct answer")
    {
        std::string file = "../tests/08.dat";

        std::list<std::wstring> answer = {L"dog", L"dog"};

        WHEN("build words ladder")
        {
            WordsGraph graph;
            graph.buildGraph(file, "../sources/words.txt");
            graph.buildWordsLadder();
            graph.writeLadderInFile("../tests/08.ans");
            auto res = graph.getLadder();

            THEN("result and the correct answer must be equal")
            {
                REQUIRE(res == answer);
            }
        }
    }
}