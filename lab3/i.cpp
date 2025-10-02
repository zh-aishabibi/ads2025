#include <iostream>
using namespace std;

bool have(int arr[], int n, int k){
    bool h = false;
    int low = 0; int high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if (arr[mid] == k){
            h = true;
            break;
        }
        else if (arr[mid] > k){
            high = mid-1;
            
        }
        else low = mid+1; 
    }
    return h;
}

int main(){
    int n ,k ;
    cin >> n; int arr[n];
    for (int i=0; i <n; i++){
        cin >> arr[i];
    }
    cin >> k;
    if(have(arr, n , k)) cout << "Yes";
    else cout << "No";
}