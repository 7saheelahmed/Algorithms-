#include <iostream>
#include <vector>
using namespace std;
using std::vector;
 
long long pisanoPeriod(long long m) {
    long long first = 0, second = 1, third = first + second;
    for (int i = 0; i < m * m; i++) {
        third = (first + second) % m;
        first = second;
        second = third;
        if (first == 0 && second == 1) return i + 1;
    }
}
long long get_fibonaccihuge(long long n, long long m) {
    long long periodlength = pisanoPeriod(m);
    long long patternRemain = n % periodlength;    
 
    //long long *sum = new long long[patternRemain];
 
    long long alpha = 0;
    long long beta = 1;
    long long result = patternRemain;
    for (int i = 1; i < patternRemain; i++)
    {
        result = (alpha + beta) % m;
        alpha=beta;
        beta=result;
    }   
    return result % m;
}
 
int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
}