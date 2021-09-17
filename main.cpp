#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
    //cout << "hello";

    Lexer* lexer = new Lexer();

// TODO
    ifstream in(argv[1]);
    string becomeString;
    string yeah = argv[1];
    //cout << yeah << endl;

    if (!in){
        cout << "not open man" << endl;
    }

    //char input = inFile.get();
    string input;

    while (!in.eof()) {
        string line;
        getline(in, line);
        input += line + (in.eof() ? "" : "\n"); }

    /*ostringstream oneInput;
    oneInput << in.rdbuf();
    string input = oneInput.str();
    //cout << oneInput.str();*/

    lexer->Run(input);
    lexer->ToString();
    cout << "Total Tokens = " << lexer->GetSize();

//delete lexer;

    return 0;


}