#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int xinm(int m, int x) {
    if(m == 0) return 0;
    int n = 0;
    int k = x;
    while(m % k == 0) {
        k *= x;
        n++;
    }
    return n;
}

int main() {
    int n;
    cin >> n;
    int arr[n][n][2];
    int zeroflag = 0;
    int zeroi;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j][0];
            if(arr[i][j][0] == 0) {
                zeroflag = 1;
                zeroi = i;
            }
            arr[i][j][1] = xinm(arr[i][j][0], 5);
            arr[i][j][0] = xinm(arr[i][j][0], 2);
            if(i == 0 && j == 0) {
            } else if(i == 0) {
                arr[i][j][0] += arr[i][j - 1][0];
                arr[i][j][1] += arr[i][j - 1][1];
            } else if(j == 0) {
                arr[i][j][0] += arr[i - 1][j][0];
                arr[i][j][1] += arr[i - 1][j][1];
            } else {
                if(arr[i - 1][j][0] < arr[i][j - 1][0]) {
                    arr[i][j][0] += arr[i - 1][j][0];
                } else {
                    arr[i][j][0] += arr[i][j - 1][0];
                }
                if(arr[i - 1][j][1] < arr[i][j - 1][1]) {
                    arr[i][j][1] += arr[i - 1][j][1];
                } else {
                    arr[i][j][1] += arr[i][j - 1][1];
                }
            }
        }
    }
    int k = 0;
    if(arr[n - 1][n - 1][0] > arr[n - 1][n - 1][1]) k = 1;
    if(zeroflag && arr[n - 1][n - 1][0] > 0 && arr[n - 1][n - 1][1] > 0) {
        cout << 1 << endl;
        for(int ii = 0; ii < zeroi; ii++) cout << 'D';
        for(int ii = 0; ii < n - 1; ii++) cout << 'R';
        for(int ii = zeroi; ii < n - 1; ii++) cout << 'D';
        return 0;
    }
    cout << arr[n - 1][n - 1][k] << endl;
    int x = n - 1, y = n - 1;
    char path[10000];
    int pi = 2 * (n - 1) - 1;
    while(x != 0 || y != 0) {
        if(x == 0) {
            y--;
            path[pi--] = 'R';
        } else if(y == 0) {
            x--;
            path[pi--] = 'D';
        } else {
            if(arr[x - 1][y][k] < arr[x][y - 1][k]) {
                x--;
                path[pi--] = 'D';
            } else {
                y--;
                path[pi--] = 'R';
            }
        }
    }
    for(int i = 0; i < 2 * (n - 1); i++) cout << path[i];
    cout << endl;
    return 0;
}
