#include "symboltable.h"

SymbolTable::SymbolTable()
{

}

variable *SymbolTable::getVariable(const QString &name)
{
    if(symbolExists(name))
    {
        list<variable *>::iterator v;
        for(v = _variables.begin(); v != _variables.end(); v++)
            if((*v) -> getTitle() == name)
                return *v;
    }
    return (variable *)NULL;
}

bool SymbolTable::symbolExists(const QString &name) const
{
    for(variable *v:_variables)
        if(v -> getTitle() == name)
            return true;

    return false;
}

bool SymbolTable::addVariable(variable *toAdd)
{
    if(!symbolExists(toAdd -> getTitle()))
        _variables.push_back(toAdd);
    else return false;

    return true;
}

bool SymbolTable::addVariable(const QString name, const float value)
{
    if(!symbolExists(name))
        _variables.push_back(new variable(name, value));
    else return false;

    return true;
}


bool SymbolTable::addVariable(const variable &toAdd)
{
    if(!symbolExists(toAdd.getTitle()))
        _variables.push_back(new variable(toAdd));
    else return false;

    return true;
}

bool SymbolTable::editVariable(variable &toEdit)
{
    if(symbolExists(toEdit.getTitle()))
    {
        list<variable *>::iterator v;
        for(v = _variables.begin(); v != _variables.end(); v++)
            if((*v) -> getTitle() == toEdit.getTitle())
                (*v) -> setValue(toEdit.calculer());
        return true;
    }
    return false;
}

bool SymbolTable::setVariable(variable &toSet)
{
    if(symbolExists(toSet.getTitle()))
        return editVariable(toSet);

    return addVariable(new variable(toSet));
}

bool SymbolTable::setVariable(const QString name, const float value)
{
    variable v(name, value);
    return setVariable(v);
}

bool SymbolTable::deleteVariable(const QString &name)
{
    if(symbolExists(name))
        for(list<variable *>::iterator v = _variables.begin(); v != _variables.end(); v++)
            if((*v) -> getTitle() == name)
            {
                //Deleting contained object
                delete *v;

                //Removing slot
                _variables.erase(v);
                return true;
            }

    return false;
}

bool SymbolTable::untrackVariable(const QString &name)
{
    if(symbolExists(name))
        for(list<variable *>::iterator v = _variables.begin(); v != _variables.end(); v++)
            if((*v) -> getTitle() == name)
            {
                //Removing slot
                _variables.erase(v);
                return true;
            }

    return false;
}

void SymbolTable::checkConsistent() const
{
    for(variable *v:_variables)
        if(v == NULL)
            throw "Null pointer to variable in symbol table";
}

void SymbolTable::displayContent(ostream &stream) const
{
    for(variable *v:_variables)
    {
        if(v != NULL)
            stream << v -> getTitle().toStdString() << " = " << v -> getValue();
        else
            stream << "Reading error";
        stream << endl;
    }
}
