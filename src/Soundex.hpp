#pragma once

#include <string>
#include <map>

using namespace std;

class Soundex
{
public:
    static string encode(const string&);

private:
    static const map<char, char> m_encodeTab;
    static void convertToNumbers(string &);
    static void removeSameNumbers(string &);
    static void toLower(string &);
    static void removeTheSameNumWithFirst(string &);
    static void removeVowelLetters(string &);
    static void removeSpecialLetters(string &);
};

