#include "WordsGraph.hpp"
#include "catch.hpp"

SCENARIO("Test 01")
{
    GIVEN("2 input files and the correct answers")
    {
        std::string file1 = "../tests/01_1.dat";
        std::string file2 = "../tests/01_2.dat";

        std::list<std::wstring> answer1 = {L"sage", L"sale", L"pale", L"pall", L"poll", L"pool", L"fool"};
        std::list<std::wstring> answer2 = {L"sage", L"page", L"pale", L"pall", L"poll", L"pool", L"fool"};
        std::list<std::wstring> answer3 = {L"sage", L"sale", L"pale", L"pole", L"poll", L"pool", L"fool"};
        std::list<std::wstring> answer4 = {L"sage", L"page", L"pale", L"pole", L"poll", L"pool", L"fool"};

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