#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using std::vector ;


vector<int> optimal_sequence(int n){
	vector<int> sequence ;
	vector<int> temp(n+1);
	for(int i=1;i<temp.size();i++){
		temp[i]=temp[i-1]+1;
		if(i%2==0)
			temp[i]=min(1+temp[i/2],temp[i]);
		if(i%3==0)
			temp[i]=min(1+temp[i/3],temp[i]);
	}
	int i=n;
	while(i>1){
		sequence.push_back(i);
		if(temp[i-1]==temp[i]-1)
			i-=1;
		else if(i%2==0 && temp[i/2]==temp[i]-1)
			i/=2;
		else if(i%3==0 && temp[i/3]==temp[i]-1)
			i/=3;

	}
	sequence.push_back(1);
	reverse(sequence.begin(),sequence.end());
	return sequence;

}
int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}