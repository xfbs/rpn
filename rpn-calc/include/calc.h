#pragma once
#include <string>
#include <deque>

class Command {
    public:
        virtual void execute(std::deque<double> &stack) = 0;
        virtual ~Command() {}
        static Command *parse(std::string tok);
};

class Number: public Command {
    public:
        Number(double num);
        void execute(std::deque<double> &state);

    private:
        double number;
};

class Add: public Command {
    public:
        Add();
        void execute(std::deque<double> &state);
};

class Mul: public Command {
    public:
        Mul();
        void execute(std::deque<double> &state);
};

class Sub: public Command {
    public:
        Sub();
        void execute(std::deque<double> &state);
};

class Div: public Command {
    public:
        Div();
        void execute(std::deque<double> &state);
};
