



#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int least_common_subsequence3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int m = a.size();
	int n = b.size();
	int p = c.size();
	int L[m+1][n+1][p+1];
		
	for(int i=0; i<=m; i++) {
		for(int j=0; j<=n; j++) {
			for(int k=0; k<=p; k++) {
				if(i == 0 || j == 0 || k == 0)
					L[i][j][k] = 0;
				else if(a[i-1] == b[j-1] && a[i-1] == c[k-1])
					L[i][j][k] = L[i-1][j-1][k-1] + 1;
				else
					L[i][j][k] = max(max(max(max(max(L[i-1][j][k], L[i][j-1][k]), L[i][j][k-1]), L[i-1][j-1][k]), L[i-1][j][k-1]), L[i][j-1][k-1]);
			}
		}
	}
    return L[m][n][p];
}

int main() {
  size_t len1;
  std::cin >> len1;
  vector<int> a(len1);
  for (size_t i = 0; i < len1; i++) {
    std::cin >> a[i];
  }
  size_t len2;
  std::cin >> len2;
  vector<int> b(len2);
  for (size_t i = 0; i < len2; i++) {
    std::cin >> b[i];
  }
  size_t len3;
  std::cin >> len3;
  vector<int> c(len3);
  for (size_t i = 0; i < len3; i++) {
    std::cin >> c[i];
  }
  std::cout << least_common_subsequence3(a, b, c) << std::endl;
}
