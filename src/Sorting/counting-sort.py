def count_keys_equal(A, n, m):
    equal = [0] * (m + 1)
    for i in range(0, n):   # 0 1 2 3 4 5 6
        key = A[i]          # 1 3 0 1 1 3 1
        equal[key] += 1
    return equal

def count_keys_less(equal, m):
    less = [0] * (m + 1)
    less[0] = 0
    for j in range(1, m+1):                       # 0 1 2 3 4 5 6
        less[j]= less[j - 1] + equal[j - 1]     # 0 0 0 0 0 0 0 
    return less

def rearrange(A, less, n, m):
    next = [0] * (m + 1)
    B = [0] * n
    for j in range(0, m + 1):                   # 1 2 5 5 6 7 10
        next[j] = less[j] + 1
    for i in range(0, n):
        key = A[i]
        index = next[key] - 1
        B[index] = A[i]
        next[key] += 1
    return B

def counting_sort(A, n, m):
    equal = count_keys_equal(A, n, m)
    less = count_keys_less(equal, m)
    return rearrange(A, less, n, m)

A = [4, 1, 5, 0, 1, 6, 5, 1, 5, 3]
print A
m = max(A)
n = len(A) 
B = counting_sort(A, n, m)
print(B)
