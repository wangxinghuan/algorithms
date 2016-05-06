#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Solution{
	public:
		int reverse(int x){

			stringstream ss;
			string strTemp;
			string str;
			string symbol;

			//judge the number symbol

			ss << x;
			ss >> strTemp;

			if ( '+' == strTemp[0] || '-' == strTemp[0] ){
				symbol = strTemp[0];
			}

			strTemp.clear();
			ss.clear();

			x = abs(x);

			//reverse
			while(x != 0){

				ss << ( x % 10);
				ss >> strTemp;
				str+= strTemp;

				ss.clear();
				strTemp.clear();
				x = x / 10;
			}


			str = symbol + str;
			ss << str;
			ss >> x;

			return x;
		}
};


int main()
{

	Solution s;

	cout << s.reverse(-123) << endl;


}
