#include <iostream>
#include <cmath>

using namespace std;


double f(double x) {
    return /*x*x + x*x*x + 2*x +*/ (cos(x));
}

// Metoda prostokątów
double rectangle_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double x_i = a + i * h;
        sum += f(x_i);
    }
    return sum * h;
}
// Metoda trapezów
double trapeziod_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 0; i < n; i++) {
        double x_i = a + i * h;
        sum += f(x_i);
    }
    return sum * h;
}

// Metoda Simpsona
double simpson_method(double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "Liczba przedziałów n musi być parzysta dla metody Simpsona." << endl;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
    {
        double x = a + i * h;
        sum += 4 * f(x);
    }

    for (int i = 2; i < n; i += 2)
    {
        double x = a + i * h;
        sum += 2 * f(x);
    }

    return sum * (h / 3) ;
}

// Kwadratura Gaussa-Czebyszewa
double gauss_chebyshev(int n) {
    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        double x_i = cos(M_PI * (2.0 * i - 1) / (2.0 * n));
        sum += f(x_i) * sqrt(1 - x_i * x_i);
    }

    return M_PI / n * sum;
}

int main() {
    double a = -1;
    double b = 1;
    int n = 200;



    double result = rectangle_method(a, b, n);
    double result2 = trapeziod_method(a, b, n);
    double result3 = simpson_method(a, b, n);
    double result4 = gauss_chebyshev(n);

    cout << "Przyblizona wartosc calki dla metody prostokatow: " << result << endl;
    cout << "Przyblizona wartosc calki dla metody trapezow: " << result2 << endl;
    cout << "Przyblizona wartosc calki dla metody Simpsona: " << result3 << endl;
    cout << "Przyblizona wartosc calki dla kwadratury Gaussa-Czebyszewa: " << result4 << endl;
    return 0;
}

