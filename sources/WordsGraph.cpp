#include "WordsGraph.hpp"

#include <fstream>
#include <iostream>
#include <queue>

unsigned int heuristic(const std::string& v1, const std::string& v2);

void WordsGraph::buildGraph(const std::string& file1, const std::string& file2)
{
    std::ifstream fs1(file1);

    if (!fs1)
        throw std::invalid_argument("Cannot open the file " + file1);

    if (!(fs1 >> startWord_))
        throw std::invalid_argument("Incorrect start word in file " + file1);

    auto len = startWord_.length();

    if (!(fs1 >> endWord_) || endWord_.length() != len)
        throw std::invalid_argument("Incorrect end word in file " + file1 + " (the length of the start word must be equal to the length of the end word).");

    fs1.close();

    std::ifstream fs2(file2);

    if (!fs2)
        throw std::invalid_argument("Cannot open the file " + file2);

    std::string word;
    std::unordered_map<std::string, std::unordered_set<std::string>> dict;

    for (size_t i = 0; i < len; ++i) // add startWord_ and endWord_ in the dict
    {
        auto bucket = startWord_.substr(0, i) + '_' + startWord_.substr(i + 1, len - i - 1);
        if (dict.find(bucket) == dict.end())
            dict[bucket] = std::unordered_set<std::string>();
        dict[bucket].insert(startWord_);

        bucket = endWord_.substr(0, i) + '_' + endWord_.substr(i + 1, len - i - 1);
        if (dict.find(bucket) == dict.end())
            dict[bucket] = std::unordered_set<std::string>();
        dict[bucket].insert(endWord_);
    }

    while (fs2 >> word)
    {
        if (word == startWord_ || word == endWord_) continue;

        if (word.length() == len)
        {
            for (size_t i = 0; i < len; ++i)
            {
                auto bucket = word.substr(0, i) + '_' + word.substr(i + 1, len - i - 1);

                if (dict.find(bucket) == dict.end())
                    dict[bucket] = std::unordered_set<std::string>();

                dict[bucket].insert(word);
            }
        }
    }

    fs2.close();

    for (const auto& key : dict)
        for (const auto& word1 : dict[key.first])
            for (const auto& word2 : dict[key.first])
                if (word1 != word2)
                    addEdge(word1, word2);
}

void WordsGraph::buildWordsLadder() noexcept
{
    wordsLadder_ = std::list<std::string>();
    auto queue = std::priority_queue<PriorValue, std::vector<PriorValue>, Comparator>();
    queue.push(PriorValue(startWord_, 0));
    auto cameFrom = std::unordered_map<std::string, std::string>();
    auto costTo = std::unordered_map<std::string, unsigned int>();
    cameFrom[startWord_] = "";
    costTo[startWord_] = 0;

    while (!queue.empty())
    {
        auto current = queue.top();
        queue.pop();

        if (current.getValue() == endWord_)
            break;

        for (const auto& next : adjList_.at(current.getValue()))
        {
            auto new_cost = costTo[current.getValue()] + 1;
            if (costTo.find(next) == costTo.end() || new_cost < costTo[next])
            {
                costTo[next] = new_cost;
                queue.push(PriorValue(next, new_cost + heuristic(next, endWord_)));
                cameFrom[next] = current.getValue();
            }
        }
    }

    wordsLadder_.push_front(endWord_);
    auto word = cameFrom[endWord_];
    while (!word.empty())
    {
        wordsLadder_.push_front(word);
        word = cameFrom[word];
    }
    if (wordsLadder_.front() != startWord_)
        wordsLadder_.push_front(startWord_);
}

const std::list<std::string>& WordsGraph::getLadder() const noexcept
{
    return wordsLadder_;
}

std::string WordsGraph::getStartWord() const noexcept
{
    return startWord_;
}

std::string WordsGraph::getEndWord() const noexcept
{
    return endWord_;
}

void WordsGraph::writeLadderInFile(const std::string& file) const noexcept
{
    std::ofstream ofs(file);

    if (wordsLadder_.size() <= 2)
        ofs << "Cannot build a ladder of words";
    else
        for (const auto& w : wordsLadder_)
            ofs << w << std::endl;

    ofs.close();
}

WordsGraph::PriorValue::PriorValue(const std::string &value, int priority) : value_(value), priority_(priority) {}

const std::string& WordsGraph::PriorValue::getValue() const noexcept
{
    return value_;
}

int WordsGraph::PriorValue::getPriority() const noexcept
{
    return priority_;
}

bool WordsGraph::Comparator::operator()(WordsGraph::PriorValue fst, WordsGraph::PriorValue scnd)
{
    return fst.getPriority() > scnd.getPriority();
}

void WordsGraph::addEdge(const std::string& v1, const std::string& v2) noexcept
{
    if (adjList_.find(v1) == adjList_.end())
        adjList_[v1] = std::unordered_set<std::string>();

    adjList_[v1].insert(v2);

    if (adjList_.find(v2) == adjList_.end())
        adjList_[v2] = std::unordered_set<std::string>();

    adjList_[v2].insert(v1);
}

unsigned int heuristic(const std::string& v1, const std::string& v2)
{
    unsigned int res = 0;

    for (auto i = 0; i < v1.length(); ++i)
        if (v1[i] != v2[i])
            ++res;

    return res;
}