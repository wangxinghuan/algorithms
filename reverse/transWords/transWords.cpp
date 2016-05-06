/*
 * FileName: transWords.cpp
 * Copyright (C) 2014-08-13 15:23 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include <iostream> 
#include <map>
#include <stdexcept>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ifstream& open_file(ifstream &in, const string &file){
    in.close();
    in.clear();
    in.open(file.c_str());

    return in;
}


int main(int argc, const char *argv[])
{
    if(3 != argc){
        throw runtime_error("wrong number of arguments");
    }
    //读取第一个用于转换的文件

    map<string, string> transMap;

    ifstream mapFile;

    if(!open_file(mapFile, argv[1])){
        throw runtime_error("conversion file invalid");
    }

    string key, value;

    while(mapFile >> key >> value){
        transMap.insert(make_pair(key, value));
    }

    //读取第二个用于转换的文件

    ifstream inputFile;

    if(!open_file(inputFile, argv[2])){
        throw runtime_error("input file invaid");
    }

    string line;

    while(getline(inputFile, line)){
        istringstream ss(line);
        string word;

        bool firstWord = true;

        while(ss >> word){
            //map<string, string>::iterator end = transMap.end();
            // if(((map<string, string>::iterator end4) = transMap.end()) != end);
            map<string, string>::iterator it = transMap.find(word);

            if(it != transMap.end()){
                cout << it->second;
            }else{
                cout << word;
            }

            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
