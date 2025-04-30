#include <iostream>
#include <cmath>

using namespace std;


double f(double x) {
    return x*x;
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
    double sum = f(a) * f(b) / 2;

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

    /*for (int i = 1; i < n; i++) {*/

        for (int i = 1; i < n; i+=2)
        {
            double x1 = a + i * h;
            for (int y = 2; y < n; y+=2) {
                double x2 = a + i * h;
                sum += 4 * x1 + 2 * x2;
        }
        }

    return sum * (h / 3);
}

int main() {
    double a = 0;
    double b = 0;
    int n = 0;



    double result = rectangle_method(a, b, n);
    double result2 = trapeziod_method(a, b, n);
    //double result3 = trapeziod_method(a, b, n);

    cout << "Przyblizona wartosc calki dla metody prostokatow: " << result << endl;
    cout << "Przyblizona wartosc calki dla metody trapezow: " << result2 << endl;
    //cout << "Przyblizona wartosc calki dla metody Simpsona: " << result3 << endl;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.