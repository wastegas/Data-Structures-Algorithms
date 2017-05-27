def mergesort(A, p, r):
    if r - p > 1:
        q = int((p + r) / 2)
        mergesort(A, p, q)
        mergesort(A, q, r)
        merge(A, p, q, r)

def merge(A, p, q, r):
    B = A[p:q]
    C = A[q:r]
    i = 0 
    j = 0
    for k in range (p, r):
        if j >= len(C) or (i < len(B) and B[i] < C[j]):
            A[k] = B[i]
            i += 1
        else:
            A[k] = C[j]
            j += 1 

A = [12, 9, 3, 7, 14, 11, 6, 2, 10, 5]
p = 0
r = len(A)  
print(A)
mergesort(A, p, r)
print(A)
