#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mod 1000000007
const int N = 1e+5;
void onlinejudge(){
        #ifndef ONLINE_JUDGE
        freopen("H:/CodeChef/input.txt","r",stdin);
        freopen("H:/CodeChef/output.txt","w",stdout);
        #endif
}
int arr[N];
int st[4*N];
void buildTree(int si,int ss,int se){
    if(ss == se){
        st[si] = arr[ss];
        return;
    }
    int mid = (ss+se)/2;
    buildTree(2*si,ss,mid);//left node
    buildTree(2*si+1,mid+1,se);//right node    
    st[si] = min(st[2*si],st[2*si+1]);//min of right and left node
}
int query(int si,int ss,int se,int qs,int qe){
    if(qe<ss || qs>se)//completly out of range
        return INT_MAX;
    if(ss>=qs && se<=qe)//completly inside
        return st[si];
    int mid = (se+ss)/2;
    int l = query(2*si,ss,mid,qs,qe);
    int r = query(2*si+1,mid+1,se,qs,qe);
    return min(l,r);
}
int main() {
        onlinejudge();
        IOS;
        int N;
        cin>>N;
        for (int i = 0; i < N; ++i)
            {
                cin>>arr[i];
            }    
        buildTree(1,0,N-1);
        int Q,i,j;
        cin>>Q;
        while(Q--){
            cin>>i>>j;
            cout<<query(1,0,N-1,i,j)<<endl;
        }
    return 0;
}

