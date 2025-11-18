#include <iostream>
#include <vector>
using namespace std;

// Memoization
int fibMemo (int n){
    vector <int> memo = {0,1};
    if (n < memo.size()) {
        return memo[n];
    }
    else {
        int f = fibMemo(n - 1) + fibMemo(n - 2);
        memo.push_back(f);
        return f;
    }
}

// Sin guardar el vector de resultados
int fibMemo2(int n){
    if (n <= 1) return n;
    else {
        int n1 = fibMemo2(n - 1), n2 = fibMemo2(n - 2), f;
        f = n1 + n2;
        n1 = n2;
        n2 = f;
        return f;
    }
}

// Tabulation
int fibTab(int n) {
    vector <int> f(n);
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

// Sin guardar el vector de resultados
int fibTab2(int n){
    if (n <= 1) return n;
    else {
        int n1 = 0, n2 = 1, f;
        for (int i = 2; i <= n; i++) {
            f = n1 + n2;
            n1 = n2;
            n2 = f;
        }
        return f;
    }
}



