#include <iostream>
#include <cmath>
using namespace std;
class point{
    public:
        double x, y;
        point(int xo = 0, int yo=0) {
            x = xo;
            y = yo;
        }
        double dist(point a, point b) {
            return sqrt(pow(a.x - b.x,2)+pow(a.y-b.y,2));
        }
        double dist_o(point a) {
            return sqrt(pow(a.x,2)+pow(a.y,2));
        }
        point operator+(point &a) {
            point z;
            z.x = x + a.x;
            z.y = y + a.y;
            return z;
        }
        point operator-(point &a) {
            point z;
            z.x = x - a.x;
            z.y = y - a.y;
            return z;
        }
        point operator*(point &a) {
            point z;
            z.x = x*a.x;
            z.y = y*a.y;
            return z;
        }
        point operator/(point &a) {
            point z;
            z.x = x/a.x;
            z.y = y/a.y;
            return z;
        }
        bool operator==(point &a) {
            return x==a.x && y==a.y;
        }
        int quad() {
            if(x==0 && y==0) return 0;
            if(x>0 && y>0) return 1;
            if(x<0 && y>0) return 2;
            if(x<0 && y<0) return 3;
            if(x>0 && y<0) return 4;
            return -1;
        }
        void print() {
            cout << "(" << x << "," << y << ")";
        }
};

int main() {
    point a(2,3), b(4,5), c, d(2,3);
    c = a/b;
    bool x = a==d;
    cout << c.x << " " << c.y;   
    cout << "\n" << x;
}