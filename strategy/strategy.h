#ifndef _STRATEGY_H_
#define _STRATEGY_H_


namespace model{
   /***************************************************************************
    * name: strategy algorithm
description : define a family of algorithms, encapculate each one, and make them interchangeable. Strategy lets the algorithm vary independently from cliens that use it.
   ***************************************************************************/
    class Strategy{
        public:
            ~Strategy();
            virtual void AlgorithmInterface() = 0;
        protected:
            Strategy();
    };


    class ConcreteStrategyA : public Strategy {
        public:
            ConcreteStrategyA();
            ~ConcreteStrategyA();
            virtual void AlgorithmInterface();
    };

    class ConcreteStrategyB : public Strategy{
        public:
            ConcreteStrategyB();
            ~ConcreteStrategyB();

            virtual void AlgorithmInterface();
    };
    

    /*
     * define the context class
     * this distinguishes the strategy algorithm from template.
     * strategy algorithm through the combine of this class and the 
     * class before to change the behavior, but the template use the 
     * inheritance to change the behavior.
     */

    class Context{
        public:
            Context(Strategy *);
            ~Context();
            void doAction();
        private:
            Strategy* _strategy;
    };

}
#endif
