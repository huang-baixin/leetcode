#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <map>
using namespace std;

#define INT_MAX      2147483647

int firstMissingPositiveImpl(int A[], int n) {
    int cand_val = 0;

    for (int i = 0; i < n; ++i) {
        cand_val = A[i];
        // 这里用涂色的方法来理解即可；每次进入while 就涂一次颜色，最后找的是最后一次没涂色的方
        while(cand_val > 0 && cand_val < n && cand_val != A[cand_val - 1]) {
            swap(A[i], A[cand_val - 1]);
            cand_val = A[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (A[i] != i+1) {
            return i + 1;
        }
    }

    return n + 1;
}

int firstMissingPositive(int A[], int n) {
    return firstMissingPositiveImpl(A, n);
}


void printArray(int a[], int n){
    cout << "[ ";
    for(int i=0; i<n-1; i++) {
        cout << a[i] << ", ";
    }
    cout << a[n-1] << " ]";
}

void Test(int a[], int n, int expected) {
    printArray(a, n);
    int ret = firstMissingPositive(a, n);
    cout << "\t   missed = " << ret << "  " << (ret==expected?"passed!":"failed!") << endl;
    //printArray(a, n);
    //cout <<endl;
}

int main()
{
#define TEST(a, e) Test(a, sizeof(a)/sizeof(int), e) 

    int a0[]={1};
    TEST(a0, 2);

    int a1[]={1,2,0};
    TEST(a1, 3);

    int a2[]={3,4,-1,1};
    TEST(a2, 2);

    int a3[]={1000,-1};
    TEST(a3, 1);

    int a4[]={1000, 200};
    TEST(a4, 1);

    int a5[]={2,5,3,-1};
    TEST(a5, 1);

    int a6[]={1, 100};
    TEST(a6, 2);

    int a7[]={7,8,9,11};
    TEST(a7, 1);

    int a8[]={4,3,2,1};
    TEST(a8, 5);

    return 0;
}
