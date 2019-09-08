#include "parse.h"

Node *Node::parse(std::deque<std::string> &tokens) {
    return parse_addsub(tokens);
}

Node *Node::parse_paren(std::deque<std::string> &tokens) {
    if(tokens.front() == "(") {
        tokens.pop_front();
        Node *cur = parse_addsub(tokens);
        // closing paren (check?)
        tokens.pop_front();

        return cur;
    } else {
        return parse_literal(tokens);
    }
}

Node *Node::parse_exp(std::deque<std::string> &tokens) {
    Node *cur = parse_paren(tokens);

    if(tokens.size() && tokens.front() == "^") {
        tokens.pop_front();
        return new Exp(cur, parse_paren(tokens));
    }

    return cur;
}

Node *Node::parse_muldiv(std::deque<std::string> &tokens) {
    Node *cur = parse_exp(tokens);

    if(tokens.size()) {
        if(tokens.front() == "*") {
            tokens.pop_front();
            return new Mul(cur, parse_muldiv(tokens));
        } else if(tokens.front() == "/") {
            tokens.pop_front();
            return new Div(cur, parse_muldiv(tokens));
        }
    }

    return cur;
}

Node *Node::parse_addsub(std::deque<std::string> &tokens) {
    Node *cur = parse_muldiv(tokens);

    if(tokens.size()) {
        if(tokens.front() == "+") {
            tokens.pop_front();
            return new Add(cur, parse_addsub(tokens));
        } else if(tokens.front() == "-") {
            tokens.pop_front();
            return new Sub(cur, parse_addsub(tokens));
        }
    }

    return cur;
}

Node *Node::parse_literal(std::deque<std::string> &tokens) {
    double num = std::stod(tokens.front());
    tokens.pop_front();
    return new Lit(num);
}

Add::Add(Node *lhs, Node *rhs) : lhs(lhs), rhs(rhs) {
}

Add::~Add() {
    delete lhs;
    delete rhs;
}

Sub::Sub(Node *lhs, Node *rhs) : lhs(lhs), rhs(rhs) {
}

Sub::~Sub() {
    delete lhs;
    delete rhs;
}

Exp::Exp(Node *lhs, Node *rhs) : lhs(lhs), rhs(rhs) {
}

Exp::~Exp() {
    delete lhs;
    delete rhs;
}

Mul::Mul(Node *lhs, Node *rhs) : lhs(lhs), rhs(rhs) {
}

Mul::~Mul() {
    delete lhs;
    delete rhs;
}

Div::Div(Node *lhs, Node *rhs) : lhs(lhs), rhs(rhs) {
}

Div::~Div() {
    delete lhs;
    delete rhs;
}

Lit::Lit(double num) : number(num) {
}

void Lit::to_rpn(std::deque<std::string> &out) {
    out.push_back(std::to_string(number));
}

void Add::to_rpn(std::deque<std::string> &out) {
    lhs->to_rpn(out);
    rhs->to_rpn(out);
    out.push_back("+");
}

void Sub::to_rpn(std::deque<std::string> &out) {
    lhs->to_rpn(out);
    rhs->to_rpn(out);
    out.push_back("-");
}

void Mul::to_rpn(std::deque<std::string> &out) {
    lhs->to_rpn(out);
    rhs->to_rpn(out);
    out.push_back("*");
}

void Div::to_rpn(std::deque<std::string> &out) {
    lhs->to_rpn(out);
    rhs->to_rpn(out);
    out.push_back("/");
}

void Exp::to_rpn(std::deque<std::string> &out) {
    lhs->to_rpn(out);
    rhs->to_rpn(out);
    out.push_back("^");
}

