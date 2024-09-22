#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v = A;
    set<T> s;
    for (auto x : A) s.insert(x);
    for (auto x : B) if (!s.count(x)) v.push_back(x);
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s;
    for (auto x : B) s.insert(x);
    for (auto x : A) if (s.count(x)) v.push_back(x);
    return v;
}
