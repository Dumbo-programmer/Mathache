#include "standard_library.h"
#include <cmath>

double StandardLibrary::add(double a, double b) {
    return a + b;
}

double StandardLibrary::multiply(double a, double b) {
    return a * b;
}

double StandardLibrary::derivative(double (*f)(double), double x) {
    double h = 1e-5;
    return (f(x + h) - f(x)) / h;
}

double StandardLibrary::integrate(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += f(a + i * h) * h;
    }
    return sum;
}
