#include<iostream>
#include<vector>
using namespace std;
using std::vector;

int max_index(vector<int>weights,vector<int>values){
    int max_i=0;
    double max=0;
    for(int i=0;i<weights.size();i++){
        if(weights[i]!=0 && (double)values[i]/weights[i]>max){
            max=(double)values[i]/weights[i];
            max_i=i;
        }
    }
    
    return max_i;
}
double optimal_solution(int capacity,vector<int>weights,vector<int>values){
    double value=0.0;
    for(int i=0;i<weights.size();i++){
        if(capacity==0){
            return value;
        }
        int best_index=max_index(weights,values);
        int wgt_taken=min(capacity,weights[best_index]);
        value+=wgt_taken*(double)values[best_index]/weights[best_index];
        weights[best_index]-=wgt_taken;
        capacity-=wgt_taken;
    }
    return value;
}
int main(){
    int n,capacity;
    cin>>n>>capacity;
    vector<int>weights(n);
    vector<int>values(n);
    for(int i=0;i<weights.size();i++){
        cin>>values[i]>>weights[i];
        }
    double optimal_value=optimal_solution(capacity,weights,values);
    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}