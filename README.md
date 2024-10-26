# expression-calculator-in-C

This C program demonstrates how to evaluate mathematical and logical expressions using the [TinyExpr library](https://github.com/codeplea/tinyexpr). It includes custom functions for relational operations (such as greater-than and equality checks) to support expressions with logical and relational operators.

## Features
- Evaluate mathematical and logical expressions with initial variable values.
- Extendable for adding other mathematical operations.

## Prerequisites
- **Compiler**: A C compiler like `gcc`.

## Getting Started

### 1. Clone the Repository 
```bash
git clone https://github.com/msk1039/expression-calculator-in-C.git
cd expression-calculator-in-C
```

### 2. Compile the code
```
gcc main.c tinyexpr.c -o evaluator -lm
```

### 3. Run the program
```
./evaluator
```

## Code Overview

The program defines custom functions to handle relational and logical operations:
- greater_than(double a, double b): Returns 1 if a > b, otherwise 0.
- eq(double a, double b): Returns 1 if a == b, otherwise 0.

## Expressions Evaluated

The program evaluates the following expressions:

- (3*i - 2*j) % (2*d - c)
- 2*(i/5) + (4*(j - 3)) % (i + j - 2)
- (i - 3*j) % (c + 2*d) / (x - y)
- neg(gt(j, 'c'))
- eq(2*x + y, 0)

## Customization

You can modify the expressions in main.c:

- Update or add expressions by changing the strings expr1 to expr5.
- To add more complex expressions, add new expressions as strings and recompile.

You can also define additional helper functions by following the greater_than , lower_than , eq and not_eq function examples in the code.

## License
This project uses TinyExpr under its open-source license. See the TinyExpr(https://github.com/codeplea/tinyexpr) repository for details.