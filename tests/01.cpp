#include "WordsGraph.hpp"
#include "catch.hpp"

SCENARIO("Test 01")
{
    GIVEN("2 input files and the correct answers")
    {
        std::string file1 = "../tests/01_1.dat";
        std::string file2 = "../tests/01_2.dat";

        std::list<std::string> answer1 = {"sage", "sale", "pale", "pall", "poll", "pool", "fool"};
        std::list<std::string> answer2 = {"sage", "page", "pale", "pall", "poll", "pool", "fool"};
        std::list<std::string> answer3 = {"sage", "sale", "pale", "pole", "poll", "pool", "fool"};
        std::list<std::string> answer4 = {"sage", "page", "pale", "pole", "poll", "pool", "fool"};

        WHEN("build words graph and words ladder")
        {
            WordsGraph graph;
            graph.buildGraph(file1, file2);
            graph.buildWordsLadder();
            graph.writeLadderInFile("../tests/01.ans");
            auto res = graph.getLadder();

            THEN("result and the correct answer must be equal")
            {
                REQUIRE((res == answer1 || res == answer2 || res == answer3 || res == answer4));
            }
        }
    }
}