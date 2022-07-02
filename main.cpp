#include <fstream> // std::ifstream, std::ofstream
#include <iostream> // std::cout, std::cin
#include <string> // std::string
#include <algorithm> // std::find
#include "config.cpp" // change, endings, diphtongs

bool contains(std::set<std::string> set, std::string element)
{
    return set.find(element) != set.end();
}

bool before_vowel(std::string word, std::string x)
{
    for(int len = 2; len >= 0; --len)
    {
        if(word.length() >= word.find(x) + x.length() + len)
        {
            return contains(vowels, word.substr(word.find(x) + x.length(), len));
        }
    }
}

void replace_endings(std::string& word, std::string x, std::string y)
{
    std::size_t pos = word.length() - x.length();
    if(word.find(x) == pos && pos != std::string::npos)
    {
        word.replace(pos, x.length(), y);
    }
}

void replace(std::string& word, std::string x, std::string y)
{
    std::size_t pos = word.find(x);
    while(pos != std::string::npos)
    {
        word.replace(pos, x.length(), y);
        pos = word.find(x);
    }
}

void open(std::ifstream& file, std::string filename)
{
    file.open(filename);
    while(!file.is_open())
    {
        std::cout << "Could not open the file " << filename
        << "\nEnter the correct filename: ";
        std::cin >> filename;
        file.open(filename);
    }
}

std::string dengu(std::string word)
{
    std::string x, y;
    for(auto it = change.begin(); it != change.end(); ++it)
    {
        x = it->first;
        y = it->second;
        if(contains(endings, x))
        {
            replace_endings(word, x, y);
        }
        else if(!(contains(diphtongs, x) && before_vowel(word, x)))
        {
            replace(word, x, y);
        }
    }
    return word;
}

int main(int argc, char *argv[])
{
    const std::string home = std::getenv("HOME");
    const std::string dir = "/prog/cpp/dengu/pie";
    const std::string in = (argc > 1) ? argv[1] : home + dir;
    const std::string out = (argc > 2) ? argv[2] : in.substr(in.rfind("/") + 1, std::string::npos) + "_dengu";
    const std::string mark = (argc > 3) ? argv[3] : "*";
    const std::string del = (argc > 4) ? argv[4] : " —";
    const int mark_len = mark.length();
    std::ifstream input;
    std::ofstream output;
    open(input, in);
    output.open(out);
    std::string line, word;
    std::size_t begin, end;
    while(std::getline(input, line))
    {
        begin = line.find(mark);
        while(begin != std::string::npos)
        {
            line.erase(begin, mark_len);
            end = line.find(del, begin) - begin;
            word = line.substr(begin, end);
            line.replace(begin, word.length(), dengu(word) + " (" + word + ")");
            begin = line.find(mark);
        }
        output << line << std::endl;
    }
    input.close();
    output.close();
    return 0;
}
