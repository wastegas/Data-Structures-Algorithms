def quicksort(A, p, r):
    if r - p > 1:
        q = partition(A, p, r)
        quicksort(A, p, q - 1)
        quicksort(A, q + 1, r)

def partition(A, p, r):
    q = p
    for u in range(p, r-1):
        if A[u] <= A[r]:
            A[q], A[u] = A[u], A[q]
            q += 1
    A[q], A[r] = A[r], A[q]
    return q

A = [9, 7, 5, 11, 12, 2, 14, 3, 10, 6]
print(A)
quicksort(A, 0, len(A)-1)
print(A)
