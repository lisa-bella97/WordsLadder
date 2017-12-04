#include "WordsGraph.hpp"
#include "catch.hpp"

SCENARIO("Test 02")
{
    GIVEN("2 input files (first of them is empty)")
    {
        std::string file1 = "../tests/02_1.dat";
        std::string file2 = "../tests/02_2.dat";

        WHEN("try to build words graph")
        {
            WordsGraph graph;

            THEN("exception must be thrown")
            {
                REQUIRE_THROWS(graph.buildGraph(file1, file2));
            }
        }
    }
}