MERGE TWO SORTED ARRAY
===

```
    a = [1, 4, 6, 7, 11, 44, 64]
    b = [3, 5, 7, 33, 56, 102]

    N = |a|
    M = |b|

    ans = []

    aIdx = 0, bIdx = 0
    idx = 0

    // Find smaller element pointed by aIdx and bIdx and add that to final array.
    while aIdx < N && bIdx < M {
        if(a[aIdx] < b[bIdx])
            ans[idx++] = a[aIdx++]
        else
            ans[idx++] = b[bIdx++]
    }

    //Add remaining element of either array to ans.
    while(aIdx < N)
        ans[idx++] = a[aIdx++]

    while(bIdx < N)
        ans[idx++] = b[bIdx++]



```
