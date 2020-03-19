/*
    2020-03-18 guide-to-competitive-programming
    chapter4
*/

#include <bits/stdc++.h>
using namespace std;

ostream& operator<< (ostream& os, vector<pair<int, int> >& v){
    int size = v.size();
    os << '[';
    for(int i=0; i<size-1; ++i)
        os << '(' << v[i].first << "," << v[i].second << "), ";
    os << '(' << v[size - 1].first << "," << v[size - 1].second << ")]";
    return os;
}


template<typename T>
ostream& operator<< (ostream& os, vector<T>& v){
    int size = v.size();
    os << '[';
    for(int i=0; i<size-1; ++i)
        os << v[i] << ", ";
    os << v[size-1] << "]";
    return os;
}

void printArray(int* arr, int size){
    cout << '[';
    for(int i = 0; i<size - 1; ++i)
        cout << arr[i] << ", ";
    cout << arr[size - 1] << "]\n";
}

// 삽입 정렬 (insert sort)
void insertSort(vector<int>& arr){
    int size = arr.size();
    for(int i = 0, j = 0, cur = 0; i<size; ++i){
        j = i; cur = arr[i];
        while(--j >= 0 && arr[j] > cur){
            arr[j+1] = arr[j];
            arr[j] = cur;
        }
    }
}

// 버블 정렬 (bubble sort)
void bubbleSort(vector<int>& arr) {
    int size = arr.size();
    for(int i=0; i<size-1; ++i){
        for(int j=i; j<size-1; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
                
        }
    }
}


// 병합 정렬 (merge sort)
void merge(vector<int>& arr, int left, int right, int mid){
    int size = right - left + 1;
    vector<int> arr2(size);
    int i = left,
        j = mid + 1,
        count = 0,
        spare = 0;
    
    while(i <= mid && j <= right){
        arr2[count++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    
    spare = (i == mid + 1) ? j : i;
    while(count <= size)
        arr2[count++] = arr[spare++];
    i = left;
    j = 0;
    while(i <= right)
        arr[i++] = arr2[j++];
}

void mergeSort(vector<int>& arr, int left, int right){
    int mid = (left + right) / 2;
    if(left == right)
        return;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, right, mid);
    
}

// 계수 정렬 (countingSort) -> 해시 맵과 유사
void countingSort (vector<int>& arr, const int MAX_VALUE){
    vector<int> arr2(MAX_VALUE);
    int size = arr.size();
    for(int i =0; i<size; ++i)
        ++arr2[arr[i]-1];
    for(int i=0, j=0; i < MAX_VALUE; ++i){
        while(arr2[i]--) 
            arr[j++] = i + 1;
        if(j == size - 1)
            break;
    }
}

/*
    스윕 라인 알고리즘 (sweep line algorithm)
    정렬된 순서대로 처리되는 이벤트의 집합으로 문제를 모델링하는 방법

    이진탐색 (생략)

    최적해 구하는 예제
    n대의 기계가 한개의 일을 하는데 드는 시간이 Pi라고 한다.
    최소 시간이 y 시간이고
    k개의 task를 처리해야한다고 하면,
      
*/
void getOptimalTime(vector<int>& p, int k, int y){
    int size = p.size(),
        x = y,
        taskSum = 0;

    while(taskSum < k ){
        taskSum = 0;
        for(int i = 0; i<size; ++i)
            taskSum += (x / p[i]);
        ++x;
    }
    cout << "Optimal time is " << x-1 << '\n';
}

int main(){
    vector<int> arr0{1, 3, 6, 2, 8, 2, 5, 9};
    insertSort(arr0);
    cout << arr0 << '\n';
    vector<int> arr1{1, 3, 6, 2, 8, 2, 5, 9};
    bubbleSort(arr1);
    cout << arr1 << '\n';
    vector<int> arr2{1, 3, 6, 2, 8, 2, 5, 9};
    mergeSort(arr2, 0, arr2.size()-1);
    cout << arr2 << '\n';
    vector<int> arr3{1, 3, 6, 2, 8, 2, 5, 9};
    countingSort(arr3, 10);
    cout << arr3 << '\n';
    
    // 표준이 짱이다
    vector<int> arr4{1, 3, 6, 2, 8, 2, 5, 9};
    sort(arr4.begin(), arr4.end());     // 이게 갑임
    cout << arr4 << '\n';
    sort(arr4.rbegin(), arr4.rend());
    cout << arr4 << '\n';

    int* arr5 = new int[10]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sort(arr5, arr5 + 10);
    printArray(arr5, 10);
    string s = "sfjdlsjfklsdfdsfmlsd";
    sort(s.begin(), s.end());
    cout << s << '\n';

    vector<pair<int,int> > v;
    v.push_back({2,1});
    v.push_back({1,5});
    v.push_back({2,3});
    v.push_back({1,2});
    sort(v.begin(), v.end());   // key -> value 순으로 정렬
    cout << v << '\n';
    // 튜플의 경우도 비슷
    
    vector<int> p{2, 3, 7};
    getOptimalTime(p, 8, 9);
    vector<int> p1{2, 3, 14};
    getOptimalTime(p1, 8, 9);
    vector<int>p2{3, 2, 5, 9};
    getOptimalTime(p2, 13, 10);

    return 0;
}