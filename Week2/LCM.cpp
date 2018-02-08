#include <iostream>

long long gcd(long long a, long long b) {
  // write your code here
  // int current_gcd = 1;
  // for (int d = 2; d <= a && d <= b; d++) {
    // if (a % d == 0 && b % d == 0) {
      // if (d > current_gcd) {
        // current_gcd = d;
      // }
    // }
  // }
  // return current_gcd;
  	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << (a*b)/gcd(a, b) << std::endl;
  return 0;
}
