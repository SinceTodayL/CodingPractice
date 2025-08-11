## ACM 组合数学



### 组合数的数论性质

如果 n, r 互质，则一定有：
$$
n | C_n^r
$$
特别的，如果 n 为素数，则一定有上述性质



#### Lucas Theroem



#### 容斥原理

**trick: 位运算枚举子集**

```c++
void enumerateSubsets(const std::vector<char>& elements) {
    int n = elements.size();
    for (int mask = 0; mask < (1 << n); ++mask) {
        std::cout << "{ ";
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {                // 这个if条件非常巧妙
                std::cout << elements[i] << " ";
            }
        }
        std::cout << "}" << std::endl;
    }
}

int main() {
    std::vector<char> elements = {'A', 'B', 'C'};
    enumerateSubsets(elements);
    return 0;
}
```

如上述代码所示，巧妙的利用 & 运算来判断某元素是否在该子集中，而从 $0 - (2^{n-1} - 1)$ 的二进制表示正好对应了含有 n 个元素的集合的每一个子集

