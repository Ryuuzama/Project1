#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Parser.h"
#include "Interpreter.h"
using namespace std;

int main(int argc, char** argv) {
    //cout << "hello";

    vector<Token*> mainTokens;
    Lexer* lexer = new Lexer();
    DatalogProgram datalogprogramObject;


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
    //lexer->ToString();

    //cout << "Total Tokens = " << lexer->GetSize();
    mainTokens = lexer->getTokens();
    Parser parser = Parser(mainTokens);
    parser.parse();
    datalogprogramObject = parser.getDatalogProgram();
    Interpreter interpreterObject(datalogprogramObject);
    interpreterObject.Interpret();
    interpreterObject.evaluateAllQueries();




//delete lexer;

    return 0;


}