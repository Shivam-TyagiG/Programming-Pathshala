#include <iostream>
#include<vector>
using namespace std;

void suffix_maxi(vector<int>& arr, vector<int> &suffix_max, int& n)
{
	suffix_max[n-1]=arr[n-1];
	for(int i=n-2; i>=0; i--)
	{
		suffix_max[i] = max(suffix_max[i+1], arr[i]);
	}
	return ;
}

int main() {
    // your code goes here
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	//we need to find suffix max
	vector<int> suffix_max(n,0);
	suffix_maxi(arr, suffix_max, n);
	int ans = -1;
	for(int i=0; i<n; i++)
	{
		ans = max(ans, suffix_max[i]-arr[i]);
	}
	cout<<ans<<endl;
    return 0;
}