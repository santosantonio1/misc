/*
  CSES problem 6 - Number Spiral
  A number spiral is a matrix in the form of:
     1  2  9 10 25
     4  3  8 11 24
     5  6  7 12 23
    16 14 13 11 22
    17 18 19 20 21 
    Notice the main diagonal belongs to an arithmetic sequene of 
    Second Order(ratio 2). Then An = 1 + n*(n-1).
    n is the "cycle" where An belongs -> n = max(x,y).
    We start at An then if y>x we must move left. If y<x we move up
    and if x=y the element is An.
    Movig depends on n. If n is odd, moving left we find numbers in
    increasing order and moving up we find elements in decreasing
    order. If n is even, moving left we find numbers in decreasing 
    order and moving up we find numbers in increasing. The number
    of moves we must take is max(x,y) - min(x,y).
    @Antonio dos Santos
  */
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    ll N;
    cin >> N;
    for(int i=0; i<N; i++) {
    ll x, y;
    cin >> y >> x;
      ll n = max(x,y),
         k = pow(-1,n%2),
    answer = 1 + n*(n-1);
    if(y>x) answer += k*(max(x,y)-min(x,y));
    if(y<x) answer -= k*(max(x,y)-min(x,y));
    cout << answer << endl;
    }
    return 0;
}
