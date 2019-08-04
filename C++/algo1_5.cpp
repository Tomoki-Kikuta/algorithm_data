#include<iostream>
#include<math.h>
using namespace std;
struct Point{
    double x;
    double y;
};
void koch(int,Point,Point);
int main(void){
    Point a,b;
    int n;
    cin >> n;
    a.x = 0;
    a.y = 0;
    b.x = 100;
    b.y = 0;
    cout << a.x <<' ' <<  a.y << '\n';
    koch(n,a,b);
    cout << b.x << ' ' << b.y << '\n';
    return 0;
}
void koch(int n,Point a,Point b){
    if(n==0){
        return;
    }
    else{
        Point s,t,u;
        double th = M_PI * 60.0 /180.0;
        s.x = (2.0 * a.x + 1.0 *b.x) /3.0;
        s.y = (2.0 * a.y + 1.0 *b.y) /3.0;
        t.x = (1.0 * a.x + 2.0 *b.x) /3.0;
        t.y = (1.0 * a.y + 2.0 *b.y) /3.0;
        u.x = (t.x - s.x) *cos(th) - (t.y-s.y) * sin(th) + s.x;
        u.y = (t.x - s.x) *sin(th) + (t.y-s.y) * cos(th) + s.y;
        koch(n-1,a,s);
        cout << s.x << ' ' << s.y << '\n';
        koch(n-1,s,u);
        cout << u.x << ' '<< u.y << '\n';
        koch(n-1,u,t);
        cout << t.x << ' ' <<t.y << '\n';
        koch(n-1,t,b);
    }
}