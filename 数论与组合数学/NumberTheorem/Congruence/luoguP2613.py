m = 19260817

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    gcd, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return gcd, x, y

def inverse(b):
    gcd, x, _ = extended_gcd(b, m)
    if gcd != 1:
        return None  # 无法求逆元
    return (x % m + m) % m

a = int(input())
b = int(input())

gcd, _, _ = extended_gcd(b, m)
if gcd != 1:
    print("Angry!")  # 无法求逆元
else:
    inv_b = inverse(b)
    print((inv_b * a) % m)