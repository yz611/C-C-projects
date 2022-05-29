#include <iostream>
#include <cmath>
#include "Calc.h"
#include "stddef.h"

Calc::Calc(int values): storedExpressions
(new std::string[values]), stored(0){}

Calc::Calc(const Calc& rhs){
    if (storedExpressions != nullptr){
        storedExpressions = new std::string[rhs.stored];
    }
}

Calc::~Calc(){
    delete[] storedExpressions;
    storedExpressions = nullptr;
    stored = 0;
}

const Calc& Calc::operator=(const Calc& rhs){
    if(this != &rhs){
        Calc temp(rhs);
        std::swap(storedExpressions, temp.storedExpressions);
        std::swap(stored, temp.stored);
    }
    return *this;
}

double Calc::process(std::string userInput, double prevValue) {
    std::string cleansedString = "";
    for(size_t i = 0; i < userInput.size(); ++i){
        if (userInput[i] == '=' || userInput[i] == ' ' ||
        userInput[i] == '(' || userInput[i] == ')'){
        } else {
            cleansedString += userInput[i];
        }
    }
    double value = std::stod(cleansedString.substr(1, cleansedString.length() - 1));
    switch (cleansedString[0])
    {
    case '^':
        return pow(prevValue, value);
        break;

    case '*':
        return prevValue * value;
        break;
    
    case '/':
        return prevValue / value;
        break;

    case '+':
        return prevValue + value;
        break;

    case '-':
        return prevValue - value;
        break;

    default:
        std::cout << "ERROR: Must start with operator "<< std::endl;
    }
}

void Calc::setStored(size_t newStored){
    stored = newStored;
}

size_t Calc::getStored(){
    return stored;
}

void Calc::print(){
    std::cout << stored;
}