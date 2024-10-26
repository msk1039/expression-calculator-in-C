#include<stdio.h>
#include "tinyexpr.h"

void execute(const char *expression, te_variable *vars, int var_count) {

    te_expr *compiled_expr = te_compile(expression, vars, var_count+4, 0); // compile the expression
    if (compiled_expr) {
        double result = te_eval(compiled_expr); // evaluate the expression
        printf("%s = %f\n", expression, result); // print the result
        te_free(compiled_expr);
    } else {
        printf("Error in expression\n");
    }
}

// custom functions to be used in the expressions
double greater_than(double a, double b) { 
    return a > b ? 1 : 0;
}

double lower_than(double a, double b) {
    return a < b ? 1 : 0;
}

double eq(double a, double b) {
    return a == b ? 1 : 0;
}

double not_eq(double a, double b)
{
    return a != b ? 1 : 0;
}

int main()
{

    // initialise variables over which the expressions will be evaluated
    // SHOULD BE OF TYPE DOUBLE
    double i = 8, j = 5;
    double x = 0.005, y = -0.01;
    double a=99, b=99, c = 99, d = 100;
 

    // passing the addresses of our variables in the array for tinyexpr
    te_variable vars[] = { 
        // modify these variables as needed 
        {"i", &i}, 
        {"j", &j},
        {"x", &x}, 
        {"y", &y},
        {"a", &a}, 
        {"b", &b},
        {"c", &c}, 
        {"d", &d},
        // custom functions to be used in the expressions
        {"greater_than", greater_than, TE_FUNCTION2},
        {"lower_than", lower_than , TE_FUNCTION2},
        {"eq", eq, TE_FUNCTION2},
        {"not_eq", not_eq, TE_FUNCTION2}
    };
 


    //example expressions (with only arithmetic operators)
    const char *expr1 = "(3*i - 2*j) % (2*d - c)";
    const char *expr2 = "2*(i/5)+(4*(j-3)) - (i+j-2)"; 


    // NOTE: 
    //example expressions with custom functions as logical expressions are not compatible with tinyexpr
    const char *expr3 = "greater_than(i, j)"; //instead of ( i > j )
    const char *expr4 = "lower_than(x, y)"; //instead of ( x < y )
    const char *expr5 = "eq(a, b)"; //instead of ( a == b )
    const char *expr6 = "not_eq(c, d)"; //instead of ( c != d )

    //example of expression with custom functions .
    const char *expr7 = "greater_than( 5*(j) , c )"; // instead of 5*(j)>c


    // pass the expression string to be calculated as the first parameter , the array of variables as the second parameter and the number of variables as the third parameter
    execute(expr1, vars, 7);

    return 0;
}