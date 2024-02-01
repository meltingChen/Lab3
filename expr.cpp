//
//  expr.cpp
//  MSDscript
//
//  Created by Thanmay Reddy Lakkireddy on 1/23/24.
//

#include "expr.hpp"
#include <stdexcept>

using namespace std;


/*
 --------NUMBER----------
 */

// Number
Number :: Number (int value) {
    // value
    this -> value = value;
    
}

// Number - Equals
bool Number :: equals (Expr * number) {
    
    Number *numberTwo = dynamic_cast<Number*>(number);
    
    if (numberTwo == NULL) {
        return false;
    } else {
        return (this->value == numberTwo->value);
    }
    
}

// Number - Interp
int Number :: interp() {
    
    return this -> value;
    
}

// Number - Has Variable
bool Number :: has_variable() {
    // bool
    return false;
    
}

//  Number - subst
Expr* Number :: subst(string var, Expr* randExpr) {
    
    return new Number(this -> value);
    
}


/*
 ----------ADD----------
 */


// Add
Add :: Add (Expr *numberOne, Expr *numberTwo) {
    
    this->lhs = numberOne;
    this->rhs = numberTwo;
    
}

// Add - Equals
bool Add :: equals(Expr *number) {
    
    Add *numberTwo = dynamic_cast<Add*>(number);
    
    if (numberTwo == NULL) {
        return false;
    } else {
        return this->lhs -> equals(numberTwo->lhs) && this->rhs -> equals(numberTwo -> rhs);
    }
    
}

// Add - Interp
int Add :: interp() {
    
    int numberOne = (this-> lhs-> interp());
    int numberTwo = (this-> rhs-> interp());
    
    // add
    int total = numberOne + numberTwo;
    return total; // total
    
}

// Add - Has Variable
bool Add :: has_variable() {

    return (lhs ->has_variable() || rhs -> has_variable());
    
}

// Add - Subst
Expr* Add :: subst (string var, Expr* randExpr){
    
    // do not use dynamic casting
    return new Add(lhs->subst(var, randExpr), rhs->subst(var, randExpr));
    
}


/*
 --------------Multiply-----------
 */


// Multiply
Multiply :: Multiply (Expr *numberOne, Expr *numberTwo) {
    
    this->lhs = numberOne;
    this->rhs = numberTwo;
    
}

// Multiply - Equals
bool Multiply :: equals(Expr *number) {
    
    Multiply *numberTwo = dynamic_cast<Multiply*>(number);
    
    if (numberTwo == NULL) {
        return false;
    } else {
        return this->lhs -> equals(numberTwo->lhs) && this->rhs -> equals(numberTwo -> rhs);
    }
    
}

// Multiply - Interp
int Multiply :: interp() {
    
    int numberOne = (this -> lhs -> interp() );
    int numberTwo = (this -> rhs -> interp());
    
    int total = numberOne * numberTwo;
    
    return total; // total
    
}

// mMultiply - Has Variable
bool Multiply:: has_variable() {
    return (lhs ->has_variable() || rhs -> has_variable());
    
}

// Multiply - Subst
Expr* Multiply :: subst (string var, Expr* randExpr) {
    
    // do not use dynamic casting
    return new Multiply(lhs->subst(var, randExpr), rhs->subst(var, randExpr));
    
}


/*
 -------------Variable--------------
 */

// Variable
Variable :: Variable (string val) {
    
    this -> val = val;
    
}

// Variable - Equals
bool Variable :: equals(Expr *var) {
    
    Variable *varTwo = dynamic_cast<Variable*>(var);
    
    if (varTwo == NULL) {
        return false;
    } else {
        return this->val == varTwo->val;
    }
    
}

// Variabel - Interp
int Variable :: interp() {
    // throws
    throw runtime_error("no value for variable");

    
}

// Variable - Has Variable
bool Variable :: has_variable () {
    
    // bool
    return true;
}

// Variable - SUbst
Expr* Variable :: subst(string var, Expr* randExpr){
    
    if(this->val == var){
        
        return randExpr;
    }

    // return
    return new Variable (this->val);
    
}
