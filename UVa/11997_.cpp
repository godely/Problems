#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 750 + 10;      //???????750??

struct Item     //??????
{
    int s;      //s = A[i] + B[j]
    int b;      //b = j?B[j]???
    Item(int ss, int bb):s(ss), b(bb){}
    bool operator < (const Item& e) const       //?????,??????????s????????
    {
        return s > e.s;
    }
};

void merge(int *A, int *B, int k)       //??A??B??,???k = 2??k????
{
    int i;
    priority_queue<Item> pq;
    for(i = 0; i < k; i++)      //???????
        pq.push(Item(A[i]+B[0], 0));
    for(i = 0; i < k; i++)      //??k????
    {
        Item item = pq.top();       //????????
        pq.pop();
        A[i] = item.s;
        int b = item.b;
        if(b+1 < k)     //????????,????“1”??????
            pq.push(Item(item.s-B[b]+B[b+1], b+1));
    }
}

int a[maxn][maxn];      //???k*k??
int main() {
    int k, i, j;
    while(cin>>k)
    {
        for(i = 0; i < k; i++)
        {
            for(j = 0; j < k; j++)
                cin>>a[i][j];
            sort(a[i], a[i]+k);     //???
        }
        for(i = 1; i < k; i++)
            merge(a[0], a[i], k);       //????
        for(i = 0; i < k-1; i++)        //????
            cout<<a[0][i]<<" ";
        cout<<a[0][k-1]<<endl;
    }
    return 0;
}

