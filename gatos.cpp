#include <iostream>
#include <queue>
using namespace std;
int main(){
    string s = "a";
    queue<int> p1,p2;
    while(getline(cin, s)){
        if(s=="-") break;
        p1.push(stoi(s));
    }
    while(getline(cin, s)){
        if(s=="-") break;
        p2.push(stoi(s));
    }

    while(!p1.empty() && !p2.empty()){
        int c1 = p1.front(), c2 = p2.front();
        if(c1>c2) {
            p1.pop(); p2.pop();
            p1.push(c1);
            p1.push(c2);
            continue;
        }
        if(c1<c2){
            p1.pop(); p2.pop();
            p2.push(c2);
            p2.push(c1);
            continue;
        }
    }
    int score = 0;
    if(p1.empty()){
        while(!p2.empty()){
        int i = p2.size();
        int x = p2.front();
        cout << x << endl;
        score += x * i;
        p2.pop();
        }
    } 
    else{
        while(!p1.empty()){
        int i = p1.size();
        int x = p1.front();
        cout << x << endl;
        score += x * i;
        p1.pop(); 
        }   
    }
    cout << score << endl;
    return 0;
}