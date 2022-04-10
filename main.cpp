#include <bits/stdc++.h>
using namespace std;
int a,b;
char mapp[1010][1010];
int vis[1010][1010];
int ans[1010][1010];
int maxx = 0;
int cnt = 0;
void dfs(int x,int y ,int bx,int by) {
    if (bx < x & y == by) {
        if (mapp[x][y] == '/') {
            if (y - 1 >= 1) {
                cnt ++;
                /*if(vis[x][y - 1]) {
                    cout<<"-1";
                    puts("");
                    cout<<x<<"  "<<y;
                    exit(0);
                }*/
                vis[x][y - 1] = 1;
                dfs(x,y - 1, x,y);
                vis[x][y - 1] = 0;
            }
            else {
                ans[x][y] = cnt + 1;
            }

        }
        if(mapp[x][y] == '\\') {
            if (y + 1 <= b) {
                cnt ++;
                /*if(vis[x][y + 1]) {
                    cout<<"-1";
                    puts("");
                    cout<<x<<"  "<<y;
                    exit(0);
                }*/
                vis[x ][y + 1] = 1;
                dfs(x,y + 1,x,y);
                vis[x][y + 1] = 0;
            }
        }
        else {
            ans[x][y] = cnt + 1;
        }
    }
    if (bx > x & y == by) {
        if (mapp[x][y] == '/') {
            if (y + 1 <= b) {
                cnt ++;
                /*if(vis[x][y + 1]) {
                    cout<<"-1";
                    puts("");
                    cout<<x<<"  "<<y;
                    exit(0);
                }*/
                vis[x][y + 1] = 1;
                dfs(x,y + 1,x,y);
                vis[x][y + 1] = 0;
            }
            else {
                ans[x][y] = cnt + 1;
            }
        }

        if(mapp[x][y] == '\\') {
            if (y - 1 >= 1) {
                cnt ++;
                /*if(vis[x][y - 1]) {
                    cout<<"-1";
                    puts("");
                    cout<<x<<"  "<<y;
                    exit(0);
                }*/
                vis[x][y - 1] = 1;
                dfs(x,y - 1,x,y);
                vis[x][y - 1] = 0;
            }
            else {
                ans[x][y] = cnt + 1;
            }
        }
    }
    if (bx == x & y > by) {
        if (mapp[x][y] == '/') {
            if(x - 1 >= 1) {
                cnt ++;
                /*if(vis[x - 1][y]) {
                    cout<<"-1";
                    puts("");
                    cout<<x<<"  "<<y;
                    exit(0);
                }*/
                vis[x - 1][y] = 1;
                dfs(x - 1,y,x,y);
                vis[x - 1][y] = 0;
            }
            else {
                ans[x][y] = cnt + 1;
            }
        }

        if(mapp[x][y] == '\\') {
            if (x + 1 <= a) {
                cnt ++;
                /*if(vis[x + 1][y]){
                    cout<<"-1";
                    puts("");
                    cout<<x<<"  "<<y;
                    exit(0);
                }*/
                vis[x + 1][y] = 1;
                dfs(x + 1,y,x,y);
                vis[x + 1][y] = 0;
            }
            else {
                ans[x][y] = cnt + 1;
            }
        }
    }
    if (bx == x & y < by) {
        if (mapp[x][y] == '/') {
            if (x + 1 <= a) {
                cnt ++;
                /*if(vis[x + 1][y] ) {
                    cout<<"-1";
                    puts("");
                    cout<<x<<"  "<<y;
                    exit(0);
                }*/
                vis[x + 1][y] = 1;
                dfs(x + 1,y,x,y);
                vis[x + 1][y] = 0;
            }
            else {
                ans[x][y] = cnt + 1;
            }
        }
        if(mapp[x][y] == '\\') {
            if (x - 1 >= 1) {
                cnt ++;
                /*if(vis[x - 1][y]) {
                    cout<<"-1";
                    puts("");
                    cout<<x<<"  "<<y;
                    exit(0);
                }*/
                vis[x - 1][y] =  1;
                dfs(x - 1,y,x,y);
                vis[x - 1][y] = 0;
            }
            else {
                ans[x][y] = cnt + 1;
            }
        }
    }
}
int main() {
    cin>>a>>b;
    for(int i = 1;i <= a;i ++) {
        for( int j = 1;j <= b;j ++) {
            cin>>mapp[i][j];
        }
    }
    for(int i = 1;i <= a;i ++) {
        if(!ans[i][1]) {
            cnt = 0;
            dfs(i,1,i,0);
            maxx = max(maxx,cnt);
            ans[i][1] = cnt;
        }
        if (!ans[i][b]) {
            cnt = 0;
            dfs(i,b,i,b + 1);
            maxx = max(maxx,cnt);
            ans[i][b] = cnt;
        }
    }
    for(int i = 1;i <= b;i ++) {
        if(!ans[1][i]) {
            cnt = 0;
            dfs(1,i,0,i);
            ans[1][i] = cnt;
            maxx = max(maxx,cnt);
        }
        if (!ans[a][i]) {
            cnt = 0;
            dfs(a,i,a + 1,i);
            ans[a][i] = cnt;
            maxx = max(maxx,cnt);
        }
    }
    cout<<maxx + 1;
    return 0;
}
/*
10 10
\\////\/\\
\/////\\/\
//\\//\\/\
\\///\/\//
///\///\\/
\//\\//\//
/\/\//\//\
//\///\//\
//\\\\/\//
/\////\\/\
 * */
