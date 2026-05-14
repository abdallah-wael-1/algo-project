# Diagonal Difference — Algorithms Project

> Given an n×n square matrix, calculate the **absolute difference** between the sums of its two diagonals.

---

## Problem Statement

For a square matrix of size **n×n**:
- **Primary diagonal** (top-left → bottom-right): elements where `i == j`
- **Secondary diagonal** (top-right → bottom-left): elements where `i + j == n - 1`

**Result** = `| sum(primary diagonal) - sum(secondary diagonal) |`

### Example
```
Matrix:        Primary diagonal   = 11 + 5 + (-12) = 4
11  2   4      Secondary diagonal =  4 + 5 +  10   = 19
 4  5   6      
10  8 -12      Output: |4 - 19| = 15
```

### Constraints
```
-100 < arr[i][j] < 100
```

---

## Repository Structure

```
algo-project/
├── Documentation/
│   └── Diagonal_Difference_Project.docx   # Full report (pseudo code, analysis, comparison)
└── Implementation/
    ├── non_recursive.c                     # Iterative solution — O(n²)
    └── recursive.c                         # Recursive solution — O(n)
```

---

## Algorithms

### 1. Non-Recursive (Iterative) — `O(n²)`

Traverses **all n² elements** using nested loops, accumulating both diagonal sums simultaneously.

```c
int DiagonalDifference(int n, int array[n][n]) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j)       sum1 += array[i][j];
            if (i + j == n-1) sum2 += array[i][j];
        }
    return (sum1 > sum2) ? sum1 - sum2 : sum2 - sum1;
}
```

| Case | Time | Space |
|------|------|-------|
| Best / Average / Worst | **O(n²)** | O(1) |

---

### 2. Recursive — `O(n)`

Processes **only the 2n diagonal elements**, one row per recursive call.

```c
int DiagonalDifference(int n, int i, int arr[n][n]) {
    if (i == n) return 0;
    int res = arr[i][i] - arr[i][n - 1 - i];
    return res + DiagonalDifference(n, i + 1, arr);
}
```

| Case | Time | Space |
|------|------|-------|
| Best / Average / Worst | **O(n)** | O(n) call stack |

---

## Comparison

| Feature | Non-Recursive | Recursive |
|---|---|---|
| Elements Visited | All n² | Only 2n diagonal elements |
| Time Complexity | O(n²) | **O(n)** ✓ |
| Space Complexity | **O(1)** ✓ | O(n) — call stack |
| Readability | Easy | Concise, needs recursion knowledge |
| Performance (large n) | Slower | **Faster** ✓ |
| Stack Overflow Risk | None | Possible for very large n |

---

## How to Compile & Run

```bash
# Non-Recursive
gcc non_recursive.c -o non_recursive
./non_recursive

# Recursive
gcc recursive.c -o recursive
./recursive
```

**Sample session:**
```
Enter array size
3
Enter array elements
11 2 4
4 5 6
10 8 -12
Difference is 15
```
