#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <list>
#include "variable.h"

class SymbolTable
{
private:
    list<variable *> _variables;
public:
    SymbolTable();

    //Get Variable object from name
    variable *getVariable(const QString &name);

    //Check if a Variable is found with given name
    bool symbolExists(const QString &name) const;

    //TABLE EDITORS
    //Passes the reference of this variable inside of the table
    bool addVariable(variable *toAdd);

    //Adds a Variable in table if no Variable with the same name exists in
    bool addVariable(const QString name, const float value);

    //Adds a Variable in table if no Variable with the same name exists in
    bool addVariable(const variable &toAdd);

    //Edits a Variable with the same name than the given variable, to its value.
    //'toEdit' variable is not edited, and only serves as a model.
    bool editVariable(const variable &toEdit);

    //Choose between addVariable() or editVariable()
    bool setVariable(const variable &toSet);
    bool setVariable(const QString name, const float value);

    //Delete a Variable from list
    bool deleteVariable(const QString &name);

    //Removes a pointer
    bool untrackVariable(const QString &name);

    //Checks if every list's slots have a non-null adress
    void checkConsistent() const;

    //Display contained variables
    void displayContent(ostream &stream) const;
};

#endif // SYMBOLTABLE_H
