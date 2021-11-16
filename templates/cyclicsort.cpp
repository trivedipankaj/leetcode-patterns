#include<iostream>
#include<vector>
using namespace std;

class CyclicSort{
public:
	static void sort(vector<int> &nums){
		int i=0;
		while(i < nums.size()){
			int j = nums[i] -1;
			if(nums[i] != nums[j]){
				swap(nums, i, j);
			}else{
				i++;
			}
		}	
	}

private:
	static void swap(vector<int> &v, int i, int j){
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;
	}
};


int main(){
 	vector<int> v ={2,3,1,4,5,7,6};
	CyclicSort::sort(v);	

	for(auto val : v){
		cout<<val<<" ";
	}
	cout<<endl;

}