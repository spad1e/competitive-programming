//Note that this solution works locally but will get WA if submitted due to the condition of not being able to call global functions and variables while executing recover_answer
#include <bits/stdc++.h>
#include "cheatsheet.h"
//#include "stub.cpp"
#define ll long long
#define sz(x) (int)x.size()
#define pb push_back
using namespace std;

vector<int> add(vector<int> a, vector<int> b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (sz(a) < sz(b)) a.pb(0);
    while (sz(b) < sz(a)) b.pb(0);

    vector<int> c;
    bool carry = 0;
    for (int i = 0; i < sz(a); ++i) {
        if (a[i]+b[i]+carry <= 350000) {
            c.pb(a[i]+b[i]+carry);
            carry = 0;
        }
        else {
            c.pb(a[i]+b[i]+carry-350001);
            carry = 1;
        }
    }
    if (carry) c.pb(1);
    reverse(c.begin(), c.end());
    return c;
}

vector<int> mul(vector<int> a, vector<int> b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> c;
    int carry = 0;
    for (int i = 0; i < sz(a); ++i) {
        vector<int> v;
        for (int j = 0; j < sz(b); ++j) {
            ll d = (ll)a[i]*b[j]+carry;
            v.pb(d%350001);
            carry = d/350001;
        }
        if (carry != 0) v.pb(carry);
        reverse(v.begin(), v.end());
        for (int j = 0; j < i; ++j) v.pb(0);
        c = add(c, v);
    }
    return c;
}

bool greater_than(vector<int> a, vector<int> b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (sz(a) < sz(b)) a.pb(0);
    while (sz(b) < sz(a)) b.pb(0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < sz(a); ++i) {
        if (a[i] > b[i]) return 1;
        if (b[i] > a[i]) return 0;
    }
    return 0;
}

vector<int> fac[1100];
int fw[1100];

void update(int i, int val) {for (; i < 1100; i += i&-i) fw[i] += val;}
int query(int i) {int ret = 0; for (; i > 0; i -= i&-i) ret += fw[i]; return ret;}


vector<int> write_cheatsheet(int N, vector<int> A) {
    for (int i = 1; i < 1100; ++i) fw[i] = (i&-i);
    fac[0].pb(1);
    for (int i = 1; i < 1100; ++i) fac[i] = mul({i}, fac[i-1]);
    vector<int> ret, cur = {0};
    for (int i = 0; i < 1068; ++i) {
        int l = 0, r = 1067-i;
        while (l < r) {
            int mid = (l+r+1)/2;
            if (greater_than(add(cur, mul({mid}, fac[1067-i])), A)) r = mid-1;
            else l = mid;
        }
        cur = add(cur, mul({l}, fac[1067-i]));
        int idx = l+1;
        l = 1, r = 1068;
        while (l < r) {
            int mid = (l+r)/2;
            if (query(mid) < idx) l = mid+1;
            else r = mid;
        }
        ret.pb(l-1);
        update(l, -1);
    }
	return ret;
}

vector<int> recover_answer(int N, vector<int> R){
    vector<int> ret;
    for (int i = 1; i < 1100; ++i) fw[i] = (i&-i);
    for (int i = 0; i < 1068; ++i) {
        int idx = query(R[i]+1);
        update(R[i]+1, -1);
        ret = add(ret, mul({idx-1}, fac[1067-i]));
    }
    while (sz(ret) > N) ret.erase(ret.begin());
    return ret;
}
