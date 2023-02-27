#include <iostream>
#include<vector>
using namespace std;
int main() {
    // your code goes here
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	
	int maxi = INT_MIN;
	int count= 0; 
	for(int i=0; i<n; i++)
	{
		maxi = max(maxi, arr[i]);
		if(maxi == i) count++;
	}
	cout<<count<<endl;
    return 0;
}