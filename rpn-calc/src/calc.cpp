#include "calc.h"

Command *Command::parse(std::string tok) {
    if(tok == "+") {
        return new Add();
    }

    if(tok == "*") {
        return new Mul();
    }

    if(tok == "-") {
        return new Sub();
    }

    if(tok == "/") {
        return new Div();
    }

    return new Number(std::stod(tok));
}

Number::Number(double num) : number(num) {
}

void Number::execute(std::deque<double> &state) {
    state.push_back(number);
}

Add::Add() {
}

void Add::execute(std::deque<double> &state) {
    double rhs = state.back();
    state.pop_back();
    double lhs = state.back();
    state.pop_back();
    state.push_back(lhs + rhs);
}

Mul::Mul() {
}

void Mul::execute(std::deque<double> &state) {
    double rhs = state.back();
    state.pop_back();
    double lhs = state.back();
    state.pop_back();
    state.push_back(lhs * rhs);
}

Sub::Sub() {
}

void Sub::execute(std::deque<double> &state) {
    double rhs = state.back();
    state.pop_back();
    double lhs = state.back();
    state.pop_back();
    state.push_back(lhs - rhs);
}

Div::Div() {
}

void Div::execute(std::deque<double> &state) {
    double rhs = state.back();
    state.pop_back();
    double lhs = state.back();
    state.pop_back();
    state.push_back(lhs / rhs);
}
