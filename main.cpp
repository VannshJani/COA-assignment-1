#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

long long fibonaccirecursive(int n) {
    if (n <= 1)
        return n;
    return fibonaccirecursive(n - 1) + fibonaccirecursive(n - 2);
}

void fibonacciLoop(int n) {
    long long prev2 = 0; 
    long long prev1 = 1; 
    long long curr;
    for (int i = 0; i < n; ++i) {
        if (i <= 1)
            curr = i;
        else {
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        cout << curr << " ";
    }
}

vector<long long> memo(50, -1);

long long fibonacciMemo(int n) {
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = fibonacciMemo(n - 1) + fibonacciMemo(n - 2);
    return memo[n];
}

void fibonacciLoopMemo(int n) {
    vector<long long> fib(n);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    for (int i = 0; i < n; ++i)
        cout << fib[i] << " ";
}



int main() {
    // struct timespec start, end;
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    // for (int i = 0; i < 50; ++i)
    //     cout << fibonaccirecursive(i) << " ";
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    
    // // time taken in seconds
    // double time_taken = (end.tv_sec - start.tv_sec)+ (end.tv_nsec - start.tv_nsec)* 1e-9;
    // cout << "\nTime taken by recursive function is : " << fixed << time_taken << " seconds"<< endl;

    // time taken by loop
    // struct timespec start, end;
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    // fibonacciLoop(50);
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    // double time_taken = (end.tv_sec - start.tv_sec)+ (end.tv_nsec - start.tv_nsec)* 1e-9;
    // cout << "\nTime taken by loop function is : " << fixed << time_taken << " seconds"<< endl;

    // time taken by memoization
    // struct timespec start, end;
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    // for (int i = 0; i < 50; ++i)
    //     cout << fibonacciMemo(i) << " ";
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    // double time_taken = (end.tv_sec - start.tv_sec)+ (end.tv_nsec - start.tv_nsec)* 1e-9;
    // cout << "\nTime taken by recursive function with memoization is : " << fixed << time_taken << " seconds"<< endl;

    // time taken by loop memoization
    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    fibonacciLoopMemo(50);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_taken = (end.tv_sec - start.tv_sec)+ (end.tv_nsec - start.tv_nsec)* 1e-9;
    cout << "\nTime taken by loops with memoization is : " << fixed << time_taken << " seconds"<< endl;


    return 0;
}
