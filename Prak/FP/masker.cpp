#include <stdio.h>
#include <stdlib.h>

long long int MOD = 1e9 + 7;

long long int pow(long long int base, long long int po) {
    long long int ans = 1;
    for (int i=0; i < po; i++)
    {
        ans = (ans * base) % MOD;
    }
    return ans % MOD;
}

int main() {
    long long int N, M, ans;
    scanf("%lld %lld", &N, &M);
    ans = pow(M-1, N-1);
    ans = (ans * M) % MOD;
    printf("%lld\n", ans % MOD);
    return 0;
}