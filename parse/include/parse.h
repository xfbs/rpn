#pragma once
#include <deque>
#include <string>

class Node {
    public:
        virtual std::deque<std::string> to_rpn() = 0;
        virtual ~Node() {};
        Node *parse(std::deque<std::string> &tokens);

    private:
        Node *parse_paren(std::deque<std::string> &tokens);
        Node *parse_exp(std::deque<std::string> &tokens);
        Node *parse_muldiv(std::deque<std::string> &tokens);
        Node *parse_addsub(std::deque<std::string> &tokens);
        Node *parse_literal(std::deque<std::string> &tokens);
};

class Add : public Node {
    public:
        Add(Node *lhs, Node *rhs);
        virtual std::deque<std::string> to_rpn();

    private:
        Node *lhs;
        Node *rhs;
};

class Mul : public Node {
    public:
        Mul(Node *lhs, Node *rhs);
        virtual std::deque<std::string> to_rpn();

    private:
        Node *lhs;
        Node *rhs;
};
