#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// messy and works :|
int a, b, c, d, e, f, g, h, i, j;

double evaluate1(double x, double y) {
    return a * x * x + b * x + c * y * y + d * y + e;
}
double evaluate2(double x, double y) {
    return f * x * x + g * x + h * y * y + i * y + j;
}

double gradx(double x, double y) {
    return 2 * (2 * a * x + b) * evaluate1(x, y) + 2 * (2 * f * x + g) * evaluate2(x, y);
}
double grady(double x, double y) {
    return 2 * (2 * c * y + d) * evaluate1(x, y) + 2 * (2 * h * y + i) * evaluate2(x, y);
}

int main() {
    int x1, y1, r1;
    int x2, y2, r2;
    int x3, y3, r3;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cin >> x3 >> y3 >> r3;
    
    a = (r2 * r2 - r1 * r1);
    b = -2 * (x1 * r2 * r2 - x2 * r1 * r1);
    c = (r2 * r2 - r1 * r1);
    d = -2 * (y1 * r2 * r2 - y2 * r1 * r1);
    e = ((x1 * x1 + y1 * y1) * r2 * r2 - (x2 * x2 + y2 * y2) * r1 * r1);
    f = (r3 * r3 - r1 * r1);
    g = -2 * (x1 * r3 * r3 - x3 * r1 * r1);
    h = (r3 * r3 - r1 * r1);
    i = -2 * (y1 * r3 * r3 - y3 * r1 * r1);
    j = ((x1 * x1 + y1 * y1) * r3 * r3 - (x3 * x3 + y3 * y3) * r1 * r1);
    
    double x[] = {x1, x2, y3};
    double y[] = {y1, y2, y3};
    for(int k = 0; k < 3; k++) {
        double step = 5;
        for(int kk = 0; kk < 10000; kk++) {
            double gx = gradx(x[k], y[k]);
            double gy = grady(x[k], y[k]);
            double gd = sqrt(gx * gx + gy * gy);
            double e1 = evaluate1(x[k], y[k]);
            double e2 = evaluate2(x[k], y[k]);
            if(gd < .00000001) break;
            step = (e1 * e1 + e2 * e2) / gd / 2;
            x[k] += -step * gx / gd;
            y[k] += -step * gy / gd;
        }
    }
    double mind = -10;
    int mink = 0;
    for(int k = 0; k < 3; k++) {
        if(mind < 0 || mind > (x[k] - x1) * (x[k] - x1) + (y[k] - y1) * (y[k] - y1)) {
            mind = (x[k] - x1) * (x[k] - x1) + (y[k] - y1) * (y[k] - y1);
            mink = k;
        }
    }
    if(abs(evaluate1(x[mink], y[mink])) < .01 && abs(evaluate2(x[mink], y[mink])) < .01) {
        printf("%.5f %.5f", x[mink], y[mink]);
    
    return 0;
}
