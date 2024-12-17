#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

float func(float x) {
    return 0.25 * pow(x, 3) + x - 1.2502;
}

float n(float x1, float x2, int &iterations) {
    float x = (x2 + x1) / 2;
    while (abs(func(x)) > 0.00001) {
        if (func(x) > 0) x2 = x;
        else x1 = x;
        x = (x2 + x1) / 2;
        iterations++;
    }
    return x;
}

int main() {
    int iterations = 0;
    auto start = chrono::high_resolution_clock::now();

    float result = n(0, 2, iterations);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Результат: " << result << endl;
    cout << "Количество итераций: " << iterations << endl;
    cout << "Время выполнения: " << duration.count() << " секунд" << endl;

    return 0;
}
