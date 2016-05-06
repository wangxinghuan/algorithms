#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
		public:
				void reverseWords(string &s) {
						stringstream ss(s);
						string word;

						s.clear();

						ss >> word;
						s = word;

						while(ss >> word){
								if ( word == " "){
										word = "";
										continue;
								}

								s = word + " " + s;
						}
				}
};

int main(){
		Solution s;
		string str = " a h       ii           ";

		s.reverseWords(str);
		cout << str << "---------------" << endl;
}
