#include <fstream> // std::ifstream, std::ofstream
#include <string> // std::string
#include <algorithm> // std::find
#include "config.cpp" // change, endings, diphtongs

bool contains(std::set<std::string> set, std::string element)
{
    return set.find(element) != set.end();
}

bool before_vowel(std::string word, std::string x)
{
    return contains(vowels, word.substr(word.find(x)+x.length(), 1)) ||
           contains(vowels, word.substr(word.find(x)+x.length(), 2));
}

void replace(std::string& word, std::string x, std::string y)
{
    int pos = word.find(x);
    if(contains(diphtongs, x) && before_vowel(word, x))
    {
        return;
    }
    if(contains(endings, x))
    {
        pos = word.length() - x.length();
        if(word.find(x) == pos && pos != std::string::npos)
        {
            word.replace(pos, x.length(), y);
        }
        return;
    }
    while(pos != std::string::npos)
    {
        word.replace(pos, x.length(), y);
        pos = word.find(x);
    }
}

std::string dengu(std::string word)
{
    for(auto it = change.begin(); it != change.end(); ++it)
    {
        replace(word, it->first, it->second);
    }
    return word;
}

int main()
{
    std::ifstream dic;
    std::ofstream out;
    std::string line, word;
    std::size_t begin, end;
    dic.open("swadesh");
    out.open("out");
    while(std::getline(dic, line))
    {
        begin = line.find("*");
        while(begin != std::string::npos)
        {
            line.erase(begin, 1);
            end = line.find(" ", begin) - begin;
            word = line.substr(begin, end);
            word = word.substr(0, word.find(","));
            line.replace(begin, word.length(), dengu(word) + " (" + word + ")");
            begin = line.find("*");
        }
        out << line << std::endl;
    }
    dic.close();
    out.close();
    return 0;
}
