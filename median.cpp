#include <bits/stdc++.h>
using namespace std;

void balance(multiset<int>& left, multiset<int>& right) {
    if (left.size() == right.size() || left.size() == right.size() + 1) return;
    while (right.size() > left.size()) {
        auto it = right.begin();
        left.insert(*it);
        right.erase(it);
    }
    while (left.size() > right.size() + 1) {
        auto it = left.end();
        it = prev(it);
        right.insert(*it);
        left.erase(it);
    }
    return;
}

void addEl(multiset<int>& left, multiset<int>& right, int x) {
    if (left.size() == 0) {
        left.insert(x);
        return;
    }
    int median = *(left.rbegin());
    if (x <= median) {
        left.insert(x);
    } else {
        right.insert(x);
    }
    balance(left, right);
}

int main() { return 0; }
