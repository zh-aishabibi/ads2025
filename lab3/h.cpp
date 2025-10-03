#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int which(vector<int> &p, int x){
    int low = 0, high = p.size()-1;
    while (low < high){
        int mid = (low+high)/2;
        if (p[mid] < x){
            low = mid+1;
        }
        else 
        high = mid;
    }
    return low;
}

int main(){
    int block, mistake;
    cin >> block >> mistake;
    vector<int> v(block);
    
    for (int i=0; i <block; i++){
        cin >> v[i];
    }
    int sum =0, m;
    vector <int> pref(block);
    for (int i=0; i < block ; i++){
        sum=  sum + v[i]; 
        pref[i] = sum;
    }
    
    for (int i=0; i < mistake; i++){
        cin >> m;
        cout << which(pref,m) +1 << endl;
    }
    return 0;
}