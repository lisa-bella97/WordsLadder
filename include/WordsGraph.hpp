#ifndef WORDS_GRAPH_HPP
#define WORDS_GRAPH_HPP

#include <unordered_map>
#include <unordered_set>
#include <list>
#include <string>

class WordsGraph
{
public:
    void buildGraph(const std::string& startAndEndWordsFile, const std::string& wordsFile);
    void buildWordsLadder() noexcept;
    const std::list<std::string>& getLadder() const noexcept;
    std::string getStartWord() const noexcept;
    std::string getEndWord() const noexcept;
    void writeLadderInFile(const std::string& file) const noexcept;

private:
    class PriorValue
    {
    public:
        PriorValue(const std::string& value, int priority);
        const std::string& getValue() const noexcept;
        int getPriority() const noexcept;

    private:
        std::string value_;
        int priority_;
    };

    class Comparator
    {
    public:
        bool operator()(PriorValue fst, PriorValue scnd);
    };

    std::unordered_map<std::string, std::unordered_set<std::string>> adjList_; // adjacency list of the graph
    std::string startWord_;
    std::string endWord_;
    std::list<std::string> wordsLadder_;

    void addEdge(const std::string& v1, const std::string& v2) noexcept;
};

#endif