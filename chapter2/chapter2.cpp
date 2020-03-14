/*
    2020-03-14 guide-to-competitive-programming
    chapter2
    
*/

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

/*
    2.1.1 입력과 출력
    ios_base::sync_with_stdio(0); cin.tie(0);   -> 입력과 출력 프로그래밍 병목 발생 저하
    int a, b;
    읽어오기
    scanf("%d %d", &a, &b);
    출력하기
    printf("%d %d\n", &a, &b);

    공백을 포함한 채로 읽어올 때 
    string s;
    getline(cin, s);
     
    데이터의 양을 모를 때
    while(cin >> x) {}

    입력과 출력을 위해 파일을 사용할 때
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/

/*
    2.1.2 수를 처리하는 방법
    int 4byte (32bit)
    -2^31 ~ 2^31 - 1
    long long 8byte(64bit)

    int a = 123456789;
    long long b = a * a;
    cout << b << '\n'; // -1757895751
    위에서 int형을 곱했기 때문에 int 형으로 변환된다.

    g++ 컴파일러는 128bit 자료형인 __int128_t를 지원한다.

    나머지 연산
    매우 큰 정수도 모듈로(modulo) m 으로 구해도 될때가 있다. 나머지?
    이런 경우에는 답이 매우 크더라도 int나 long long으로 표현 가능하다.
    x를 m으로 나눈 나머지가 x mod m이라 할 때, 다음이 성립한다.
    (a + b) mod m = (a mod m + b mod m) mod m
    (a - b) mod m = (a mod m - b mod m) mod m
    (a * b) mod m = (a mod m * b mod m) mod m
    이를 이용하면 n!을 m으로 나눈 나머지를 계산하기 쉽다.
    음수 나머지를 처리하는 방법은 m만큼 더해주는 것이다

    부동소수점 실수
    만약 부동소수점을 다뤄야하는데 double로 부족하다면 long double(g++)을 사용하라
    부동소수점을 출력하는 간단한 방법은 printf("%.9f", x); 이다
    부동소수점 일치를 판단할 때는 다음과 같이 일정 e보다 작으면 일치하게 판단시키는 것이다.
    if(abs(a - b) < 1e-9){
        // a and b are equal;
    }
    double 의 경우 절댓값이 2^53 이하인 모든 정수를 정확하게 표현할 수 있다.
*/

/*
    2.1.3 코드 짧게 만들기
    자료형
    typedef를 통해 자료형 이름을 줄일 수 있다.
    typedef long long ll;
    ll a = 1123231232;
    typedef vector<int,int> vii;
    vii v1;

    매크로
    #define F first
    f.first -> f.F    별로 안좋은 습관이 될 것 같다.
    #define REP(i,a,b) for (int i = a; i <= b; i++)
    REP(i,1,n){
        search(i);
    }
*/


// 재귀적 알고리즘

/*
    2.2.1 부분집합 생성하기
    vector<int> subset;
*/
int i = 1;
void search(int k, vector<int>& subset) {
    int n = 5;
    if(k == n+1){
        int size = subset.size();
        cout << i++ << "'th" << '\n';
        if(size == 0) return;
        cout << "{";
        for(int i=0; i<size; ++i){
            if(i != size - 1)
                cout << subset[i] << ", ";
            else
                cout << subset[i] << "}\n";
        }
    } else {
        // k를 부분집합에 포함시킨다.
        subset.push_back(k); 
        search(k+1, subset);
        subset.pop_back();
        // k를 부분집합에 포함시키지 않는다.
        search(k+1, subset);
    }
}

/*
    2.2.2 순열 생성하기
    원소가 n개인 집합의 모든 순열을 생성하는 알고리즘
*/
void search2(vector<int>& v, vector<bool>& chosen, int size){
    int n = v.size();
    if(n == size){
        cout << "(";
        for(int i=0; i<n; ++i){
            if(i != n-1)
                cout << v[i] << ", ";
            else
                cout << v[i] << ")\n";
        }
    } else {
        for(int i = 0; i < size; ++i){
            if(chosen[i]) continue;
            chosen[i] = true;
            v.push_back(i + 1);
            search2(v, chosen, size);
            chosen[i] = false;
            v.pop_back();
        }
    }

}

/*
    2.2.3 퇴각 검색 (Backtracking)
    

*/
void chessQueen(vector<int>& col, vector<int>& diag1, vector<int>& diag2 , vector<vector<int>>& output, int n, int y){
    if(y == n){
        for(int y = 0; y < n; ++y){
            for(int x = 0; x < n; ++x)
                cout << (output[y][x] ? 'X' : 'O') << ' ';
            cout << '\n';
        }
        cout << '\n';
    } else{
        for(int x = 0; x < n; ++x){
            if(col[x] || diag1[x + y] || diag2[x-y+n - 1]) continue;
            col[x] = diag1[x + y] = diag2[x-y+n - 1] = 1;
            output[y][x] = 1;
            chessQueen(col, diag1, diag2, output, n, y + 1);
            col[x] = diag1[x + y] = diag2[x-y+n - 1] = 0;
            output[y][x] = 0;
        }
    }
}

int main() {

    int a = 123456789;
    long long b = a * a;
    cout << b << '\n';  // -1757895751
    long long c = (long long)a * a; // (long long)(a * a); 는 안된다
    cout << c << '\n';  // -1757895751
    int n, m;
    cin >> n >> m;
    long long x = 1;
    for(int i = 1; i <= n; ++i)
        x = (x * i) % m;
    if(x<0) x += m;         // 음수일 경우 양수로 변환
    cout << x << '\n';
    vector<int> subset{};
    search(1, subset);

    vector<int> permutation{};
    vector<bool> chosen{};
    chosen.resize(3);
    search2(permutation, chosen, chosen.size());

    int size = 5;
    vector<int> col(size), diag1(2*(size - 1)), diag2(2*(size - 1));
    vector<vector<int> > output(size, vector<int>(size));
    chessQueen(col, diag1, diag2, output, size, 0);
\
}


