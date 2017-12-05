#include "WordsGraph.hpp"
#include "catch.hpp"

SCENARIO("Test 07")
{
    GIVEN("2 input files and the correct answer")
    {
        std::string file1 = "../tests/07_1.dat";
        std::string file2 = "../tests/07_2.dat";

        std::list<std::wstring> answer = {L"кот", L"кит", L"гит", L"гик", L"пик"};

        WHEN("build words ladder")
        {
            WordsGraph graph;
            graph.buildGraph(file1, file2);
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