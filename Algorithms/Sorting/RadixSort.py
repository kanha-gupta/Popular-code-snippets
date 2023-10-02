def count_sort(arr, place):  # define counting sort
    n = len(arr)
    pos = [0] * (10)
    for i in range(n):
        pos[(arr[i] // place) % 10] += 1
    sorted_arr = [0] * (n)
    for i in range(1, 10):
        pos[i] += pos[i - 1]
    for i in range(n - 1, -1, -1):
        # This is necessary to make count_sort stable
        sorted_arr[pos[(arr[i] // place) % 10] - 1] = arr[i]
        pos[(arr[i] // place) % 10] -= 1
    return sorted_arr


def radix_sort(arr):  # Sort a code in O(n*log(max)) time
    maximum = max(arr)
    place = 1
    while maximum // place > 0:
        arr = count_sort(arr, place)  # Any Stable merging algorithm like counting sort
        place *= 10
    print(arr)


data = [121, 432, 564, 23, 1, 45, 788]
radix_sort(data)
