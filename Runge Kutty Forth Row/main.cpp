#include <iostream>
#include <math.h>

using namespace std;

double dydividedx(double x, double y) {
    return tan(y) + 1;
}

double rungeKuttyForthRow(double y[], double N, double step) {
    auto k = new double[4];
    double deltaYn = 0;
    double changedX = 0;
    for (int x = 0; x < N / step; x++) {
        k[0] = step * dydividedx(changedX, y[x]);
        k[1] = step * dydividedx(changedX + step / 2, y[x] + 0.5 * k[0]);
        k[2] = step * dydividedx(changedX + step / 2, y[x] + 0.5 * k[1]);
        k[3] = step * dydividedx(changedX + step, y[x] + k[2]);
        deltaYn = (1.0 / 6.0) * (k[0] + 2 * k[1] + 2 * k[2] + k[3]);
        y[x + 1] = y[x] + deltaYn;
        changedX = changedX + step;
    }
    for (int i = 0; i < N / step; i++) {
        cout << "y" << i + 1 << " = " << y[i] << endl;
    }

}

int main() {
    double N = 0.4;
    double step = 0.025;
    double amountOfCounts = N / step;
    auto intAmountOfCounts = (int) amountOfCounts;
    auto *y = new double[intAmountOfCounts];
    y[0] = 1;
    rungeKuttyForthRow(y, N, step);
    return 0;
}