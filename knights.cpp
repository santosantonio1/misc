#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin >> n;
    for(ll i=1; i<=n; i++){
        if(i<=2){
            ll total = (i*i*(i*i-1))/2;
            cout << total << endl;
        }
        else{
            ll total = (i*i * (i*i-1))/2,
                rec = (i-1)*(i-2)*4;
            cout << total - rec << endl;
        }
    }
    return 0;
