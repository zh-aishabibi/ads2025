#include <iostream>
#include <string>
using namespace std;

string real(string s){
    string res = "";
    for (int i = 0; i< s.size(); i++){
        if (s[i] != res.back()){
            res.push_back(s[i]);
        }
        else {
            res.pop_back();
        }
    }
    return res;
}

int main(){
    string a;
    cin >> a;
    
    if (real(a)== "")
        cout << "YES";
    else
        cout << "NO";
    return 0;
}