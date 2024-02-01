//
//  ExprTest.cpp
//  MSDscript
//
//  Created by Thanmay Reddy Lakkireddy on 1/23/24.
//

#include <stdio.h>
#include "catch.h"
#include "expr.hpp"



TEST_CASE("Expression Testing") {


    SECTION("Test zero") {
        Expr *emptyOne = new Number(0);
        Expr *emptyTwo = new Number(0);
        Expr *emptyThree = new Number(12);
        Expr *one = new Number(1);
        Expr *two = new Number(12);

        CHECK_FALSE((new Variable("x")) -> equals(new Number(7)));
        CHECK(emptyOne->equals(emptyTwo));
        CHECK(emptyThree->equals(two));
        CHECK_FALSE(one->equals(two));
        CHECK_FALSE(one->equals(emptyOne));
        CHECK_FALSE(one->equals(emptyTwo));
    }

    SECTION("NUMBER") {
        
        Expr *numOne = new Number(1);
        Expr *numTwo = new Number(5);
        Expr *numThree = new Number(10);
        Expr *numFour = new Number(12);
        Expr *numFive = new Number(12);
        

        CHECK(numFour->equals(numFive));
        CHECK_FALSE(numOne->equals(numTwo));
        CHECK_FALSE(numTwo->equals(numFive));
        CHECK_FALSE((new Number(7))->equals(new Variable("x")));
        CHECK_FALSE(numFive->equals(numOne));
        CHECK_FALSE(numFour->equals(numThree));

    }

    SECTION("ADD") {

        Expr *addOne = new Add(new Number(1), new Number(1));
        Expr *addTwo = new Add(new Number(1), new Number(1));
        Expr *addThree = new Add(new Number(4), new Number(5));
        Expr *addFour = new Add(new Number(5), new Number(4));
        Expr *addFive = new Add(new Number(1), new Number(1));

        CHECK(addOne -> equals(addTwo));
        CHECK(addOne -> equals(addFive));
        CHECK_FALSE(addOne -> equals(addThree));
        CHECK_FALSE(addOne -> equals(addFour));
        CHECK(addTwo -> equals(addFive));
        
    }

    SECTION("MULTIPLY") {
        
        Expr *multOne = new Multiply(new Number(2), new Number(3));
        Expr *multTwo = new Multiply(new Number(2), new Number(3));
        Expr *multThree = new Multiply(new Number(4), new Number(5));
        Expr *multFour = new Multiply(new Number(2), new Number(5));
        Expr *multFive = new Multiply(new Number(2), new Number(3));

        CHECK(multOne -> equals(multTwo));
        CHECK_FALSE(multOne -> equals(multThree));
        CHECK_FALSE(multOne -> equals(multFour));
        CHECK(multOne -> equals(multFive));
        CHECK(multTwo -> equals(multFive));

    }

    SECTION("Different Operations") {
        
        Expr *addExpr = new Add(new Number(2), new Number(3));
        Expr *multExpr = new Multiply(new Number(2), new Number(3));
        Expr *addExprOne = new Add(new Number(3), new Number(2));
        Expr *multExprOne = new Multiply(new Number(5), new Number(3));
        Expr *addExprTwo = new Add(new Number(3), new Number(3));
        
        CHECK_FALSE(addExpr->equals(multExprOne));
        CHECK_FALSE(addExpr -> equals(addExprTwo));
        CHECK_FALSE(addExpr -> equals (addExprOne));
        CHECK_FALSE(addExprTwo -> equals(multExpr));
        CHECK_FALSE(multExpr -> equals(multExprOne));
        
    }

    SECTION("same structure, same operations, different values") {
        
        Expr *one = new Add(new Multiply(new Add(new Number(2), new Number(3)), new Add(new Number(4), new Number(5))),
                                 new Multiply(new Number(6), new Number(7)));

        Expr *two = new Add(new Multiply(new Add(new Number(2), new Number(3)), new Add(new Number(4), new Number(5))),
                                 new Multiply(new Number(8), new Number(7)));
        
        Expr *three = new Add(new Multiply(new Add(new Number(2), new Number(3)), new Add(new Number(4), new Number(5))),
                                 new Multiply(new Number(6), new Number(7)));

        Expr *four = new Add(new Multiply(new Add(new Number(2), new Number(3)), new Add(new Number(4), new Number(5))),
                                 new Multiply(new Number(8), new Number(7)));
        
        Expr *five = new Add(new Multiply(new Add(new Number(2), new Number(3)), new Add(new Number(4), new Number(5))),
                                 new Multiply(new Number(8), new Number(7)));

        CHECK(one -> equals (three));
        CHECK(two -> equals (four));
        CHECK_FALSE(one->equals(two));
        CHECK_FALSE(one->equals(four));
        CHECK(five->equals(four));

    }


    SECTION("Nested") {

        Expr *exprOne = new Multiply(new Add(new Number(2), new Number(3)), new Number(4));
  
        Expr *exprTwo = new Multiply(new Add(new Number(2), new Number(3)), new Number(4));

        Expr *exprThree = new Multiply(new Add(new Number(2), new Number(3)), new Number(5));

        Expr *exprFour = new Add(new Multiply(new Number(2), new Number(3)), new Number(4));

        Expr *exprFive = new Multiply(new Add(new Number(1), new Number(3)), new Number(5));
        
        CHECK(exprOne ->equals(exprTwo));
        CHECK_FALSE(exprOne ->equals(exprThree));
        CHECK_FALSE(exprOne ->equals(exprFour));
        CHECK_FALSE(exprOne -> equals (exprFive));
        CHECK_FALSE(exprTwo -> equals (exprFive));

    }

    SECTION("Different Types Nested") {
        
        Expr *exprOne = new Multiply(new Add(new Multiply(new Number(5), new Number(3)), new Number(2)),
                                new Add(new Number(5), new Number(11)));
        
        Expr *exprTwo = new Multiply(new Add(new Multiply(new Number(5), new Number(3)), new Number(2)),
                                new Add(new Number(5), new Number(11)));
        

        Expr *exprThree = new Multiply(new Add(new Multiply(new Number(2), new Number(3)), new Number(4)), new Number(11));
        
        Expr *exprFour = new Multiply(new Add(new Multiply(new Number(2), new Number(3)), new Number(4)),
                                new Add(new Add(new Number(5), new Number(6)), new Number(1)));
        
        Expr *exprFive = new Multiply(new Add(new Multiply(new Number(7), new Number(17)), new Number(4)),
                                      new Add(new Add(new Number(29), new Number(8)), new Number(67)));

        CHECK_FALSE(exprOne -> equals(exprThree));
        CHECK_FALSE(exprOne -> equals(exprFour));
        CHECK(exprOne -> equals(exprTwo));
        CHECK_FALSE(exprFour -> equals(exprTwo));
        CHECK_FALSE(exprFour -> equals(exprThree));
        CHECK_FALSE(exprFour -> equals (exprFive));

    }
    
    SECTION("Check throws with") {
       
        CHECK_THROWS_WITH( (new Variable("x"))->interp(), "no value for variable" );
    }
    
    SECTION("Check - Interp - Add") {
        CHECK( (new Add(new Number(3), new Number(2)))->interp()==5 );
        CHECK( (new Add(new Number(5), new Number(2)))->interp()==7 );
        CHECK( (new Add(new Number(9), new Number(2)))->interp()==11 );
        CHECK( (new Add(new Number(4), new Number(2)))->interp()==6 );
        CHECK( (new Add(new Number(3), new Number(3)))->interp()==6 );
    }
    
    SECTION("Interp") {
        
        CHECK( (new Add(new Add(new Number(10), new Number(15)),new Add(new Number(20),new Number(20))))
                ->interp()==65);
        
    }
    
    SECTION("Check - Interp - Multiply") {
        CHECK( (new Multiply(new Number(3), new Number(2)))->interp()==6 );
        CHECK( (new Multiply(new Number(5), new Number(2)))->interp()==10 );
        CHECK( (new Multiply(new Number(9), new Number(2)))->interp()==18 );
        CHECK( (new Multiply(new Number(4), new Number(2)))->interp()==8 );
        CHECK( (new Multiply(new Number(3), new Number(3)))->interp()==9 );
    }
    
    SECTION("has_variable Test") {
        CHECK( (new Add(new Variable("x"), new Number(1)))->has_variable() == true );
        CHECK( (new Multiply(new Number(2), new Number(1)))->has_variable() == false );
        CHECK( (new Add(new Number(2), new Number(1)))->has_variable() == false );
        CHECK( (new Multiply(new Number(2), new Number(1)))->has_variable() == false );
        CHECK( (new Multiply(new Variable("y"), new Number(1)))->has_variable() == true );
    }
    
    SECTION("Subst Test") {
        
        CHECK( (new Add(new Variable("x"), new Number(7)))
               ->subst("x", new Variable("y"))
               ->equals(new Add(new Variable("y"), new Number(7))) );
       
        
        CHECK( (new Variable("x"))
               ->subst("x", new Add(new Variable("y"),new Number(7)))
               ->equals(new Add(new Variable("y"),new Number(7))) );
        
        CHECK( (new Add(new Variable("z"), new Number(8)))
               ->subst("z", new Variable("a"))
               ->equals(new Add(new Variable("a"), new Number(8))) );
        
        CHECK( (new Variable("z"))
               ->subst("z", new Add(new Variable("a"),new Number(8)))
               ->equals(new Add(new Variable("a"),new Number(8))) );
        
        CHECK( (new Add(new Variable("b"), new Number(9)))
               ->subst("b", new Variable("c"))
               ->equals(new Add(new Variable("c"), new Number(9))) );
        
        CHECK( (new Variable("b"))
               ->subst("b", new Add(new Variable("c"),new Number(9)))
               ->equals(new Add(new Variable("c"),new Number(9))) );
        
        //new test added
        CHECK( (new Variable("a"))
               ->subst("b", new Add(new Variable("c"),new Number(9)))
               ->equals(new Variable("a") ));
        CHECK( (new Multiply(new Variable("x"), new Number(7)))
               ->subst("x", new Variable("y"))
               ->equals(new Multiply(new Variable("y"), new Number(7))) );

    }
    
}
