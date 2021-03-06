#include "WordsGraph.hpp"
#include "catch.hpp"

SCENARIO("Test 06")
{
    GIVEN("2 input files and the correct answer")
    {
        std::string file1 = "../tests/06_1.dat";
        std::string file2 = "../tests/06_2.dat";

        std::list<std::wstring> answer = {L"123e", L"e23e"};

        WHEN("build words ladder")
        {
            WordsGraph graph;
            graph.buildGraph(file1, file2);
            graph.buildWordsLadder();
            graph.writeLadderInFile("../tests/06.ans");
            auto res = graph.getLadder();

            THEN("result and the correct answer must be equal")
            {
                REQUIRE(res == answer);
            }
        }
    }
}