

## ACM 数论

 

### 快速幂

最基础的代码之一，加速幂运算，利用了二进制数的特征

```c++
ll fastpower_withmod(ll a, ll n){
     ll ans = 1;
     while(n){
        if(n & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
     }
     return ans % mod;
}
```

快速幂的一大用途就是加速矩阵运算，这个矩阵一般是自己构造，描述实际问题的，比如斐波那契数列的通项便可以用矩阵快速幂在 $O(log n)$ 级别的时间求出，其他问题如果可以用==矩阵幂运算模拟（加速递推）==，同样也可以用快速幂（需要重载对矩阵的乘法运算）

还有一种和快速幂想法很相像的算法：龟速乘法，把乘法当作加法处理，目的是防止爆longlong，算法如下

```c++
ll multi(ll x, ll y){
    ll ans = 0;
    while(y){
        if(y & 1) 
            ans = (ans + x) % mod;
        x = (x + x) % mod;
        y >>= 1;
    }
    return ans;
}
```





### GCD 和 LCM

重要性质：

*  $gcd (a, b) = gcd (b, a\%b) = gcd(a, b + k*a)$
*  $gcd(k*a, k*b) = k*gcd(a, b)$  

求GCD代码：

```c++
inline ll gcd(ll x, ll y){
    return y == 0 ? x : gcd(y, x % y);
}
```



==算数基本定理==

任何正整数 $n > 1$，可以唯一的分解为有限个素数的乘积，即：
$$
n = p_1^{c_1} p_2^{c_2}...p_m^{c_m}
$$
若两个数 a，b 满足：$a = p_1^{q_1} p_2^{q_2}...p_m^{q_m}$ ，$b = p_1^{t_1} p_2^{t_2}...p_m^{t_m}$，则有：
$$
gcd(a, b) = p_1^{min(q_1, t_1)}p_2^{min(q_2, t_2)}...p_m^{min(q_m,t_m)} \\
lcm(a, b) = p_1^{max(q_1, t_1)}p_2^{max(q_2, t_2)}...p_m^{max(q_m,t_m)}
$$
经典题目：(涉及到质因数分解、容斥原理)

>###### 题目描述
>
>给定两个数 $x,y$，求有多少种不同的长度为 $n$ 的序列 $(a_1,a_2,\cdots,a_n)$，其所有元素的最大公约数为 $x$ 且最小公倍数为 $y$。
>
>两个序列 $(a_1,a_2,\cdots,a_n)$ 与 $(b_1,b_2,\cdots,b_n)$ 不同，是指存在至少一个位置 $i$ 满足 $a_i\neq b_i$。
>
>由于答案可能很大，请输出答案对 $998\ 244\ 353$ 取模后的结果。
>

其中涉及到的质因数分解，只要逐个检查 $2 到 \sqrt{n}$ 的所有数即可





### 01分数规划

对于给定的序列$(a_1,a_2,\cdots,a_n)$，$(b_1,b_2,\cdots,b_n)$，同时选出 k 个 a, b ，求：
$$
max \frac{\sum_{i=1}^{n} a_i s_i}{\sum_{i=1}^{n} b_i s_i}, 其中s_i为0或1，代表选该组数或不选
$$
方法：枚举每一个可能的 x,  但是要二分，对于每一个 x，要使
$$
max \frac{\sum_{i=1}^{n} a_i s_i}{\sum_{i=1}^{n} b_i s_i} \geq x
$$
移项转化为：
$$
\sum_{i = 1}^{n}(a_i - x * b_i) \geq 0
$$
二分中 check 函数的写法：

```c++
struct node{
    double a, b, y;
}point[1010];

//究竟选哪些组数根据题意，本例中选前k个
bool check(double k){
      for(int i = 0; i < n; ++i){
          point[i].y = - point[i].b * k + point[i].a * 1.0;
      }
      sort(point, point + n, cmp);
      double all = 0;
      for(int i = 0; i < n - t; ++i){
           all += point[i].y;
      }
      return all - 0 > 1e-6;
}
```



