#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> res;

void subset(vector<int> nums, vector<int> &v, int pos){
	if(pos > nums.size()) return;
	res.push_back(v);

	for(int i=pos; i<nums.size(); i++){
		v.push_back(nums[i]);
		subset(nums, v, i+1);
		v.pop_back();
	}

}



int main(){
   vector<int> v ={1,2,3};
   vector<int> temp;
   subset(v, temp, 0);
   for(auto ele : res){
   	  for(int i=0; i<ele.size(); i++){
   	  	cout<<ele[i]<<" ";
   	  }
   	  cout<<endl;
   }
}