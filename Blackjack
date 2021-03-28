#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3+3;
int arr[N], dp1[N][N], dp2[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int tests=0; cin >> tests;
  for (int test=1; test <= tests; ++test) {
    int n, x, y;
    cin >> n >> x >> y;
    memset(dp1,0xff,sizeof dp1);
    memset(dp2,0x7f,sizeof dp2);
    for (int i=1; i<=n; ++i)
      cin >> arr[i];
    for (int i=0; i<=n; ++i)
      dp1[i][0]=0;
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=y; ++j)
        if (j<arr[i])
          dp1[i][j]=dp1[i-1][j];
        else
          dp1[i][j]=max(dp1[i-1][j],( dp1[i-1][j-arr[i]]!=-1 ? dp1[i-1][j-arr[i]]+1 : -1 ));
    for (int i=x; i<=y; ++i)
      dp2[n][i]=0;
    for (int i=n; i>0; --i)
      for (int j=0; j<=y; ++j)
        if (j<arr[i])
          dp2[i-1][j]=min(dp2[i][j],dp2[i-1][j]);
        else {
          dp2[i-1][j]=min(dp2[i-1][j],dp2[i][j]);
          dp2[i-1][j-arr[i]]=min(dp2[i-1][j-arr[i]],dp2[i][j]+1);
        }
    int ans=0x7f7f7f7f;
    for (int i=1; i<=n; ++i)
      for (int j=0; j<=y; ++j)
        if (~dp1[i][j] && i-dp1[i][j] <= dp2[i][j])
          ans=min(ans,dp2[i][j]);
    cout << (ans==0x7f7f7f7f?-1:ans) << '\n';
  }
  return 0;
}
