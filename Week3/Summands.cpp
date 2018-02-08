#include<iostream>
#include<vector>
using namespace std;
using std::vector;
vector<int> get_optimised_summand(int n){
    vector<int> get_summand;
    if(n<=2){
        get_summand.push_back(n);
    }
    else{
        int l=1;
        while(n > 2*l){
            get_summand.push_back(l);
            n-=l;
            l+=1;
        }
    get_summand.push_back(n);
    }
  return   get_summand ;
} 
int main(){
    int n;
    cin>>n;
    vector<int> get_summand=get_optimised_summand(n);
    cout << get_summand.size() << '\n';
    for (size_t i = 0; i < get_summand.size(); ++i) {
            cout << get_summand[i] << ' ';
        }
    return 0;
}