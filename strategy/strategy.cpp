#include "strategy.h"

int selector = 1000;
namespace model{
    Strategy :: Strategy(){

    }

    Strategy :: ~Strategy(){

    }

    ConcreteStrategyA :: ConcreteStrategyA(){

    }

    ConcreteStrategyA :: ~ConcreteStrategyA(){

    }

    void ConcreteStrategyA :: AlgorithmInterface(){
       selector = 0; 

    }


    ConcreteStrategyB :: ConcreteStrategyB(){

    }

    ConcreteStrategyB :: ~ConcreteStrategyB(){

    }

    void ConcreteStrategyB :: AlgorithmInterface(){


        selector = 1;

    }


    Context :: Context(Strategy * strategy){
        this->_strategy = strategy;
    }

    Context :: ~Context(){
        delete this->_strategy;
    }

    void Context :: doAction(){
        this->_strategy->AlgorithmInterface();
    }
}
