#include <matplot/matplot.h>
#include <cmath>

/*
Compile instr.

g++ main.cpp -std=c++17 \
-I/opt/homebrew/opt/matplotplusplus/include \
-L/opt/homebrew/opt/matplotplusplus/lib \
-lmatplot \
-o plot

./plot
*/


int main() {

    using namespace matplot;

    auto my_function = [](double t)
    {   
        return std::sin(t) * std::exp(-t / 5.0);
    };

    auto x = linspace(0.0, 10.0 * pi, 1000);
    auto y = transform(x, my_function);

    plot(x, y)->line_width(3).color("blue");

    title("Plot of sin(t) * exp(-t/5)");
    show();
}
