#include "WordsGraph.hpp"
#include "catch.hpp"

SCENARIO("Test 03")
{
    GIVEN("2 input files and the correct answer")
    {
        std::string file1 = "../tests/03_1.dat";
        std::string file2 = "../tests/03_2.dat";

        std::list<std::wstring> answer = {L"01234", L"51234", L"56234", L"56734", L"56784", L"56789"};

        WHEN("build words ladder")
        {
            WordsGraph graph;
            graph.buildGraph(file1, file2);
            graph.buildWordsLadder();
            graph.writeLadderInFile("../tests/03.ans");
            auto res = graph.getLadder();

            THEN("result and the correct answer must be equal")
            {
                REQUIRE(res == answer);
            }
        }
    }
}