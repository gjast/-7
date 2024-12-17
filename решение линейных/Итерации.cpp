#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
using namespace std;

float f(float x) {
    return 0.25 * pow(x, 3) + x - 1.2502;
}
float g(float x) {
    return 1.2502 - 0.25f * pow(x, 3);
}

int main() {
    float x0 = 1.0;
    float x1, e = 0.00001;
    int N = 100;
    int step = 0;

    auto start = chrono::high_resolution_clock::now();

    do {
        x1 = g(x0);
        step++;

        cout << "Итерация " << step << ": x = " << x1 << endl;
        if (step > N) {
            return 0;
        }
        x0 = x1;

    } while (abs(f(x1)) > e);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "\nКорень: " << x1 << endl;
    cout << "Количество итераций: " << step << endl;
    cout << "Время выполнения: " << duration.count() << " секунд." << endl;

    return 0;
}
