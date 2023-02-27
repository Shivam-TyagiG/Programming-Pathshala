#include <iostream>
#include<vector>
using namespace std;

void rotate(vector<int> &arr, int i, int j)
{
	while(i<j)
	{
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
}

int main() {
    int n,k;
	cin>>n>>k;
	
	if(k>n)
	{
		k=k%n;
	}
	
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	
	rotate(arr, n-k, n-1);
	rotate(arr, 0, n-k-1);
	rotate(arr, 0, n-1);
	
	for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return 0;
}