经典题目：（涉及到背包问题）

>**题目描述**
>
>Farmer John 要带着他的 $n$ 头奶牛，方便起见编号为 $1\ldots n$，到农业展览会上去，参加每年的达牛秀！他的第 $i$ 头奶牛重量为 $w_i$，才艺水平为 $t_i$，两者都是整数。
>
>在到达时，Farmer John 就被今年达牛秀的新规则吓到了：
>
>（一）参加比赛的一组奶牛必须总重量至少为 $W$（这是为了确保是强大的队伍在比赛，而不仅是强大的某头奶牛），并且。
>
>（二）总才艺值与总重量的比值最大的一组获得胜利。
>
>FJ 注意到他的所有奶牛的总重量不小于 $W$，所以他能够派出符合规则（一）的队伍。帮助他确定这样的队伍中能够达到的最佳的才艺与重量的比值。





### 线性丢番图方程

==裴蜀定理==
$$
\forall a, b ,  \exist x, y 使得 gcd(a, b) = ax+by
$$
这告诉我们，a, b 的线性组合可以构成任何包含因子 $gcd(a, b)$ 的数

但是如果限制了x, y 也是会有一些小整数无法构成

==扩展欧几里得算法==

这是求解丢番图方程的最实用算法

`````c++
ll extended_gcd(ll a, ll b, ll& x, ll& y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}
`````

对于方程 $ax+by=c$ 的整数解，如果  $gcd(a, b) | c$ 不成立，则不存在 x，y的解；

接下来，先求 $ax + by = gcd(a, b)$ 的解，这可以通过上述扩展欧几里得算法求出，但是这里求出的 $x_0, y_0$ 只是一个特解

得到 $x_0, y_0$ 后，可以先将其中某个转换为最小正整数（其实没有必要）：令 $d = gcd(a, b)$, 则：`x = ((x % b / d) + b / d) % b /d`, 或者对 y 进行如此操作

由于刚才我们把方程右边的 c 转换为了 $gcd(a, b)$，现在再乘回去，即：$x_0^{'} = x_0 *(c / d)，y_0^{'} = y_0 * {c / d}$  ，然后可以写出通解：
$$
x = x_0^{'} + (b / d) * k \quad \quad y = y_0^{'} - (a/d)*k, \quad  \quad k \in N
$$





### 同余

**基本性质**

如果
$$
a \equiv b \pmod{m}, c \equiv d \pmod{m}
$$
则有
$$
a \times c \equiv  b\times d \pmod{m}
$$
**同余方程**

对于同余方程 $ax \equiv b \pmod{m}$，有解的充要条件为: $gcd(a, m) | b$，这点由裴蜀定理容易想象

对于该方程的求解，往往需要用到求逆，即模 m 群下1的逆元

求逆的方法有很多种：

* 扩展欧几里得算法求逆

```c++
ll mod_inverse(ll a, ll m){
	ll x, y;
    extended_gcd(a, m, x, y);
    return ((x % m) + m) % m   // 保证返回的是最小正整数解
}
```

* 如果 m 和 a 互素，用==费马小定理==求逆

`````C++
ll mod_inverse(ll a, ll m){
    return fastpower(a, m - 2) % m;
}
`````

* 多个连续整数求逆：递推公式

```c++
ll inverse[N];
void get_inverse(ll n, ll p){  // p 为 mod, 且 p 为质数
    inverse[1] = 1;
    for(int i = 2; i <= n; ++i){
        inverse[i] = (p - p/i) * inverse[p % i] % p;  // 神奇的逆元递推公式
    }
}
```



==对有理数 $\frac{a}{b}$ 取模==，其实就是求方程 $bx \equiv a \pmod{m}$ 的解





### 中国剩余定理

对于同余方程组
$$
x \equiv a_1 \pmod{m_1}\\
x \equiv a_2 \pmod{m_2}\\
...\\
x \equiv a_r \pmod{m_r}
$$


