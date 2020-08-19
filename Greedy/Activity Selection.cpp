https://practice.geeksforgeeks.org/problems/activity-selection/0


#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
const int N=3e5+10;
int mod=1000000007;
const int inf=1e9+1;


int power(int a,int b) {int ans=1; while(b){if(b&1)ans=(ans*a)%mod;b/=2;a=(a*a)%mod;}return ans;}
int bit(int n){if(n==0)return 0;int k=1,b=0;while((n/k)!=0){k*=2;b++;}return b-1;}

int n,t,k,m,x,y,z,flag=1;
string s;

void solve(){
    
}

static bool comapre(vector<int>a,vector<int>b){
	return a[0]<b[0];
}

int32_t main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	int start[n],end[n];
    	fo(i,n)cin>>start[i];
    	fo(i,n)cin>>end[i];
    	
    	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    	fo(i,n){
    		pq.push({start[i],end[i]});
    	}

    	vector<int>ans;
    	ans.pb(pq.top().second);
    	pq.pop();

    	while(!pq.empty()){
    		pair<int,int>curr={pq.top().first,pq.top().second};
    		pq.pop();
    		if(curr.first>=ans.back()){
    			ans.pb(curr.second);
    		}
    		else{
    			ans.back()=min(ans.back(),curr.second);
    		}
    	}
    	int res=ans.size();
    	cout<<res<<endl;
    }
    

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
