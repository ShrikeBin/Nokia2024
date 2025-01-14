#include <string>
#include <unordered_map>
#include <cctype>

unsigned int scrabbleScore(std::string word)
{
    unsigned int score {0};
    
    const std::unordered_map<char, int> letterValues =
    {
        {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}, {'L', 1}, {'N', 1}, {'S', 1}, {'T', 1}, {'R', 1},
        {'D', 2}, {'G', 2},
        {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
        {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
        {'K', 5},
        {'J', 8}, {'X', 8},
        {'Q', 10}, {'Z', 10},
        {' ', 0}
    };
    
    for(auto x : word)
    {
        score += letterValues.at(std::toupper(x));
    }
    
    return score;
}





