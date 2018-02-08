#include<iostream>
#include <cassert>
#include <vector>
#include <math.h> 
#include <algorithm> 

using namespace std;

int BinarySearch(const vector<int> &A,int low, int high,int key){
	
	if(high<low)
		return -1;
	else{
	    int mid=low+(high-low)/2;
	    if(A[mid]==key)
		    return mid;
	    else if(A[mid]<key)
		    return BinarySearch( A,mid+1,high,key);
	    else
		    return BinarySearch(A,low,mid-1,key);
	}
    return -1;
}
int main(){
	int n,m;
	cin>>n;
	vector<int>A(n);
	for(size_t i=0;i<A.size();i++){
		cin>>A[i];
	}
	cin>>m;
	vector<int>B(m);
	for(size_t i=0;i<m;i++){
		cin>>B[i];
	}
	sort(A.begin(),A.end());
	for(size_t i=0;i<m;++i){
		cout<<BinarySearch(A,0,A.size()-1,B[i])<<' ';
	}
	return 0;
}	