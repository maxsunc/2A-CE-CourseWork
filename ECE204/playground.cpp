#include <iostream>
#include <iomanip>

double approx_derivative(double (*f)(double), double x, double h)
{
    return (f(x + h) - f(x - h)) / (2 * h);
}

int main()
{
    auto f = [](double x)
    { return x * x; }; // Example function: f(x) = x^2
    double x = 2.0;    // Point at which to approximate the derivative
    double h = 0.01;   // Small step size

    while (h > 1e-10)
    {
        double derivative = approx_derivative(f, x, h);
        std::cout << "h: " << std::setw(10) << h
                  << " Approx. Derivative: " << std::setw(15) << derivative
                  << " Exact Derivative: " << std::setw(15) << 2 * x
                  << std::endl;
        h /= 10; // Decrease h
    }

    return 0;
}