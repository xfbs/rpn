#pragma once
#include <deque>
#include <string>

class Node {
    public:
        virtual void to_rpn(std::deque<std::string> &out) = 0;
        virtual ~Node() {};
        static Node *parse(std::deque<std::string> &tokens);

    private:
        static Node *parse_paren(std::deque<std::string> &tokens);
        static Node *parse_exp(std::deque<std::string> &tokens);
        static Node *parse_muldiv(std::deque<std::string> &tokens);
        static Node *parse_addsub(std::deque<std::string> &tokens);
        static Node *parse_literal(std::deque<std::string> &tokens);
};

class Add : public Node {
    public:
        Add(Node *lhs, Node *rhs);
        ~Add();
        virtual void to_rpn(std::deque<std::string> &out);

    private:
        Node *lhs;
        Node *rhs;
};

class Sub : public Node {
    public:
        Sub(Node *lhs, Node *rhs);
        ~Sub();
        virtual void to_rpn(std::deque<std::string> &out);

    private:
        Node *lhs;
        Node *rhs;
};

class Exp : public Node {
    public:
        Exp(Node *lhs, Node *rhs);
        ~Exp();
        virtual void to_rpn(std::deque<std::string> &out);

    private:
        Node *lhs;
        Node *rhs;
};

class Mul : public Node {
    public:
        Mul(Node *lhs, Node *rhs);
        ~Mul();
        virtual void to_rpn(std::deque<std::string> &out);

    private:
        Node *lhs;
        Node *rhs;
};

class Div : public Node {
    public:
        Div(Node *lhs, Node *rhs);
        ~Div();
        virtual void to_rpn(std::deque<std::string> &out);

    private:
        Node *lhs;
        Node *rhs;
};

class Lit : public Node {
    public:
        Lit(double num);
        virtual void to_rpn(std::deque<std::string> &out);

    private:
        double number;
};