如果满足 $m_i$ 之间两两互素，就符合中国剩余定理的条件 

直接套公式即可：
$$
x \equiv (a_1 M_1 M^{-1}_1 + a_2 M_2 M^{-1}_2 + ... + a_r M_r M^{-1}_r)  \pmod{M}
$$
其中   $M = M_1M_2...M_r \quad M_i = M/m_i$

扩展的中国剩余定理，代码如下，基本思想是将每两个都合并为一个

```c++
/*
    扩展中国剩余定理 模板
    如果同余方程中的 m 都是互素的，x 有解公式
    但是如果不满足这个条件，就要用扩展中国剩余定理
    其实就是以两个为一个方程组，然后合并为一个，直到只剩两个方程
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 1;
int n;
ll a[N];
ll m[N];

//龟速乘, 防止爆long long
ll multiply(ll a, ll b, ll m){
    ll ans = 0;
    while(b > 0){
        if(b & 1){
            ans = (ans + a) % m;
        }
        a = (a + a) % m;
        b >>= 1;
    }
    return ans;
}

ll extended_gcd(ll a, ll b, ll& x, ll& y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

ll excrt(){
    ll x, y;
    ll m1 = m[1], a1 = a[1];
    ll ans = 0;
    for(int i = 2; i <= n; ++i){
        ll a2 = a[i], m2 = m[i];
        ll a = m1, b = m2;
        ll c = (a2 - a1 % m2 + m2) % m2;
        ll d = extended_gcd(a, b, x, y);

        // 无解
        if(c % d != 0){
            return -1;
        }

        x = multiply(x, c / d, b / d);  // 之所以模为b/d，是因为要求在模b/d意义下最小的x
        ans = a1 + x * m1;
        m1 = m2 / d * m1;
        ans = (ans % m1 + m1) % m1;
        a1 = ans;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> m[i] >> a[i];
    }
    cout << excrt() << endl;

    return 0;
}
```





### 素性测试

用更加简单的方法测试一个数是否为素数，而不是用 $O(\sqrt{n})$ 的复杂度遍历测试

但是以此为代价的是，该类判断方法往往是概率性的，只是我们可以通过一些手段提高准确率

* 费马素性测试，基于费马小定理

在 1-n 内任选一个随机的基值 a ，如果 $a^{n-1} \equiv 1 \pmod{n}$ 不成立，==则 n 一定不是素数==；若成立，则==很大概率是素数==，但有可能不是

* Miller-Rabin 素性测试

在模 n 群中，若存在 1 的非平凡平方根（平凡平方根就是 1 和 n - 1 ），则 n 一定不为素数，也就是说：
$$
x^2 \equiv 1 \pmod{n}
$$
如果 n 为素数，则一定只有 1 和  n - 1 两个解

下面是例程

```c++
// hdu 2138
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastpower(ll a, ll n, ll mod){ 
    ll ans = 1;
    while(n){
        if(n & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans % mod;
}

bool witness(ll a, ll n){ // 素性测试的核心函数，基于二次探测定理
    ll u = n - 1;
    int t = 0;
    while(u & 1 == 0){
        u >>= 1;
        t++;
    }
    ll x1, x2;
    x1 = fastpower(a, u, n);
    for(int i = 1; i <= t; ++i){
        x2 = fastpower(x1, 2, n);
        if(x2 == 1 && x1 != 1 && x1 != n - 1)
            return true;
        x1 = x2;
    }
    if(x1 != 1)
        return true;
    return false;
}

bool MillerRabin(ll n, ll s){
    if(n < 2)  //返回false，表示不是素数
        return false; 
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    for(int i = 0; i < s && i < n; ++i){
        ll a = rand() % (n - 1) + 1;
        if(witness(a, n))
            return false;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll m, input, test_times = 30;
    while(cin >> m){
        ll cnt = 0;
        for(int i = 0; i < m; ++i){
            cin >> input;
            if(MillerRabin(input, test_times))
                cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
```







