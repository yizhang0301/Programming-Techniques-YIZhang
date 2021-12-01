#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 30, M = 700;

int h[N], e[M], ne[M], idx;
bool st[N];
// Add inserts two connected vertices to the list
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;  //add new cd in graph
}
//method for depth-first search 优先搜索
void dfs(int x)
{
    st[x] = true; // vertex has been visited 顶点访问判断
    for(int i = h[x]; ~i; i = ne[i]) // traverse the list遍历列表     Bitwise negation
    {
        int y = e[i];
        if(st[y])   
          continue;
        dfs(y);
    }
}

int main()
{
    int T;
    cin >> T;
    getchar();      
    getchar();      
    
    while(T--)
    {
        memset(st, false, sizeof st);  //Initialize the element in the array to the middle element
        memset(h, -1, sizeof h);
        idx = 0;
        
        char s[5];
        fgets(s, 5, stdin);             // Read the entire line 
        int n = s[0] - 'A' + 1;        ///Number of letters
        
        while(fgets(s, 5, stdin) && s[0] != '\n')  //check empty
        {
            int a = s[0] - 'A' + 1, b = s[1] - 'A' + 1;
            add(a, b), add(b, a);
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!st[i])  // vertex has or not been visited
            {
                ans++;
                dfs(i);
            }
        }
        
        printf("%d\n", ans);
        if(T)   printf("\n");
    }
    
    return 0;
}
