#ifndef STANDARD_LIBRARY_H
#define STANDARD_LIBRARY_H

class StandardLibrary {
public:
    static double add(double a, double b);
    static double multiply(double a, double b);
    static double derivative(double (*f)(double), double x);
    static double integrate(double (*f)(double), double a, double b, int n);
};

#endif // STANDARD_LIBRARY_H
