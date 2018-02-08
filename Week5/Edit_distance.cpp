#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using std::vector;
using std::string;

int Edit_distance(const string &a,const string &b){
	int n = a.size();
	int m = b.size();
	vector<vector<int>> D(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++){
		D[i][0]=i;
	}
	for(int j=0;j<=m;j++){
		D[0][j]=j;
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				D[i][j]=std::min(std::min(D[i-1][j],D[i][j-1]) + 1, D[i-1][j-1] + 0);
			}
			else
				D[i][j]=std::min(std::min(D[i-1][j],D[i][j-1]) + 1, D[i-1][j-1] + 1);
		}
	}
	return D[n][m];
}

int main() {
  string a;
  string b;
  std::cin >> a >> b;
  std::cout << Edit_distance(a, b) << std::endl;
  return 0;
}
