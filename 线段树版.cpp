#include<cstdio>
#include<cstring>
#include <iostream>
using namespace std;
struct node
{
    int from;
    int end;
    int add;
    int he;
}rt[4000001];
void insert(int x,int y,int num)       //       build the segment tree
{
    rt[num].from = x;
    rt[num].end  = y;
    if(x != y)
    {
        insert(x,(x + y) / 2,num * 2);
        insert((x + y) / 2 + 1,y,num * 2 + 1);
    }
}
void dfs(int num)
{
    if(rt[num * 2].he && rt[num * 2 + 1].he)
    {
        rt[num].he = rt[num * 2].he + rt[num * 2 + 1].he;
    }
    else
    {
        dfs(num * 2);
        dfs(num * 2 + 1);
    }
}
void updfs(int num)
{
    if(num %  2 == 1)
    {
        rt[num / 2].he = rt[num].he + rt[num - 1].he;
        if(num / 2)
            updfs(num / 2);
    }
    else
    {
        rt[num / 2].he = rt[num].he + rt[num + 1].he;
        if(num / 2)
            updfs(num / 2);
    }
}
void add(int x,int y,int many,int num)
{
    if(rt[num].from == x && rt[num].end == y)
    {
        rt[num].he += many * (y - x + 1);
        if(rt[num].from != y)
        {
            add(rt[num].from,(rt[num].from + rt[num].end) / 2,many,num * 2);
            add((rt[num].from + rt[num].end) / 2 + 1,rt[num].end,many,num * 2 + 1);
        }
        else
            updfs(num);
    }
    else
    {
        if(x <= (rt[num].from + rt[num].end) / 2)
        {
            if(y <= (rt[num].from + rt[num].end) / 2 )
            {
                add(x,y,many,num * 2);
            }
            else
            {
                add(x,(rt[num].from + rt[num].end) / 2,many,num * 2);
                add((rt[num].from + rt[num].end) / 2 + 1,y,many,num * 2 + 1);
            }
        }
        else
        {
            add(x,y,many,num * 2 + 1);
        }
    }
}
void he1(int x,int y,int num,int val)
{
    if(rt[num].from == x && rt[num].end == y)
    {
        rt[num].he = val;
        if(num % 2 == 1)
        {
            rt[num / 2].he = rt[num].he + rt[num - 1].he;
        }
    }
    else
    {
        if(x >= (rt[num].from + rt[num].end) / 2 + 1)
        {
            he1(x,y,num * 2 + 1,val);
        }
        else
        {
            he1(x,y,num * 2,val);
        }
    }
}
int ans = 0;
void he(int x,int y,int num)
{
    if(rt[num].from == x && rt[num].end == y)
    {
        ans += rt[num].he;
    }
    else
    {
        if(x <= (rt[num].from + rt[num].end) / 2)
        {
            if(y <= (rt[num].from + rt[num].end ) / 2)
            {
                he(x,y,num * 2);
            }
            else
            {
                he(x,(rt[num].from + rt[num].end ) / 2,num * 2);
                he((rt[num].from + rt[num].end ) / 2 + 1,y,num * 2 + 1);
            }
        }
        else
        {
            he(x,y,num * 2 + 1);
        }
    }
}
int main()
{
    freopen("testdata.in","r",stdin);
    freopen("1.out","w",stdout);
	int a,b;
    cin>>a>>b;
    int c[10001];
    for (int i = 1; i <= a; ++i) {
        cin>>c[i];
    }
    insert(1,a,1);                //       build the segment tree
    for (int j = 1; j <= a; ++j)
    {
        he1(j,j,1,c[j]);
    }
    dfs(1);
    for(int i = 1;i <= b;i ++)
    {
        int x;
        cin>>x;
        if (x == 2)
        {
            int y,z;
            cin>>y>>z;
            ans = 0;
            he(y,z,1);
            cout<<ans<<endl;
        }
        else
        {
            int q,w,e;
            cin>>q>>w>>e;
            add(q,w,e,1);
        }
    }
    return 0;
}
