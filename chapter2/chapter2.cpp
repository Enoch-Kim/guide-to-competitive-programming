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

/*
    2.3 비트연산
    음의 부호인 경우
    -x 는 unsigned의 2^n -x와 같다
    그 이유는 보수를 취할 때 모든 비트를 뒤집고 +1 을 해주기 때문이다.
    이 때문에 ~x = -x -1이 성립한다.(부호가 있는경우)
    AND & OR | XOR ^ NOT ~
    & 의 경우 나누어 떨어지는지를 알 수 있다. 
    x & (2^k - 1) = 0 이라면 2^k로 나누어 떨어진다는 것이다.
    x & 1 이 0이라면 짝수 1이라면 홀수

    비트 시프트 연산
    왼쪽 시프트 x << k 의 경우 x의 오른쪽에 비트 0을 k개 더하는 것이다.
    오른쪽 시프트 x >> k 의 경우 x를 오른쪽에서부터 비트를 k개 제거하는 것이다.

    비트마스크
    비트마스크 1 << k는 k번째 위치에만 비트가 1이 있고 나머지 위치의 비트는 모두 0인 정수이다.
    그러므로 비트마스크를 사용하여 정수의 특정한 비트 하나에 접근할 수 있다.
    x & (1 << k) != 0 이라면 이 정수 x의 k번째 비트의 값이 1이라는 것이다.
    이를 활용하여 2진법을 표현할 수 있다.
    for(int k = 31; k>=0; k--){
        if(x&(1<<k)) cout << '1';
        else cout << '0';
    }
    이 외에도 
    x | (1 << k) 비트를 수정하는 공식
    x ^ (1 << k) 비트를 뒤집는 공식
    x & ~(1 << k) k번째 비트를 0으로 바꾸는 공식
    x & (x - 1) 가장 오른쪽 비트를 1을 0으로 바꾸는 공식
    x & -x 정수 x의 모든 비트를 0으로 바꾸되 비트 1중에서 제일 오른쪽 것만 하나 남기는 ㅗㅇ식
    x | (x - 1) 마지막 비트 1 다음에 나오는 모든 비트를 뒤집는 공식
    양의정수 x & (x -1) == 0 이라면 x는 2의 거듭제곱이다.
    => 비트마스크는 기본적으로 1 << k가 int형이므로 
    long long 의 경우 1LL << k 를 이용해야 한다.

    g++ 컴파일러는 비트 수를 셀 때 사용할 수 있는 다음과 같은 함수를 제공한다.
    __builtin_clz(x) 비트 표현의 왼쪽에 연속해서 있는 비트 0의 개수
    __builtin_ctz(x) 비트 표현의 오른쪽에 연속해서 있는 비트 0의 개수
    __builtin_popcount(x) 비트 표현에서 비트 1의 개수
    __builtin_parity(x) 비트 표현에서 비트 1의 개수에 대한 패리티(Parity, 짝수 혹은 홀수)
    이들은 int형을 지원하며 함수 뒤에 ll을 넣으면 long long이 지원된다.

    0 ~ n-1 의 집합의 부분집합을 int로 표현할 수 있다.
    예를들어 0 ~ 31의 모든 부분집합을 표현할 때, 포함된 것을 1로 표현하면 된다.
    그리고 1, 3, 4, 8을 부분집합에 포함한 후 집합의 크기를 출력하려면 다음과 같이 하면 된다.
    int x = 0; 
    x |= (1<<1);
    x |= (1<<3);
    x |= (1<<4);
    x |= (1<<8);
    cout << __builtin_popcount(x) << "\n"; // 4
    그리고 다음 코드는 집합에 포함된 원소를 모두 출력하는 코드이다.
    for (int i = 0; i < 32; i++){
        if(x&(1<<i)) cout << i << " ";
    }// 1 3 4 8

    집합에 대한 연산은 더욱 쉽다
    교집합 a & b
    합집합 a | b
    여집합 ~a
    차집합 a & (~b)

    부분집합 검사도 가능하다 0 ~ n-1까지의 부분집합을 검사하려면
    for(int b=0; b < (1<<n); ++b){
        // 부분집합 b를 처리
    }

    부분집합 중 원소의 개수가 정확히 k개인것만 살펴보는 코드
    for(int b = 0; b < (1<<n); ++b){
        if(__builtin_popcount(b) == k){
            // operate
        }
    }

    집합 x의 모든 부분집합을 차례로 살펴보는 코드
    int b = 0;
    do{
        // 부분집합 b를 처리한다.
    } while (b=(b - x) & x);

    cpp bitset
    cpp표준 라이브러리 비트셋은 원소가 0 또는 1인 배열과 같이 쓸 수있다.
    bitset<10> s;
    s[1] = 1;
    s[3] = 1;
    s[4] = 1;
    s[7] = 1;
    cout << s[4] << "\n";
    cout << s[5] << "\n";

    count는 비트 1의 개수를 반환
    cout << s.count() << "\n";
    
    비트 연산 적용도 가능
    bitset<10> a,b;
    bitset<10> c = a&b;
    bitset<10> d = a|b;
    bitset<10> e = a^b;

*/

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

    // int size = 5;
    // vector<int> col(size), diag1(2*(size - 1)), diag2(2*(size - 1));
    // vector<vector<int> > output(size, vector<int>(size));
    // chessQueen(col, diag1, diag2, output, size, 0);

}


