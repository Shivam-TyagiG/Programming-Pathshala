#include <iostream>
#include<vector>
using namespace std;

void prefix_maxi(vector<int> &arr, vector<int> &prefix_max, int& n)
{
	prefix_max[0]=arr[0];
	for(int i=1; i<n; i++)
	{
		prefix_max[i] = max(prefix_max[i-1], arr[i]);
	}
	return ;
}
void suffix_maxi(vector<int> &arr, vector<int> &suffix_max, int& n)
{
	suffix_max[n-1] = arr[n-1];
	for(int i=n-2; i>=0; i--)
	{
		suffix_max[i] = max(suffix_max[i+1], arr[i]);
	}
	return ;
}
int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	//first we find prefix max
	vector<int> prefix_max(n);
	prefix_maxi(arr, prefix_max, n);
	
	//Then we find suffix max
	vector<int> suffix_max(n);
	suffix_maxi(arr, suffix_max, n);
	

	long long int ans = 0;
	for(int i=1; i<n-1; i++)
	{
		int deciding_height = min(prefix_max[i-1], suffix_max[i+1]);
		if(deciding_height > arr[i])
		{
			ans+=(deciding_height-arr[i]);
		}
	}
	cout<<ans;
    return 0;
}