#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>

using std::vector;
using std::string;
using std::max;
using std::min;
using std::numeric_limits;

long long operate(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long* Min_Max(int i, int j, const vector<char> &op, vector<vector<long long> > &m, vector<vector<long long> > &M) {
	long long Min = numeric_limits<long long>::infinity();
	long long Max = - numeric_limits<long long>::infinity();
	for(int k=i;k<j;k++) {
		long long a = operate(M[i][k], M[k+1][j], op[k]);
		long long b = operate(M[i][k], m[k+1][j], op[k]);
		long long c = operate(m[i][k], M[k+1][j], op[k]);
		long long d = operate(m[i][k], m[k+1][j], op[k]);
		Min = min(min(min(min(Min, a), b), c), d);
        	Max = max(max(max(max(Max, a), b), c), d);
		}
	static long long result[2];
	result[0] = Min;
	result[1] = Max;
	return result;
}

long long maximum_value(const string &s) {
	vector<char> op;
	vector<int> digit;
	for(int i=0;i<s.length();i++) {
		if(i%2 == 0) { // digit
			digit.push_back(s[i]-'0');
		}
		else { // operand
			op.push_back(s[i]);
		}
	}
	int n = digit.size();
	vector<vector<long long> > m(n, vector<long long>(n, 0));
	vector<vector<long long> > M(n, vector<long long>(n, 0));
	for(int i = 0;i<n;i++) {
		m[i][i] = digit[i];
		M[i][i] = digit[i];
	}
	for(int s=1;s<n;s++) {
		for(int i=0;i<n-s;i++) {
			int j = i+s;
			long long *t;
			t = Min_Max(i,j,op,m,M);
			m[i][j] = t[0];
			M[i][j] = t[1];
		}
	}
	return M[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << maximum_value(s) << '\n';
}
