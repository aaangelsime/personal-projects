#include <iostream>
using namespace std;

bool lhs(bool a, bool b, bool c) {
    // a c' + b c + b' c'
    return (a && !c) || (b && c) || (!b && !c);
}

bool rhs(bool a, bool b, bool c) {
    // (a + b' + c)(a + b + c')(a' + b + c')
    bool s1 =  a || (!b) ||  c;
    bool s2 =  a ||   b   || (!c);
    bool s3 = (!a) ||  b   || (!c);
    return s1 && s2 && s3;
}

int main() {
    cout << "a b c | LHS RHS Equal\n";
    cout << "----------------------\n";

    bool all_equal = true;

    for (int x = 0; x < 8; ++x) {
        bool a = (x >> 2) & 1;
        bool b = (x >> 1) & 1;
        bool c = (x >> 0) & 1;

        bool L = lhs(a, b, c);
        bool R = rhs(a, b, c);
        bool eq = (L == R);
        all_equal &= eq;

        cout << a << " " << b << " " << c << " |  "
                  << L << "   " << R << "    " << (eq ? "Yes" : "No") << "\n";
    }

    cout << "\nResult: " 
              << (all_equal ? "All 8 rows match — expressions are equivalent."
                            : "Mismatch found — expressions are NOT equivalent.")
              << "\n";

    // Return a status code if you want CI-style pass/fail:
    return all_equal ? 0 : 1;
}
