#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {
	cout<<setprecision(20);
	double x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	double ax = (x1 + x2) / 2;
	double ay = (y1 + y2) / 2;
	double bx = ax + y1 - ay;
	double by = ay - x1 + ax;
	double cx = (x3 + x2) / 2;
	double cy = (y3 + y2) / 2;
	double dx = cx + y2 - cy;
	double dy = cy - x2 + cx;
	double k = ((cx - ax) * (dy - cy) - (cy - ay) * (dx - cx)) / ((bx - ax) * (dy - cy) - (by - ay) * (dx - cx));

	double rx = ax + (bx - ax) * k;
	double ry = ay + (by - ay) * k;

	double d1x = x1 - rx;
	double d1y = y1 - ry;
	double d2x = x2 - rx;
	double d2y = y2 - ry;
	double d3x = x3 - rx;
	double d3y = y3 - ry;
	double l =  sqrt(d1x * d1x + d1y * d1y);
	double a1 = acos((d1x * d2x + d1y * d2y) / l / l);
	double a2 = acos((d3x * d2x + d3y * d2y) / l / l);
	double n1 = a1 / M_PI / 2;
	double n2 = a2 / M_PI / 2;
	for(int i = 3; i <= 100; i++) {
		int p1 = (int)(n1 * i + .0001);
		int p2 = (int)(n2 * i + .0001);
		if(abs(p1 - n1 * i) < .001 && abs(p2 - n2 * i) < .001) {
			cout<<sin(M_PI * 2 / i) * l * l / 2 * i<<endl;
			break;
		}
	}
}
