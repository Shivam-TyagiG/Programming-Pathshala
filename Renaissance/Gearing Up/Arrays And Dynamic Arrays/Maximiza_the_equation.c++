#include <climits>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void suffix_maxi(vector<long long int> &arr, vector<long long int> &suffix_max, long long int &n, long long int &r)
{
    suffix_max[n-1] = r*arr[n-1];
    for(long long int i=n-2; i>=0; i--)
    {
        suffix_max[i] = max(suffix_max[i+1], r*arr[i]);
    }
    return ;
}

void prefix_maxi(vector<long long int>& arr, vector<long long int> &prefix_max, long long int &n, long long int &p)
{
    prefix_max[0] = p*arr[0];
    for(long long int i=1; i<n ;i++)
    {
        prefix_max[i] = max(prefix_max[i-1], p*arr[i]);
    }
    return ;
}

int main()
{
    long long int n, p, q, r;
    cin>>n>>p>>q>>r;
    vector<long long int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    //Now we find prefix max to maximize it
    vector<long long int> prefix_max(n);
    prefix_maxi(arr, prefix_max, n, p);

    //Now we find the suffix max to maximize the expression we need maximum
    vector<long long int> suffix_max(n);
    suffix_maxi(arr, suffix_max, n, r);


    long long int ans = LLONG_MIN;
    for(int i=0; i<n; i++)
    {
        ans = max(ans, prefix_max[i]+ q*arr[i] + suffix_max[i]);
    }
    cout<<ans<<endl;
    return 0;
}
