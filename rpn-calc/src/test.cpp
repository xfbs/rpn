#include "calc.h"
#include <cassert>
#include <cmath>
#include <iostream>

void test_parse();
void test_execute();

int main(int argc, char *argv[]) {
    std::deque<double> state;

    test_parse();
    test_execute();

    std::cout << "ok" << std::endl;

    return EXIT_SUCCESS;
}

template<typename T>
void assert_type(std::string str) {
    Command *cmd = Command::parse(str);

    if(dynamic_cast<T *>(cmd) == nullptr) {
        std::cout
            << "error: string '"
            << str
            << "' does not map to type "
            << typeid(T).name()
            << "."
            << std::endl;
        exit(EXIT_FAILURE);
    }

    delete cmd;
}

void assert_result(double result, size_t num, ...) {
    va_list args;
    va_start(args, num);
    std::deque<double> state;

    for(size_t pos = 0; pos < num; pos++) {
        const char *arg = va_arg(args, const char *);
        Command *cmd = Command::parse(arg);
        cmd->execute(state);
    }

    assert(state.size() == 1);
    if(std::isnan(result)) {
        assert(std::isnan(state.at(0)));
    } else {
        assert(state.at(0) == result);
    }
}

void test_parse() {
    assert_type<Add>("+");
    assert_type<Sub>("-");
    assert_type<Mul>("*");
    assert_type<Div>("/");
    assert_type<Number>("0");
    assert_type<Number>("0.5");
    assert_type<Number>("nan");
}

void test_execute() {
    assert_result(1.0, 1, "1");
    assert_result(1.5, 1, "1.5");
    assert_result(NAN, 1, "nan");
}
