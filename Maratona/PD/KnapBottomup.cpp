#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX 500
#define MAXL 20
#define MIN -2000000
#define INF (1 << 30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
// #define lli unsigned long long int
#define lb long double
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//ios_base::sync_with_stdio(false);
//g++ -std=c++11 sol.cpp -o sol.exe && sol.exe < in.txt > output.txt
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int dp[5050][5050];
int peso[5050];
int valor[5050];
int n, aguenta;

void knapUp(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=aguenta;j++){
			if(i == 0 or j == 0){
				dp[i][j] = 0;
				continue;
			}

			if(j - peso[i-1] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j - peso[i-1]] + valor[i-1]);
			else dp[i][j] = dp[i-1][j];			

		}
	}

	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=aguenta;j++) cout << dp[i][j] << " ";
	// 		cout << endl;
	// }

	cout << dp[n][aguenta] << endl;
}

int main(){
	cin >> aguenta >> n;
	// swap(n,aguenta);
	memset(dp, -1, sizeof dp);

	for(int i=0;i<n;i++){
		cin >> peso[i] >> valor[i];
	}

	knapUp();


	return 0;
}