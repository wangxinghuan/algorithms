/*friend 
 *
 * friend 关键字用于改变类与类之间的权限访问控制
 * 声明为friend的函数或者类只是改变了该函数或者类对声明
 * 所处的类的访问控制，可以使该函数能够能够访问声明所在类的
 * 所有成员函数及成员变量。
 *
 * 目的：能够解决类之间数据共享的操作
 *
 *
 */
#include <iostream>
#include <string>

using namespace std;

class Girl;

class Boy {
    public:
        void display(Girl &);
    private:
        /* data */
};


class Girl{
    public:
        Girl(): name("girl"), age("11"){}
        friend void Boy::display(Girl &);
    private:
        string name;   
        string age;
};


int main(int argc, const char *argv[])
{
    Boy boy;
    Girl girl;

    boy.display(girl);

    return 0;
}


void Boy::display(Girl &girl){
    cout << "girl name is: " << girl.name << endl;
    cout << "girl age is: "  << girl.age << endl;
}
