def count_sort(arr, beneath):
    n = len(arr)
    pos = [0] * (beneath + 1)
    for i in range(n):
        pos[arr[i]] += 1
    sorted_arr = [0] * (n)
    for i in range(1, beneath + 1):
        pos[i] += pos[i - 1]
    for i in range(n - 1, -1, -1):
        sorted_arr[pos[arr[i]] - 1] = arr[i]
        pos[(arr[i]) % 10] -= 1
    print(sorted_arr)


count_sort(
    [
        1,
        2,
        2,
        3,
        2,
        1,
        4,
        4,
        5,
        3,
        2,
        3,
        4,
        3,
        2,
        2,
        1,
        2,
        4,
        4,
        4,
        5,
        5,
        4,
        3,
        4,
        2,
        4,
        5,
        2,
        4,
        2,
        1,
    ],
    5,
)
