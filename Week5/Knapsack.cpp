

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

using std::vector;

int KnapSack(int W, const vector<int> &w){
	vector<int>value(W+1);
	for(size_t i=0;i<w.size();++i){
		for(int j=W ; j-w[i]>=0 ;--j){
			value[j]=max(value[j],value[j-w[i]]+w[i]);
		}
	}

	return value[W];
}

int main(){
	int n, W;
  	cin >> W >> n;
  	vector<int> w(n);
  	for (int i = 0; i < n; i++) {
    	cin >> w[i];
  }
  	cout << KnapSack(W, w) << '\n';
  	return 0;
}