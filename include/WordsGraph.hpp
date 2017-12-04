#ifndef WORDS_GRAPH_HPP
#define WORDS_GRAPH_HPP

#include <unordered_map>
#include <list>
#include <forward_list>
#include <unordered_set>
#include <string>

class WordsGraph
{
public:
    void buildGraph(const std::string& startAndEndWordsFile, const std::string& wordsFile);
    void buildWordsLadder() noexcept;
    const std::list<std::string>& getLadder() const noexcept;
    const std::unordered_map<std::string, std::forward_list<std::string>>& getAdjList() const noexcept;
    std::string getStartWord() const noexcept;
    std::string getEndWord() const noexcept;
    void writeLadderInFile(const std::string& file) const noexcept;

private:
    typedef std::pair<std::string, int> PriorValue;
    typedef std::unordered_map<std::string, std::unordered_set<std::string>> WBucketsType;

    class Comparator
    {
    public:
        bool operator()(const PriorValue& fst, const PriorValue& scnd);
    };

    std::unordered_map<std::string, std::forward_list<std::string>> adjList_; // adjacency list of the graph
    std::string startWord_;
    std::string endWord_;
    std::list<std::string> wordsLadder_;

    WBucketsType getWordsBuckets(const std::string& startAndEndWordsFile, const std::string& wordsFile);
    void addEdge(const std::string& v1, const std::string& v2) noexcept;
};

#endif