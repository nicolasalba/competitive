/*
Multiple Knacksack

You have a knacksack of a capacity, and 'n' objects with 
value, weight, and a number of copies that you can buy of that object.

Maximize the value without exceding the capacity of the knacksack.

Time complexity is O(W*N*sum)
W = capacity, N = number of objects,
sum is: for (int i =0, sum = 0;i<n;i++) sum += log2(copies[i]) 

Tested in https://cses.fi/problemset/task/1159/
n<=100, capacity<=10^5, copies[i]<=1000
*/
ll multipleKnacksack(vl &value, vl& weight, vl&copies, ll capacity) {
    vl vs,ws;
    ll n = value.size();
    for (int i = 0;i<n;i++) {
        ll h=value[i],s=weight[i],k=copies[i];
        ll p = 1;
        while (k>p) {
            k-=p; // Binary Grouping Optimization
            vs.pb(s*p);
            ws.pb(h*p);
            p*=2;
        }
        if (k) {
            vs.pb(s*k);
            ws.pb(h*k);
        }
    }
    vl dp(capacity+1);
    // 0-1 knacksack
    for (int i =0;i<ws.size();i++) {
        for (int j = capacity;j>=ws[i];j--) {
            dp[j] = max(dp[j],dp[j-ws[i]] + vs[i]); 
        }
    }
    return dp[capacity]; 
}
