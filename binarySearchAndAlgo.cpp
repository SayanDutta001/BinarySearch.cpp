#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> 
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)      substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x)        cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count()); 

// Binary Search can be used in any search space that is montonic in nature i.e either strictly increasing or
// strictly decreasing

// Find Closest Element: 
// Closer to left
// max index : a[i]<=x
int closertoLeft(vector<int>&a, int target)
{
    int low = -1;
    int high = a.size();
    int mid;
    while(low+1<high)
    {
        mid = (low+high)>>1;
        if(a[mid]<=target)
            low = mid; 
        else
            high = mid;
    }
    return low;
}

// Closer to Right
// min i : a[i]>=x also known as lower bound
// Lower Bound : Used to find element which is greater than or equal to target Value.
// So we move the high pointer to the mid Index if we find a[mid]<target
// And if a[mid]>=target we move the low pointer to mid Index
// Once the terminating condtition for while loop is reached we come out of the loop and return the high Index
int Lbound(vector<int>&a,int target)
{
    int low = -1;
    int high = a.size();
    int mid;
    while(low+1<high)
    {
        mid = (low+high)>>1;
        if(a[mid]<target)
            low = mid; 
        else
            high = mid;
    }
    return high; // return low if a[i] < target
}

// a[i] > x -> Reciprocal of Closer to left. Only thing that will get changed is the return value.
// Upper Bound :Used to find elements that are greater than the Target Value
// We require two pointers high and low, we move the low pointer until we find a value that is greater than the 
// target value and once we reach the condition we return the index high.
int Ubound(vector<int>&a, int target)
{
    int low = -1;
    int high = a.size();
    int mid;
    while(low+1<high)
    {
        mid = (low+high)>>1;
        if(a[mid]<=target)
            low = mid; 
        else
            high = mid;
    }
    return high; // return low ; if you need a[i] <= target
}


// Q. Find the first occurence of an element in an array
int firstOccurence(vector<int>&a,int target)
{
    int ind = lower_bound(a.begin(), a.end(),target) - a.begin();
    if(a[ind]==target)
        return ind;
    return -1;
}

// Q. Find the last occurence of any element in an array
int lastOccurence(vector<int>&a,int target)
{
    int ind = upper_bound(a.begin(), a.end(),target) - a.begin();
    ind--;
    if(ind>=0 and a[ind]==target)
        return ind;
    return -1;
}

// Q. Largest Number Smaller than the Target
int lsT(vector<int>&a,int target)
{
    int ind = lower_bound(a.begin(), a.end(),target) - a.begin();
    ind--;
    if(ind>=0)
        return ind;
    else
        return -1;
}

// Q. Smallest Number Larger than the Target
int slT(vector<int>&a,int target)
{
    int ind = upper_bound(a.begin(), a.end(),target) - a.begin();
    if(ind<a.size())
        return ind;
    else
        return -1;
}

int32_t main()
{
	FIO;
    #ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif

    int n;
    cin>>n;

    vector<int>a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    // STL functions for binary Seach, it's other algorithms and applications -> TC:O(logN) for every algorithm
    bool res = binary_search(a.begin(), a.end(),4);
    cout<<((res==1)?"present":"not present")<<"\n";

    res = binary_search(a.begin(), a.end(),6);
    cout<<((res==1)?"present":"not present")<<"\n";

    int ind = lower_bound(a.begin(), a.end(),4) - a.begin(); // lower_bound returns an address
    cout<<"index: "<<ind<<" "<<",a[ind]: "<<a[ind]<<"\n";

    ind = upper_bound(a.begin(), a.end(),4) - a.begin(); // upper bound returns an address
    cout<<"index: "<<ind<<" "<<",a[ind]: "<<a[ind]<<"\n";

    int target;
    cin>>target;
    int fo = firstOccurence(a,target); // can be found out by lower bound
    if(fo != -1)
        cout<<"First occurence of "<<target<<" is at index :"<<fo<<"\n";
    else
        cout<<"Not present\n";

    cin>>target;
    fo = lastOccurence(a,target); // can be found out by upper bound
    if(fo != -1)
        cout<<"Last occurence of "<<target<<" is at index :"<<fo<<"\n";
    else
        cout<<"Not present\n";

    cin>>target;
    fo = lsT(a,target); // largest number smaller than the target val
    if(fo != -1)
        cout<<"Largest Element smaller than "<<target<<" is at index :"<<fo<<"\n";
    else
        cout<<"Not present\n";

    cin>>target;
    fo = slT(a,target); // smallest number larger than the target val
    if(fo != -1)
        cout<<"Smallest Element grater than "<<target<<" is at index :"<<fo<<"\n";
    else
        cout<<"Not present\n";
    return 0;
}
