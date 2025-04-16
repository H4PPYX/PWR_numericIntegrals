#include <iostream>
#include <cmath>

using namespace std;


double f(double x) {
    return sin(x);
}

// Metoda prostokątów
double rectangle_method(double a, double b, int n) {
    double h = (b - a) / n; // Szerokość przedziału
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double x_i = a + i * h;
        sum += f(x_i);
    }
    return sum * h;
}
// Metoda trapezów
double trapeziod_method(double a, double b, int n) {
    double h = (b - a) / n; // Szerokość przedziału
    double sum = f(a) * f(b) / 2;

    for (int i = 0; i < n; i++) {
        double x_i = a + i * h;
        sum += f(x_i);
    }
    return sum * h;
}

int main() {
    double a, b;
    int n;

    cout << "Podaj przedzial calkowania [a, b]: ";
    cin >> a >> b;
    cout << "Podaj liczbe podzialow n: ";
    cin >> n;

    double result = rectangle_method(a, b, n);
    double result2 = trapeziod_method(a, b, n);

    cout << "Przyblizona wartosc calki: " << result << endl;
    cout << "Przyblizona wartosc calki: " << result2 << endl;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.