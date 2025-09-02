# Boolean Equivalence Checker

This project provides a simple C++ program that verifies whether two Boolean expressions are logically equivalent.  
It works by generating a full **truth table** for all possible input combinations and comparing the outputs of both expressions.

## Expressions Checked

The program compares the following Boolean expressions:

- ** x'z + yz + y'z' = (x + y' + z)(x + y + z')(x' + y + z') **

Where:
- `x`, `y`, `z` are Boolean variables (0 or 1).
- `+` represents logical OR.
- Concatenation (e.g., `xy`) represents logical AND.
- `'` represents logical NOT.

## How It Works

1. Iterates through all possible values of `(a, b, c)`.
2. Evaluates both LHS and RHS for each combination.
3. Prints a truth table showing results and whether they match.
4. Reports at the end if the two expressions are **equivalent**.