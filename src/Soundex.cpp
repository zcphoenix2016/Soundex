#include "Soundex.hpp"
#include <algorithm>
#include <stdexcept>

const map<char, char> Soundex::m_encodeTab = {
    {'a', '0'}, {'e', '0'}, {'i', '0'}, {'o', '0'}, {'u', '0'}, {'y', '0'},
    {'h', '7'}, {'w', '7'},
    {'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
    {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'}, {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
    {'d', '3'}, {'t', '3'},
    {'l', '4'},
    {'m', '5'}, {'n', '5'},
    {'r', '6'}
    };

string Soundex::encode(const string& p_name)
{
    if (p_name.empty())
    {
        throw invalid_argument("Empty string !");
    }

    string l_result = p_name;
    toLower(l_result);    
    
    convertToNumbers(l_result);
    removeSpecialLetters(l_result);
    removeSameNumbers(l_result);
    removeVowelLetters(l_result);

    l_result.resize(4,'0');

    return l_result;
}

void Soundex::convertToNumbers(string & p_result)
{
    try 
    {
        transform(p_result.begin() + 1, p_result.end(), p_result.begin() + 1, [](unsigned char c){return m_encodeTab.at(c);});
    }
    catch (out_of_range)
    {
        throw invalid_argument("Invalid letter !");
    }
}

void Soundex::toLower(string & p_result)
{
    transform(p_result.begin(), p_result.end(), p_result.begin(), [](unsigned char c) { return tolower(c); });
}

void Soundex::removeSameNumbers(string & p_result)
{    
    p_result.erase(std::unique(p_result.begin() + 1, p_result.end()), p_result.end());
    removeTheSameNumWithFirst(p_result);
}

void Soundex::removeTheSameNumWithFirst(string & p_result)
{
    try
    {
        if(1 < p_result.length())
        {
            if(m_encodeTab.at(p_result.at(0)) == p_result.at(1))
            {
                p_result.erase(1, 1);
            }
        }
    }
    catch(out_of_range)
    {
        throw invalid_argument("Invalid letter !");
    }
}

void Soundex::removeVowelLetters(string & p_result)
{
    p_result.erase(std::remove(p_result.begin() + 1, p_result.end(), '0'), p_result.end());
}

void Soundex::removeSpecialLetters(string& p_result)
{
    p_result.erase(std::remove(p_result.begin() + 1, p_result.end(), '7'), p_result.end());
}
