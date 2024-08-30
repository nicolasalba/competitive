/**
 * Description: insert element at $i$-th position, cut a substring and 
 	* re-insert somewhere else. At least 2 times slower than handwritten treap.
 * Time: O(\log N) per operation? not well tested
 * Source: https://codeforces.com/blog/entry/10355
 * Verification: CEOI 2018 Day 2 Triangles
	* https://szkopul.edu.pl/problemset/problem/AzKAZ2RDiVTjeWSBolwoC5zl/site/?key=statement
	* vector is faster for this problem ...
 */

#include <ext/rope>
using namespace __gnu_cxx;
void ropeExample() {
	rope<int> v(5,0); // initialize with 5 zeroes
	F0R(i,sz(v)) v.mutable_reference_at(i) = i+1; 
	F0R(i,5) v.pb(i+1); // constant time pb
	rope<int> cur = v.substr(1,2); 
	v.erase(1,3); // erase 3 elements starting from 1st element
	for (rope<int>::iterator it = v.mutable_begin(); 
		it != v.mutable_end(); ++it) pr((int)*it,' ');
	ps(); // 1 5 1 2 3 4 5
	v.insert(v.mutable_begin()+2,cur); // or just 2
	v += cur; F0R(i,sz(v)) pr(v[i],' ');
	ps(); // 1 5 2 3 1 2 3 4 5 2 3
}

/* 
Tested in cses https://cses.fi/problemset/task/1749/
https://cses.fi/problemset/result/10105636/ 2 times slower than ordered set
It's better to create rope with an given size and value

TLE with 2*10^5
Need revision!!

push_back() - O(log N).
pop_back() - O(log N)
insert(int x, crope r1): O(log N) and Worst O(N)
substr(int x, int l): O(log N)
replace(int x, int l, crope r1): O(log N).
*/

