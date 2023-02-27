#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main() {
    // your code goes here
	int n;
	cin>>n;
	vector<int> prices(n);
	for(int i=0; i<n; i++) cin>>prices[i];
	
	long long t0_s0 = 0;
	long long t0_s1 = -1*prices[0];
	long long t1_s0 = INT_MIN;
	long long t1_s1 = INT_MIN;
	long long t2_s0 = INT_MIN;
	
	for(int i=1; i<n; i++)
	{
		long long nt0_s0, nt0_s1, nt1_s0, nt1_s1, nt2_s0;
		nt0_s0 = t0_s0;
		nt0_s1 = max(t0_s1, t0_s0-prices[i]);
		nt1_s0  = max(t1_s0, t0_s1+prices[i]);
		nt1_s1 = max(t1_s1, t1_s0-prices[i]);
		nt2_s0 = max(t2_s0, t1_s1+prices[i]);
		
		t0_s0 = nt0_s0;
		t0_s1 = nt0_s1;
		t1_s0 = nt1_s0;
		t1_s1 = nt1_s1;
		t2_s0 = nt2_s0;
	}
	cout<<max(t2_s0, max(t1_s0, t0_s0))<<endl;
    return 0;
}