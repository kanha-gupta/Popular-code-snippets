def digits(a):
    if a == 0:
        return 0
    return 1 + digits(int(a / 10))


def split_at(x, d):
    return int(x / (10**d)), x % (10**d)


def karatsuba(a, b):
    if a < 10 and b < 10:
        return a * b
    digitMax = int(max(digits(a), digits(b)) / 2)

    a1, a2 = split_at(a, digitMax)
    b1, b2 = split_at(b, digitMax)

    x = karatsuba(a1, b1)
    y = karatsuba(a2, b2)
    z = karatsuba((a1 + a2), (b1 + b2)) - x - y
    return x * (10 ** (2 * digitMax)) + z * (10**digitMax) + y
