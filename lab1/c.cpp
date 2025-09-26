#include <iostream>
#include <string>
using namespace std;

string real(string s){
    string res;
    for (int i = 0; i< s.size(); i++){
        if (s[i] != '#'){
            res.push_back(s[i]);
        }
        else {
            res.pop_back();
        }
    }
    return res;
}

int main(){
    string a ,b;
    cin >> a >> b;
    
    if (real(a)== real(b)){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    
    
    return 0;
}