### 素数筛

判断 1-n 内的素数

* 埃式筛

```c++
void get_prime(){
    ll limit = N;
    for(int i = 0; i <= limit; ++i){
        isprime[i] = true;
    }
    for(int i = 2; i * i <= limit; ++i){
        if(isprime[i]){
            for(int j = i * i; j <= limit; j += i){
                isprime[j] = false;
            }
        }
    }
}
```

* 欧拉筛

```c++
void EulerSieve(){
    int cnt = 0;
    memset(prime, 0, sizeof(prime));
    memset(isprime, true, sizeof(isprime));
    for(int i = 2; i <= N; ++i){
        if(isprime[i]){
            prime[cnt++] = i;
        }
        for(int j = 0; j < cnt; ++j){
            if(i * prime[j] > N)
                break;
            isprime[i * prime[j]] = false;
            if(i % prime[j] == 0)
                break;
        }
    }
}
```

欧拉筛的复杂度为$O(n)$，因为每个非素数只用其最小质因数筛去，而埃式筛会筛多遍





### 欧拉函数

欧拉函数定义为
$$
\phi(n) = |\{k \mid 1 \leq k \leq n, \ \gcd(k, n) = 1\}|
$$
也可以写作：
$$
\phi(n) = n \prod_{p \mid n} \left(1 - \frac{1}{p}\right)
$$
是一个积性函数，即
$$
\phi(mn) = \phi(m) \phi(n)
$$
求法如下：

```c++
const int N = 1e6 + 3;

// 求 1-n 之间所有值的欧拉函数
vector<int> Euler;
void EulerN(){
    Euler.resize(N, 0);
    for(int i = 1; i <= N; ++i){
        Euler[i] = i;
    }
    for(int i = 2; i <= N; ++i){
        if(Euler[i] == i){
            for(int j = i; j <= N; j += i){
                Euler[j] = (Euler[j] / i) * (i - 1);  
            }
        }
    }
}

// 求单个数的欧拉函数
int Euler1(int n){
    int ans = n;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            ans = (ans / i) * (i - 1);
            while(n % i == 0){
                n /= i;  // 去掉n的质因数分解中所有关于i的部分
            }
        }
    }
    if(n != 1){
        ans = (ans / n) * (n - 1);
    }
    return ans;
}
```

经典例题：（使用欧拉函数化简 gcd 的式子）

>**题目描述**
>
>求  $$\sum_{i=1}^n \sum_{j=1}^n \gcd(i, j)$$
>

这个题目的化简非常妙！



### 欧拉定理

如果 $gcd(a, m) = 1$，则有：
$$
a^{\phi(m)} \equiv 1 \pmod{m}
$$
其中, $\phi(m)$ 是 m 的欧拉函数值

除此之外，还有扩展欧拉定理：
$$
a^{b} \equiv 
\begin{cases} 
a^{b} & \text{如果 } b < \phi(m) \\
a^{b \mod \phi(m) + \phi(m)} & \text{如果 } b \geqslant \phi(m)
\end{cases}
$$
所以如果要求 $a^b\ mod \ m$，就可以用快读，边读边进行模运算得到 b，然后再快速幂

附上快读代码

```c++
inline int fastRead() {
    int x = 0, c = getchar();
    while (c < '0' || c > '9') c = getchar(); // 跳过非数字字符
    while (c >= '0' && c <= '9') {
        x = x << 3 + x << 1 + c - '0';
        x %= mod;                             // 取模运算
        c = getchar();
    }
    return x;
}
```

 



### 整除分块

该类算法是为了求解整除的求和问题：
$$
\sum_{i = 1}^{n}  \lfloor \frac{n}{i} \rfloor
$$
该算法的基本思想是将 $\lfloor \frac{n}{i} \rfloor $ 按照相同值分块，每一块都可以用 $O(1)$ 的时间复杂度计算，可以证明的是，==该分块不会超过 $2\sqrt{n}$ 个==，因此计算该类问题的复杂度就降低到了 $O(\sqrt{n})$ 

