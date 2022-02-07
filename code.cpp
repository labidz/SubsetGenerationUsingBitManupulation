#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
const int N = 1e7+10;
map<string,int> sub_ct;

vector<vector<int> > generare_subsets(vector<int> arr){
	int n = arr.size();
	int sub_count = (1<<n);
	vector<vector<int> > all_subset;
	for(int mask = 0; mask < sub_count; ++mask){
		vector<int> subset;
		for(int i=0;i<n;++i){
			if(((1<<i) & mask)!=0){
				subset.push_back(arr[i]);
			}
		}
		all_subset.push_back(subset);
		sub_ct["total"]++;
	}
	return all_subset;
}
int main(){
	cout<<"Enter Size of the Array: ";
	int n; cin>>n;
	
	try{
		if(n <= 0){
			throw(0);
		}
	}catch(int x){
		cout<<"Invalid Array Size"<<endl;
		return 0;
	}
	
	vector<int> arr(n);
	cout<<"Enter the Array: ";
	for(int i=0;  i<n; ++i){
		cin>>arr[i];
	}
	
	cout<<"Subsets: ";
	vector<vector<int> > all_subsets = generare_subsets(arr);
	cout<<"Total Subsets: "<<sub_ct["total"]<<endl;
	
	for(int i=0;i<all_subsets.size();i++){
		for(int j=0;j<all_subsets[i].size();j++){
			cout<<all_subsets[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
