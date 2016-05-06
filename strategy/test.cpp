#define __TEST__

#ifdef __TEST__
#include "strategy.h"
#include<iostream>


using namespace std;
using namespace model;
extern int selector;
void printSelector(){
switch(selector){
        case 0 : cout << "concreteStrategy A interface" << endl;
                 break;
        case 1:
                 cout << "concreteStrategy B interface" << endl;
                 break;
        default:
                 cout << "^_^!!" << endl;
    }

}

void test(){
    Strategy * ptrA = new ConcreteStrategyA();
    Strategy * ptrB = new ConcreteStrategyB();

    Context * pco = new Context(ptrA);

    pco->doAction();

    printSelector();

    pco = new Context(ptrB);

    pco->doAction();

    printSelector();
        
}

#endif


int 
main(int argc, const char *argv[])
{
    test();
    return 0;
}
