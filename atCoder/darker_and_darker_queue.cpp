#include <iostream>
#include <queue>
 
using namespace std;
 
int main(){
 
    int n,m;
    cin >> n >> m;
    char mat[n][m];
    queue<pair<int, pair<int,int>>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '#'){
                q.push(make_pair(0,make_pair(i,j)));
            }
        }
    }
    int x[] = {0,0,1,-1};
    int y[] = {-1,1,0,0};
    int ans = 0;
    while(!q.empty()){
        pair<int,pair<int,int>> p = q.front();
        q.pop();
        ans = max(ans,p.first);
        for(int i = 0; i < 4; i++){
            int r = p.second.first + x[i];
            int s = p.second.second + y[i];
            if(r >= 0 && r < n && s >= 0 && s < m && mat[r][s] == '.'){
                mat[r][s] = '#';
                q.push(make_pair(p.first+1,make_pair(r,s)));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
