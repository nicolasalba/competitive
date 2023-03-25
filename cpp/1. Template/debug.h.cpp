#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG_H
#define DEBUG_H

void __print(int x)                 {cerr << x;}
void __print(long x)                {cerr << x;}
void __print(long long x)           {cerr << x;}
void __print(unsigned x)            {cerr << x;}
void __print(unsigned long x)       {cerr << x;}
void __print(unsigned long long x)  {cerr << x;}
void __print(float x)               {cerr << x;}
void __print(double x)              {cerr << x;}
void __print(long double x)         {cerr << x;}
void __print(char x)                {cerr << '\'' << x << '\'';}
void __print(const char *x)         {cerr << '\"' << x << '\"';}
void __print(const string &x)       {cerr << '\"' << x << '\"';}
void __print(bool x)                {cerr << (x ? "true" : "false");}

template<typename T>
void __print(priority_queue<T> xs)
{cerr << "[ "; while (xs.size()) {__print(xs.top()); xs.pop(); cerr << ' '; }cerr << ']';}

template<typename T, typename V>
void __print(const pair<T, V> &x)
{__print(x.first); cerr << ':'; __print(x.second);}

template<typename T> // for data structures (vector, set, map, etc)
void __print(const T &xs)
{cerr << "[ "; for (auto &x : xs) {__print(x);cerr << ' ';}cerr << ']';}

void _print()
{cerr << "]" << endl;}

template <typename T, typename... V>
void _print(T t, V... v)
{__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define deb(x...) cerr << "[" << #x << "] = [", _print(x)

#endif /* DEBUG_H */
