#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::swap;

namespace NS1 {
    typedef int S1;
    struct S2 {};

    void swap(S1& s1, S1& s2) {
        cout << "You've been tricked :)" << endl;
    }

    void swap(S2& s1, S2& s2) {
        cout << "s2You've been tricked :)" << endl;
    }
}

int main(int argc, char** argv) {
    NS1::S1 a, b;
    NS1::S2 c, d;
    int m = 0, n = 1;


    // 1. 调用哪个swap？std::swap 还是 NS1::swap？
    swap(a, b);

    // 2. 调用哪个swap？std::swap 还是 NS1::swap？
    swap(m, n);

    // 3. 调用哪个swap？std::swap 还是 NS1::swap？
    swap(c, d);

    return 0;
}

