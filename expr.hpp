//
//  expr.hpp
//  MSDscript
//
//  Created by Thanmay Reddy Lakkireddy on 1/23/24.
//

#ifndef expr_hpp
#define expr_hpp

#include <string>

#include <stdio.h>

using namespace std;

/*
 <expr> = <number>
        | <expr> + <expr>
        | <expr> * <expr>
        | <variable>
 */


// Class Expr
class Expr {
    
public:
    virtual bool equals( Expr *randNumber) = 0;
    virtual int interp() = 0;
    virtual bool has_variable() = 0;
    virtual Expr * subst(string var, Expr* randExpr) = 0;
    
};


// Class Number
class Number : public Expr {

    public:
        int value;
        Number(int value);
        bool equals(Expr *randNumber);
        int interp();
        bool has_variable();
        Expr * subst(string var, Expr* randExpr);
};


// Class Add
class Add : public Expr {
    
    public:
        Expr *lhs;
        Expr *rhs;
        Add(Expr *lhs, Expr *rhs);
        bool equals(Expr *number);
        int interp();
        bool has_variable();
        Expr * subst(string var, Expr* randExpr);
};


// Class Multiply
class Multiply : public Expr {
    
    public:
        Expr *lhs;
        Expr *rhs;
        Multiply(Expr *lhs, Expr *rhs);
        bool equals(Expr *number);
        int interp();
        bool has_variable();
        Expr * subst(string var, Expr* randExpr);
};


// Class Variable
class Variable : public Expr {
    
public:
    string val;
    Variable(string val);
    bool equals(Expr *randVal);
    int interp();
    bool has_variable();
    Expr * subst(string var, Expr* randExpr);
};



#endif /* expr_hpp */
