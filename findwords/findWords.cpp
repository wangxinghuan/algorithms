#include "findWords.h"
#include <iostream>
#include <sstream>
#include <vector>

int FindWord::countWords(std::string &str)
{
    std::string word;
    std::stringstream line;
    int count = 0;
    line << str;
    while(line >> word)
    {
        count++;
    }

    return count;
}


void FindWord::printLongestWords(std::string &str)
{

    //初始化操作
    if( 0 == str.size())
    {
        return;
    }

    std::string word;
    std::stringstream line;
    std::vector<std::string> longestWords;
    int length = 0;

    line << str;
    while(line >> word)
    {
        //除去输入中的标点符号
        std::string::size_type pos = word.find_last_of(std::string(",:"));
        if( pos != std::string::npos)
        {
            word.erase(pos);
        }

        int word_size = word.size();

        if(word_size > length)
        {
            length = word_size;
            longestWords.clear();
            longestWords.push_back(word);
        }
        else if(word_size == length)
        {
            longestWords.push_back(word);
        }
    }

    for(std::vector<std::string>::iterator it = longestWords.begin(); it != longestWords.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}


void FindWord::printSmallestWords(std::string &str)
{

    //初始化操作
    if( 0 == str.size())
    {
        return;
    }

    std::string word;
    std::stringstream line;
    std::vector<std::string> smallestWords;
    int length = 0;

    line << str;

    line >> word;
    //消除符号对单词的影响
    std::string::size_type pos = word.find_last_of(std::string(",:"));
    if( pos != std::string::npos)
    {
        word.erase(pos);
    }

    length = word.size();
    smallestWords.push_back(word);

    while(line >> word)
    {
        std::string::size_type pos = word.find_last_of(std::string(",:"));
        if( pos != std::string::npos)
        {
            word.erase(pos);
        }

        int word_size = word.size();

        if(word_size < length)
        {
            length = word_size;
            smallestWords.clear();
            smallestWords.push_back(word);
        }
        else if(word_size == length)
        {
            smallestWords.push_back(word);
        }
    }

    for(std::vector<std::string>::iterator it = smallestWords.begin(); it != smallestWords.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}
