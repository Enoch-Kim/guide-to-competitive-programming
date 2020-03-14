/*
    2020-03-14 guide-to-competitive-programming
    WeirdAlgorithm
    https://cses.fi/problemset/task/1068
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void weirdAlgorithm(long long n) {
    while(n > 1){
        cout << n << " ";
        n = n % 2 ? 3 * n + 1 : n / 2;
    }
    cout << n << '\n';
}

int main(){
    long long n = 0;
    cin >> n;
    weirdAlgorithm(n);
}