代码如下

```c++
int cal(int n){
    int ans = 0;
    int l = 0, r = 0;
    for(l = 1; l <= n; l = r + 1){  //注意 l 的取值
        r = n / (n / l);  //算法的核心，通过左界 l 就可以求出右界的值
        ans += (r - l + 1) * (n / l);   // n/l 是该分块的值
    }
    return ans;
}
```

例题如下：

>**题目描述**
>
>给出正整数 $n$ 和 $k$，计算
>
>$$G(n, k) = \sum_{i = 1}^n k \bmod i$$
>
>其中 $k\bmod i$ 表示 $k$ 除以 $i$ 的余数。





### 威尔逊定理

这个定理告诉了我们一些素数阶乘的整除性质：
$$
如果p为素数，则有 \quad p\mid(p-1)! + 1
$$
或者可以写成：
$$
如果p为素数，则有： (p-1)! \equiv (p-1) \pmod{p}  \\
或者说：(p-1) ! = kp - 1, k \in N*
$$
如：8 | 7! + 1

例题：

>给定输入n，计算：
>$$
>S_n = \sum_{k = 1}^{n} [\frac{(3k+6)! + 1}{3k + 7} - [\frac{(3k+6)!}{3k+7}]]
>$$

令 $p = 3k + 7$ , 本题转化为求 $[\frac{(p-1)!+1}{p} - [\frac{(p-1)!}{p}]]$ 的值，$p$ 为素数时，前一项整除，该式值为0；$p$ 为合数时，$p | (p-1)!$ 成立，该式值为0





### 异或空间线性基

和在线性代数中，我们把线性基当作描述向量的基本工具，线性基可以张成整个向量空间一样，在正整数的异或运算中，也存在这样的线性基

>洛谷 P3812 
>
>给定 $n$ 个整数，在这些整数中选出任意个，求出他们异或和的最大值

在本题中，$n$ 个整数意味着有 $2^n$ 种组合，不可能用暴力枚举

实际上，这 $n$ 个数能组成的异或值却少得多，设他们其中最大值的二进制位数为 $k$，那么他们最多有 $2^k$ 种结果，和 $n$ 是一个数量级

这也意味着很多组合的异或值是重复的，**异或空间线性基** 就是这样一种方法，能够找出一个线性基，满足：在原数组 $A$ 上做异或运算，和在线性基数组 $P$ 上运算的结果一致

求线性基的基本步骤：遍历所有元素，如果当前元素二进制位为 $r$ 且之前没有元素二进制位数也为 $r$ ，则加入线性基；如果已经有了，则将当前元素和该二进制位数也为 $r$ 的元素异或（此时该数的二进制位数一定变小了），然后再重复该过程

下面 P3812 的解法给出了一种简单的求线性基的方法

```c++
const int N = 63;
ll p[N];   // p[i] 代表的是最高位在第 i 位的元素
void insert(ll x){
    for(int i = N; i >= 0; --i)
        if(x >> i == 1)
            if(p[i] == 0){
                p[i] = x; return; }
            else
                x ^= p[i];  
}
int main(){
    ll x, n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> x;  insert(x);
    }
    ll ans = 0;
    for(int i = N; i >= 0; --i)
        ans = max(ans, ans ^ p[i]);  // 只要能让当前元素变大，就计算异或
    cout << ans << endl;
    return 0;
}
```

求出线性基后，除了求元素的最大异或和，还可以求：

1. 最小异或和：线性基中的最小元素就是最小异或和，因为他和所有其他元素异或后一定会变大
2. 第 $k$ 大异或和：延续求最大异或和的思路，我们将线性基中所有元素都遍历到，只要能让当前元素变大，就计算异或；如果是求第2大呢？那就遍历最大的前 $n-1$ 个线性基；按照 $k$ 的二进制规律，如果 $k$ 的二进制表示为 01101，则代表取第2、3、5大的线性基进行运算，以此类推
