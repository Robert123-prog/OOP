#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    ifstream fin("txt");
    ofstream fout("output");

    int x, a[10], n, i, numx, idx, j;
    fin >> x;
    numx = int(log10(x)) + 1;
    n = numx;

    for (i = 1;i <= n;i++){
        if (x > 0) {
            a[i] = x % 10;
            x /= 10;
        }
    }

    for (i = 1;i < n;i++){
        idx = i;

        for (j = i + 1;j <= n;j++){
            if (a[j] > a[idx]){
                idx = j;
            }
        }

        swap(a[i], a[idx]);
    }

    for (i = 1;i <= n;i++){
        cout << a[i] << " ";
    }

    for (i = 1;i <= n;i++){
        x = x * 10 + a[i];
    }

    cout << x;

}

