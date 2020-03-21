/*
    2020-03-20 guide-to-competitive-programming
    chapter4
*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
ostream& operator<< (ostream& os, vector<T>& v){
    int size = v.size();
    os << '[';
    for(int i=0; i<size-1; ++i)
        os << v[i] << ", ";
    os << v[size-1] << "]";
    return os;
}

template<typename T>
ostream& operator<< (ostream& os, deque<T>& d){
    int size = d.size();
    os << '[';
    for(int i=0; i<size-1; ++i)
        os << d[i] << ", ";
    os << d[size-1] << "]";
    return os;
}


int main() {
    vector<int> v(10,2);
    for(auto x : v)
        cout << x << "\n";
    v = {1, 3, 2, 5, 1,3 ,5, 3,2 ,8, 7};
    cout << v.back() << "\n";
    cout << v.back() << "\n";
    v.pop_back();
    cout << v.back() << "\n";

    reverse(begin(v), end(v));
    cout << v << "\n";
    sort(v.begin(), v.end());
    cout << v << "\n";
    sort(rbegin(v), rend(v));
    cout << v << "\n";

    cout << *v.begin() << "\n";

    sort(v.begin(), v.end());
    // 정렬된 배열에서 이진탐색으로 찾아내는 함수
    auto a = lower_bound(begin(v), end(v), 3); // 3 이상 첫번째
    auto b = upper_bound(begin(v), end(v), 6);  // 6 이하 첫번째
    cout << *(lower_bound(begin(v) , end(v), 3)) << '\n';  // 왜 안되는 걸까? 흠... => sort가 오름차순으로 돼야한다
    cout << *(upper_bound(begin(v), v.end(), 6)) << '\n';   
    cout << *a << "   " << *b << '\n';
    
    deque<int> d;
    d.push_back(5);
    cout << d << "\n";
    d.push_back(2);
    d.push_front(3);
    cout << d << "\n";
    d.pop_back();
    cout << d << "\n";
    d.pop_front();
    cout << d << "\n";

    stack<int> s;
    s.push(2);
    s.push(3);
    cout << s.top() << '\n';
    cout << s.size() << '\n';
    s.pop();
    cout << s.size() << '\n';
    cout << s.top() << '\n';
    s.pop();
    cout << s.size() << '\n';
    // cout << s.top() << '\n'; -> 값이 없으니 여기서 끊김...
    
    cout << "---------------------------------------" << '\n';

    queue<int> q;
    q.push(20);
    q.push(3);
    q.push(32);
    cout << q.front() << '\n';
    q.pop();
    cout << q.front() << '\n';
    cout << q.back() << '\n';

    cout << "---------------------------------------" << '\n';

    set<int> se;    // 이진트리 기반 집합구조 O(logn)
    se.insert(3);
    se.insert(3);
    se.insert(4);
    se.insert(5);
    se.insert(8);
    cout << se.count(1) << '\n';
    cout << se.count(2) << '\n';
    cout << se.count(3) << '\n';    // set 은 오직 있냐 없냐만 저장
    cout << se.count(4) << '\n';
    se.erase(3);
    cout << se.count(3) << '\n';
    auto ses = se.find(6);
    if(ses == se.end())
        cout << "6 not found" << '\n';
    auto first = se.begin();
    auto last = se.end();
    --last;
    cout << *first << '\n'; // 2진트리 기반이므로 최솟값
    cout << *last << '\n';  // 2진트리 기반이므로 최댓값
    cout << *se.lower_bound(7) << '\n';
    cout << *se.upper_bound(3) << '\n';

    cout << "---------------------------------------" << '\n';

    unordered_set<int> unse;        // 해시함수 기반 -> O(1)
    unse.insert(3);
    unse.insert(3);
    unse.insert(4);
    unse.insert(5);
    cout << unse.count(1) << '\n';
    cout << unse.count(2) << '\n';
    cout << unse.count(3) << '\n';    // unordered_set 은 오직 있냐 없냐만
    cout << unse.count(4) << '\n';
    unse.erase(3);
    cout << unse.count(3) << '\n';

    cout << "---------------------------------------" << '\n';

    multiset<int> m;    // 이진트리기반 => O(logn)
    m.insert(3);
    m.insert(3);
    m.insert(4);
    m.insert(5);
    m.insert(8);
    cout << m.count(1) << '\n';
    cout << m.count(2) << '\n';
    cout << m.count(3) << '\n';    // multiset 은 개수 저장
    cout << m.count(4) << '\n';
    m.erase(3);
    cout << m.count(3) << '\n';
    auto firstm = m.begin();
    auto lastm = m.end();
    --lastm;
    cout << *firstm << '\n'; // 2진트리 기반이므로 최솟값
    cout << *lastm << '\n';  // 2진트리 기반이므로 최댓값
    cout << *m.lower_bound(7) << '\n';
    cout << *m.upper_bound(3) << '\n';

    cout << "---------------------------------------" << '\n';

    unordered_multiset<int> unm;    // 해시함수 기반 => O(1)
    unm.insert(3);
    unm.insert(3);
    unm.insert(4);
    unm.insert(5);
    cout << unm.count(1) << '\n';
    cout << unm.count(2) << '\n';
    cout << unm.count(3) << '\n';    // unordered_multiset 은 개수 저장
    cout << unm.count(4) << '\n';
    unm.erase(3);
    cout << unm.count(3);

    cout << "---------------------------------------" << '\n';

    map<string, int> mm;    // 이진 탐색 기반 (Ologn) -> unordered_map 해시 함수 기반 O(1)
    mm["a"] = 4;
    mm["b"] = 3;
    mm["3"] = 3323;
    cout << mm["a"] << '\n';
    cout << mm["b"] << '\n';
    cout << mm["c"] << '\n'; // 없는건 즉각 키를 만들고 default값 대입
    if(mm.count("a"))
        cout << "key exist" << '\n';
    if(mm.count("d"))
        cout << "key exist" << '\n';
    else 
        cout << "key not exist" << '\n';

    for(auto x : mm)
        cout << x.first << "," << x.second << '\n';

    cout << "---------------------------------------" << '\n';

    priority_queue<int> qq; // 원소의 추가, 탐색, 삭제연산이 있는 멀티셋 -> 탐색 및 삭제의 대상이 되는 원소는 최대 혹은 최소
                            // 추가에 O(logn) 탐색 및 삭제 O(1)
    qq.push(3);
    qq.push(5);
    qq.push(7);
    qq.push(2);
    cout << q.top() << '\n';
    qq.pop();
    qq.push(6);
    cout << q.top() << '\n';
    qq.pop();
    for(auto x : qq)
        cout << x << '\n';
    priority_queue<int, vector<int>, greater<int> > qqq;    // 원소 탐색 및 삭제를 최소 원소에 대해 할 수 있음

    string s;
    getline(cin, s);
    cout << s << endl;
    getline(cin, s);
    cout << s << endl;

    // 정책 기반 집합 => 생략
    // 성능 비교 -> 생략
}