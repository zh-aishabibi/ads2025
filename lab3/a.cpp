#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    int arr[num];
    for(int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];

    for(int k = 0; k < num; k++) {
        int result_1 = -1, result_2 = -1;

        for(int i = 0; i < n; i++) {
            int low = 0, high = m - 1;
            bool increasing = matrix[i][0] < matrix[i][m-1];

            while(low <= high) {
                int mid = low + (high - low)/2;
                if(matrix[i][mid] == arr[k]) {
                    result_1 = i;
                    result_2 = mid;
                    break;
                }

                if(increasing) {
                    if(matrix[i][mid] > arr[k]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    if(matrix[i][mid] < arr[k]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }

            if(result_1 != -1) {
                break;
            }
        }

        if(result_1 == -1) {
            cout << "-1" << endl;
        } else {
            cout << result_1 << " " << result_2 << endl;
        }
    }
}