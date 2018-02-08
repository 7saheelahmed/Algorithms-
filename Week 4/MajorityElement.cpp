#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;
int majorityElement(vector<int> &a){
	sort(a.begin(),a.end());
	int count=0;
	int key=-1;
	for(size_t i=0;i<a.size();++i){
	    if(key==a[i]){
	        count++;
	    }
	    else{
	        key=a[i];
	        count=1;
	    }
	    if(count>a.size()/2){
	        return 1;        
	    }
	}
	  return -1;
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(size_t i=0;i<n;++i){
		cin>>a[i];
		}
	cout<<(majorityElement(a) != -1);
	return 0;
}