#include <stdio.h>

#define maxN 1001

struct Node {
    int value;      // value node
    int left, right;    // pointer ke child kiri dan kanan
    int nodeLeft, nodeRight;  // jumlah node di kiri dan kanan
} n[maxN];

int nCk[maxN][maxN], S, M = 1000003;

void add(int &root, int val){
    if (root == -1)
    {
        n[root = S++] = (Node){ val, -1, -1, 0, 0 };    // new node
    }

    else 
    {
        Node &r = n[root];
        if (val < r.value)            // masukkan ke kiri jika value < root's
            add(r.left, val), r.nodeLeft++;  // masukkan ke kiri, dan tambah jumlah node di kiri
        else
            add(r.right, val), r.nodeRight++;  // masukkan ke right, dan tambah jumlah node di kanan
    }
}

long long func(int root){
    if (root == -1) 
    {
        return 1;
    }
    Node &r = n[root];
    long long ret = nCk[r.nodeLeft + r.nodeRight][r.nodeLeft]; // banyak cara untuk memasukkan
    ret = ret * func(r.left) % M;     // rekursif
    ret = ret * func(r.right) % M;     // rekursif
    return ret;
}

int main(){
    nCk[0][0] = 1;
    for (int i=1; i<maxN; i++)
    {
        nCk[i][0] = 1;
        for (int j=1; j<maxN; j++)
        {
            nCk[i][j] = (nCk[i-1][j-1] + nCk[i-1][j]) % M; // Dynamic Programming
        }
    }

    int TC;
    scanf("%d",&TC);
    while (TC--)
    {
        int N,T,val,root=-1; S = 1;
        scanf("%d %d",&N,&T);
        for (int i=0; i<N; i++) scanf("%d",&val), add(root,val);
        {
            printf("%d\n", int(func(root) * nCk[T][N] % M ));
        }
    }
}