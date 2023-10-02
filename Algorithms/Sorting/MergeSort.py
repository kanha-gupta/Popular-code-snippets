def merge_sort(arr, l, r):
    if l >= r:
        return arr
    mid = int((l + r) / 2)
    arr = merge_sort(arr, l, mid)
    arr = merge_sort(arr, mid + 1, r)
    i = l
    j = mid + 1
    k = 0
    temp = [0] * (r - l + 1)
    while k <= (r - l):
        if i > mid:
            temp[k] = arr[j]
            j += 1
            k += 1
        elif j > r:
            temp[k] = arr[i]
            i += 1
            k += 1
        elif arr[i] < arr[j]:
            temp[k] = arr[i]
            i += 1
            k += 1
        else:
            temp[k] = arr[j]
            j += 1
            k += 1
    for i in range(r - l + 1):
        arr[i + l] = temp[i]
    return arr


print(merge_sort([2, 1], 0, 1))

print(
    merge_sort(
        [1, 2, 3, 4, 2, 1, 1, 2, 3, 244, 222, 566, 2, 4, 1, 1, 1, 344, 6, 2, 1, 2],
        0,
        21,
    )
)
