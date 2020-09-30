// To find the kth smallest element in an array of numbers
// Time Complexity: O(N)

#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define F(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define ff first
#define ss second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define vi vector<int>
 
ll funmedian(ll a[],ll n)
{
    if(n<=5)
    {
        sort(a,a+n);
        return a[(n-1)/2];
    }
    ll median[n/5],sorti[5],i=0,k=0,j=0;
    while(i<n)
    {
        j=0;
        while(j<5&&i+j<n)
        {
            sorti[j]=a[i+j];
            j++;
        }
        sort(sorti,sorti+j);
        median[k++]=sorti[(j-1)/2];
        i+=j;
    }
    return funmedian(median,k);
}
ll fun(ll a[],ll n,ll x)
{
    if(x==1)
    {
        ll mini=a[0];
        F(i,0,n)
            mini=min(a[i],mini);
        return mini;
    }
    ll pivo=funmedian(a,n);
    ll right=0;
    ll left=0,b[n],c[n];
    F(j,0,n)
    {
        if(a[j]<pivo)
            b[left++]=a[j];
        else if(a[j]>pivo)
            c[right++]=a[j];
    }
    if(x==left+1)
        return pivo;
    else if (x>left+1)
    {
        ll ans=fun(c,right,x-left-1);
        return ans;
    }
    else
    {
        ll ans=fun(b,left,x);
        return ans;
    }
}
float pi=3.1415926535;
int main()
{
    // To increase input-output lag
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test_case = 1;

    while (test_case--) 
    {
        ll n,k;
        cin>>n>>k;
        ll a[n];
        F(i,0,n)
            cin>>a[i];
        ll ans=fun(a,n,k);
        cout<<ans<<endl;
    }
    return 0;
}
