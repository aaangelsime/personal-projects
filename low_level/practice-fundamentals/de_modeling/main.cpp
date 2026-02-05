/*
Approximating Differential Equations Using:

Euler's Method & 4th Order Runge-Kutta
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

// Differential equation: dy/dt = t / y
double f(double t, double y)
{
    return t / y;
}

// Runge–Kutta 4th order step
double rk4_step(double t, double y, double h)
{
    double k1 = f(t, y);
    double k2 = f(t + h / 2.0, y + h * k1 / 2.0);
    double k3 = f(t + h / 2.0, y + h * k2 / 2.0);
    double k4 = f(t + h, y + h * k3);

    return y + (h / 6.0) * (k1 + 2*k2 + 2*k3 + k4);
}

int main()
{
    double t0 = 0.0;
    double y0 = 1.0;
    double h  = 0.1;
    double tn = 1.0;

    int steps = static_cast<int>((tn - t0) / h);

    std::vector<double> t(steps + 1);
    std::vector<double> y_euler(steps + 1);
    std::vector<double> y_rk(steps + 1);

    t[0] = t0;
    y_euler[0] = y0;
    y_rk[0] = y0;

    // Time stepping
    for (int i = 0; i < steps; i++)
    {
        t[i + 1] = t[i] + h;

        // Euler
        y_euler[i + 1] = y_euler[i] + h * f(t[i], y_euler[i]);

        // Runge–Kutta
        y_rk[i + 1] = rk4_step(t[i], y_rk[i], h);
    }

    // Output formatting
    std::cout << std::fixed;

    std::cout << "Euler  | Runge-Kutta\n";
    std::cout << "====================\n";
    std::cout << "T   | Euler    | RK4\n";

    for (int i = 0; i <= steps; i++)
    {
        std::cout << std::setprecision(1) << t[i] << " | "
                  << std::setprecision(4) << y_euler[i] << " | "
                  << std::setprecision(4) << y_rk[i] << "\n";
    }

    return 0;
}
