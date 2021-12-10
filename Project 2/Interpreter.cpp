#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#include "Interpreter.h"
#include "Predicate.h"
#include "Relation.h"
#include "Database.h"
#include "Graph.h"

Interpreter::Interpreter(DatalogProgram datalogProgram) {
    newDatalogProgram = datalogProgram; //store DatalogProgram as a data member
    Relation();

}

void Interpreter::Interpret() {
        Tuple newTuple;
        vector<Predicate> schemesVector = newDatalogProgram.getSchemesVector();
        vector<Predicate> factsVector = newDatalogProgram.getFactsVector();

        for (unsigned int i =0; i < schemesVector.size(); i++) {
            newRelation.setName(schemesVector.at(i).getName());
            newHeader.setHeader(schemesVector.at(i).GetParameters());
            newRelation.setHeader(newHeader);
            for (unsigned int j = 0; j < factsVector.size(); j++) {
                if (factsVector.at(j).getName() == schemesVector.at(i).getName()) {
                    newTuple.setTuple(factsVector.at(j).getParameterStrings());
                    newRelation.addTuple(newTuple);
                    newTuple = Tuple();
                }
            }
            newDatabase.addToMap(newRelation.getName(), newRelation);
            newRelation = Relation();
        }
        //newDatabase.maptoString();

    //make a relation for each scheme-prediacte and put that relation in the database data member
    //make a tuple for each fact-predicate, and put that tuple in the appropriate relation in the database
}

Relation Interpreter::evaluatePredicate(Predicate p) {
    map<string, int> variableMap;
    vector<Predicate> queryVector = newDatalogProgram.getQueriesVector();
    Relation matchedRelation;
    vector<string> values;
    vector<int> positionVector;
    Header newHeader;
    matchedRelation = newDatabase.getFromMap(p.getName());
    for (unsigned int i =0; i < p.GetParameters().size(); i++) {
        if (p.GetParameters().at(i).isConstant()) {
            matchedRelation = matchedRelation.selectConstant(i, p.GetParameters().at(i).toString()); //if it was a constant
        }
        else {
            if (variableMap.find(p.GetParameters().at(i).toString()) != variableMap.end()) { //if i saw it in my variableMap
                int index1;
                index1 = variableMap.at(p.GetParameters().at(i).toString());
                matchedRelation = matchedRelation.selectSameValue(index1, i); //are index1 and i different?????
            }
            else { //if i'm seeing this variable for the first time.
                positionVector.push_back(i);
                variableMap[p.GetParameters().at(i).toString()] = i; //add the variable to the variable map and assign it to the index of the predicate p.
                values.push_back(p.GetParameters().at(i).toString());
            }
        }
    }
    //add all the ints from my variableMap to my position vector *****
    matchedRelation = matchedRelation.Project(positionVector);

    newHeader.setHeaderByStrings(values);
    matchedRelation.Rename(newHeader);
    return matchedRelation;
    //project, pass in indices that correspond with the variables you're working with.
    //loop through the parameters of query
    //for each attribute name, rename
}

void Interpreter::evaluateAllQueries() {
    vector<Predicate> queryVector = newDatalogProgram.getQueriesVector();
    Relation finalRelation;
    cout << "Query Evaluation" << endl;
    for (unsigned int i =0; i < queryVector.size(); i++) {
        finalRelation = evaluatePredicate(queryVector.at(i));
        if (finalRelation.isEmpty()) {
            cout << queryVector.at(i).toString() << "? No" << endl;
        }
        else {
            cout << queryVector.at(i).toString() << "? Yes(" << finalRelation.getTupleSet().size() << ")" << endl;
            if (finalRelation.getHeader().getSize() != 0) {
                finalRelation.toString();
            }
        }


    }

}

void Interpreter::evaluateRules() {
    vector<Rules> rulesVector = newDatalogProgram.getRulesVector();
    Graph newGraph(rulesVector);
    newGraph.Run();
    cout << "Rule Evaluation" << endl;
    bool Added = true;
    int index = 0;
    vector<int> form;


    for (const auto& scc : newGraph.getSCCVector()) {
        Added = false;
        cout << "SCC: ";
        form.clear();
        for (const int& m : scc) {
            unsigned int index2;
            index2++;
            if (index2 != scc.size()) {
                cout << "R" << m << ",";
            }
            else {
                cout << "R" << m;
            }
            form.push_back(m);
        }
        cout << endl;
        do {
            Added = false;
            for (const int& m : scc) {
                if (evaluateRule(rulesVector.at(m))) {
                    Added = true;
                    index++;
                }
            }
        } while (Added);
        cout << index << " passes: ";
        for(unsigned int i = 0; i < form.size(); i++) {
            if(i != form.size()-1) {
                cout << "R" << form.at(i) << ",";
            }
            else {
                cout << "R" << form.at(i);
            }
        }
        cout << endl;
    }
    cout << endl;
}
bool Interpreter::evaluateRule(Rules rule) {
    //evaluate predicates
    //join the resulting relations
    //project the columns that appear in head predicate
    //rename the relation to make it union-compatible
    //union the relation in the database
    index1++;
    Relation finalRelation = evaluatePredicate(rule.getBody().at(0));
    Relation addRelation;
    vector<int> indexes;
    for(unsigned int j =1; j < rule.getBody().size(); j++) {
        addRelation = evaluatePredicate(rule.getBody().at(j));
        finalRelation = finalRelation.Join(addRelation);
    }

    for(unsigned int i =0; i < rule.getHead().GetParameters().size(); i++){
        string value = rule.getHead().GetParameters().at(i).name;
        for(unsigned int j =0; j < finalRelation.getHeader().getVector().size(); j++){
            string value2 = finalRelation.getHeader().getVector().at(j);
            if(value == value2){
                indexes.push_back(j);
            }
        }
    }

    finalRelation = finalRelation.Project(indexes);
    cout << rule.toString() << "." << endl;
    return newDatabase.getFromMap(rule.getHead().getName()).Unite(finalRelation);

}


