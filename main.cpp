#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;


double f(double x) {
    return 0.2 + 25 * x - 200 * x*x + 675 * x*x*x - 900 * x*x*x*x + 400 * x*x*x*x*x;
}

// Metoda prostokątów
double rectangle_method(double a, double b, int n) {
    double h = (b - a) / n; //Obliczanie długości przedziałów
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double x_i = a + i * h;
        sum += f(x_i); //Podstawiamy wyznaczone punkty do danej funkcji
    }
    return sum * h; //Obliczamy sumę pól prostokątów dla poszczególnych przedziałów
}
// Metoda trapezów
double trapezoid_method(double a, double b, int n) {
    double h = (b - a) / n; //Obliczanie długości przedziałów
    double sum = (f(a) + f(b)) / 2;

    for (int i = 0; i < n; i++) {
        double x_i = a + i * h;
        sum += f(x_i); //Podstawiamy wyznaczone punkty do danej funkcji
    }
    return sum * h; //Obliczamy sumę pól trapezów dla poszczególnych przedziałów
}

// Metoda Simpsona
double simpson_method(double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "Liczba przedzialow n musi byc parzysta dla metody Simpsona." << endl;
        return 0;
    }

    double h = (b - a) / n; //Obliczanie długości przedziałów
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
    {
        double x = a + i * h;
        sum += 4 * f(x); //Suma nieparzystych
    }

    for (int i = 2; i < n; i += 2)
    {
        double x = a + i * h;
        sum += 2 * f(x); //Suma parzystych
    }

    return sum * (h / 3) ;
}

// Kwadratura Gaussa-Czebyszewa
double gauss_chebyshev(int n) {
    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        double x_i = cos(M_PI * (2.0 * i - 1) / (2.0 * n)); //Generowanie miejsc zerowych wielomianu Czebyszewa
        sum += f(x_i) * sqrt(1 - x_i * x_i);
    }

    return M_PI / n * sum;
}

int main() {
    double a = -1;
    double b = 1;
    int n = 2;


    auto start1 = high_resolution_clock::now();
    double r = rectangle_method(a, b, n);
    auto stop1 = high_resolution_clock::now();
    auto d1 = duration_cast<nanoseconds>(stop1 - start1);
    cout << "Przyblizona wartosc calki dla metody prostokatow: " << r << ", czas = " << d1.count() << " ns\n";


    auto start2 = high_resolution_clock::now();
    double t = trapezoid_method(a, b, n);
    auto stop2 = high_resolution_clock::now();
    auto d2 = duration_cast<nanoseconds>(stop2 - start2);
    cout << "Przyblizona wartosc calki dla metody trapezow: = " << t << ", czas = " << d2.count() << " ns\n";


    auto start3 = high_resolution_clock::now();
    double s = simpson_method(a, b, n);
    auto stop3 = high_resolution_clock::now();
    auto d3 = duration_cast<nanoseconds>(stop3 - start3);
    cout << "Przyblizona wartosc calki dla metody Simpsona: " << s << ", czas = " << d3.count() << " ns\n";


    auto start4 = high_resolution_clock::now();
    double g = gauss_chebyshev(n);
    auto stop4 = high_resolution_clock::now();
    auto d4 = duration_cast<nanoseconds>(stop4 - start4);
    cout << "Przyblizona wartosc calki dla kwadratury Gaussa-Czebyszewa: = " << g << ", czas = " << d4.count() << " ns\n";

    return 0;
}

