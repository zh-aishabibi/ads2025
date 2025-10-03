#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,long long> sum(vector<int> &v, int n, int power){
    int low =0, high = v.size()-1, unt=0, sum=0;
    while(low <= high){
        int mid = (low+high)/2;
        if(v[mid] <= power){
            unt = mid+1;
            low = mid + 1;
        }
        else if (v[mid] > power){
            high = mid-1;
        }
    }
    for (int i =0; i < unt; i++){
        sum = sum +v[i];
    }
    return make_pair(unt, sum);
}

int main() {
	int n,rounds, power;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i <n; i++){
	    cin >> v[i];
	}
    sort(v.begin(), v.end());
    
    cin >> rounds;
    for (int i=0; i < rounds; i++){
        cin >> power;
        pair<int,long long> result = sum(v,n, power);
        cout << result.first << " " << result.second << "\n";
    }
    return 0;
}