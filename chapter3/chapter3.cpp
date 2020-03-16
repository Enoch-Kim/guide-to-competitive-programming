/*
    2020-03-16 guide-to-competitive-programming
    chapter3
    
*/

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

/*
    시간 복잡도 -> 알고리즘 레포 참고

    다음의 시간 복잡도는 O(2^n)이다
    void g(int n) {
        if( n==1) return;
        g(n-1);
        g(n-1);
    }

    O(2^n)과 O(n!)을 제외하면 다항 시간 알고리즘이라고 할 수 있다.
    NP-hard problem의 경우를 제외하면 다항 알고리즘으로 풀 수 있다.
*/

// 최대 부분 배열 합
// 배열 안의 연속인 값들의 합을 최대로 만들라

int calcContinueSum(vector<int>& input){
    int size = input.size();
    int sum = 0, result=0;
    bool prev;
    for(int i=0; i < size - 1; ++i){
        int data = input[i];
        sum = max(data, data + sum);
        result = max(result, sum);
    }
    return result;
}

// 퀸 배치
void chessQueen(vector<int>& col, vector<int>& diag1, vector<int>& diag2 , int& output, int n, int y){
    if(y == n){
        ++output;
    } else{
        for(int x = 0; x < n; ++x){
            if(col[x] || diag1[x + y] || diag2[x-y+n - 1]) continue;
            col[x] = diag1[x + y] = diag2[x-y+n - 1] = 1;
            chessQueen(col, diag1, diag2, output, n, y + 1);
            col[x] = diag1[x + y] = diag2[x-y+n - 1] = 0;
        }
    }
}

// -> 이 함수는 n^4이 나와 비효율적이다
/*
    퀸 배치는 경우의 수를 그룹화하여 점화식을 세우면 
    q(n) = n^4/2 - 5n^3/3 + 3n^2/2 - n/3
    이라는 O(1)의 해답을 얻을 수 있다.
*/

int main(){
    return 0;
}