#include <iostream>
#include "findWords.h"

using namespace std;

int main()
{
    FindWord fd;

    string line1 = "We were her pride of 10 she named us:";
    string line2 = "Benjamin, Phoenix, the Prodigal";
    string line3 = "and perspicacious pacific Suzanne";
    string sentence = line1 + ' ' + line2 + ' ' +line3;


    cout << "words number is:" << fd.countWords(sentence) << endl;

    cout << "the longest word is: " << endl;
    fd.printLongestWords(sentence);

    cout << "the smallest word is: " << endl;

    fd.printSmallestWords(sentence);

    return 0;
}
