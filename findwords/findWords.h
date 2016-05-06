#ifndef FINDWORDS_H_INCLUDED
#define FINDWORDS_H_INCLUDED

#include <string>

class FindWord
{
public:
    int countWords(std::string &str);
    void printLongestWords(std::string  &str);
    void printSmallestWords(std::string &str);
};
#endif // FINDWORDS_H_INCLUDED
