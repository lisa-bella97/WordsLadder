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
    const std::list<std::wstring>& getLadder() const noexcept;
    const std::unordered_map<std::wstring, std::forward_list<std::wstring>>& getAdjList() const noexcept;
    std::wstring getStartWord() const noexcept;
    std::wstring getEndWord() const noexcept;
    void writeLadderInFile(const std::string& file) const noexcept;

private:
    typedef std::pair<std::wstring, int> PriorValue;
    typedef std::unordered_map<std::wstring, std::unordered_set<std::wstring>> WBucketsType;

    class Comparator
    {
    public:
        bool operator()(const PriorValue& fst, const PriorValue& scnd);
    };

    std::unordered_map<std::wstring, std::forward_list<std::wstring>> adjList_; // adjacency list of the graph
    std::wstring startWord_;
    std::wstring endWord_;
    std::list<std::wstring> wordsLadder_;

    WBucketsType getWordsBuckets(const std::string& startAndEndWordsFile, const std::string& wordsFile);
    void addEdge(const std::wstring& v1, const std::wstring& v2) noexcept;
};

#endif