#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using std::vector;

long long merge(vector<int> &A,vector<int> &temp,size_t left,size_t mid,size_t right){
	size_t i=left,j=mid,k=left;
	long long count=0;
	while(i<=mid-1 && j<=right){
		if(A[i]<=A[j]){
			temp[k]=A[i];
			i++;
			k++;
		}
		else{
			temp[k]=A[j];
			count+=mid-i;
			j++;
			k++;
		}
		
	}
	while(i<=mid-1){
		temp[k]=A[i];
		i+=1;
		k+=1;
	}
	while(j<=right){
		temp[k]=A[j];
		j+=1;
		k+=1;
	}
	for( i=left;i<=right;i++){
	    A[i]=temp[i];
	}
	return count;

}
long long no_of_inversions(vector<int> &A,vector<int> &temp,size_t left,size_t right){
	size_t number_of_inversions=0,mid=0;
	if(right<=left) return number_of_inversions;
	mid=left+(right-left)/2;
	number_of_inversions+=no_of_inversions(A,temp,left,mid);
	number_of_inversions+=no_of_inversions(A,temp,mid+1,right);
	number_of_inversions+=merge(A,temp,left,mid+1,right);
	return number_of_inversions;
}
int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); i++) {
    	cin >> A[i];
  }
  vector<int> temp(A.size());
  cout << no_of_inversions(A,temp,0,A.size()-1) << '\n';
  return 0;
}
