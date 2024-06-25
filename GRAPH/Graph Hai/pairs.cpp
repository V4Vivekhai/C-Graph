#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    queue<pair<int,int>>Q;

    Q.push({0,7});
    Q.push({0,3});
    Q.push({2,2});
    Q.push({3,1});

    int n=Q.size();

    for(int i = 0 ;i<n;i++)
    {
        pair <int,int> p;
        p = Q.front();
        
        cout<<p.first<<", ";
       cout<<p.second<<endl;

        Q.pop();

    }
    cout<<endl<<endl;

    vector<vector<int>>status(4,vector<int>(4,-1));
    for(int i = 0 ;i < 4 ; i++)
    {
        for(int j = 0 ; j< 4 ;j++)
        cout<<status[i][j]<<" ";

        cout<<endl;
    }
    


    return 0;
}
