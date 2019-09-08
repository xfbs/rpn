#include "parse.h"

Node *Node::parse(std::deque<std::string> &tokens) {
}

Node *Node::parse_paren(std::deque<std::string> &tokens) {
}

Node *Node::parse_exp(std::deque<std::string> &tokens) {
}

Node *Node::parse_muldiv(std::deque<std::string> &tokens) {
}

Node *Node::parse_addsub(std::deque<std::string> &tokens) {
}

Node *Node::parse_literal(std::deque<std::string> &tokens) {
}

Add::Add(Node *lhs, Node *rhs) : lhs(lhs), rhs(rhs) {
}

std::deque<std::string> Add::to_rpn() {
}

Mul::Mul(Node *lhs, Node *rhs) : lhs(lhs), rhs(rhs) {
}

std::deque<std::string> Mul::to_rpn() {
}
