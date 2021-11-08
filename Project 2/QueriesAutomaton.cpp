#include "QueriesAutomaton.h"
#include <iostream>
using namespace std;

void QueriesAutomaton::S0(const std::string& input) {
    string QueriesString = "Queries";
    for (int i = 0; i < 7; i++) {
        if (input[i] != QueriesString[i]) {
            Serr();
            return;
        }
    }
    inputRead = 7;
}
