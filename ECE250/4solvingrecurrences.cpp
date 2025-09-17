// ===== ECE250: SOLVING RECURRENCES - ESSENTIAL EXAM NOTES =====

// DEFINITION
// Recurrence: equation/inequality describing function in terms of smaller inputs
// Example: Merge Sort T(n) = Θ(1) if n=1, 2T(n/2) + Θ(n) if n>1

// ===== THREE METHODS FOR SOLVING RECURRENCES =====
// 1. Recursion-Tree Method
// 2. Repeated Substitution
// 3. Master Method

// ===== METHOD 1: RECURSION TREE =====
// Steps:
// 1. Draw tree showing recursive calls
// 2. Calculate cost at each level
// 3. Sum all levels
// 4. Use geometric series if needed

// EXAMPLE: T(n) = T(n/4) + T(n/2) + n²
/*
Level 0:           n²                    Cost: n²
Level 1:     (n/4)² + (n/2)²            Cost: n²/16 + n²/4 = 5n²/16
Level 2: (n/16)² + (n/8)² + (n/8)² + (n/4)²  Cost: 25n²/256
...

Total = n²(1 + 5/16 + 25/256 + ...)
      = n²(geometric series)
      = Θ(n²)
*/

// GEOMETRIC SERIES FORMULAS (CRITICAL FOR EXAMS)
// 1 + x + x² + x³ + ... = 1/(1-x) for |x| < 1
// 1 + x + x² + ... + x^n = (x^(n+1) - 1)/(x - 1) for x ≠ 1

// ===== METHOD 2: REPEATED SUBSTITUTION =====
// Steps:
// 1. Substitute recurrence into itself repeatedly
// 2. Find pattern after i substitutions
// 3. Choose i to reach base case
// 4. Solve resulting summation

// EXAMPLE 1: Linear Search
// T(n) = T(n-1) + c
// T(n) = T(n-2) + c + c = T(n-2) + 2c
// T(n) = T(n-3) + 3c
// Pattern: T(n) = T(n-i) + i*c
// Base case: i = n-1, so T(1) + (n-1)*c = Θ(n)

// EXAMPLE 2: Binary Search
// T(n) = T(n/2) + c
// T(n) = T(n/4) + c + c = T(n/4) + 2c
// T(n) = T(n/8) + 3c
// Pattern: T(n) = T(n/2^i) + i*c
// Base case: n/2^i = 1, so i = log₂(n)
// Result: T(1) + log₂(n)*c = Θ(log n)

// EXAMPLE 3: T(n) = 2T(n/2) + 1
// T(n) = 2[2T(n/4) + 1] + 1 = 4T(n/4) + 2 + 1 = 4T(n/4) + 3
// T(n) = 4[2T(n/8) + 1] + 3 = 8T(n/8) + 4 + 3 = 8T(n/8) + 7
// Pattern: T(n) = 2^i * T(n/2^i) + (2^i - 1)
// Base case: n/2^i = 1, so i = log₂(n)
// Result: 2^(log₂n) * T(1) + (2^(log₂n) - 1) = n*T(1) + (n-1) = Θ(n)

// ===== COMMON RECURRENCE PATTERNS & SOLUTIONS =====
// T(n) = T(n-1) + Θ(1)           → Θ(n)      [Linear search]
// T(n) = T(n/2) + Θ(1)           → Θ(log n)  [Binary search]
// T(n) = 2T(n/2) + Θ(1)          → Θ(n)      [Tree traversal]
// T(n) = 2T(n/2) + Θ(n)          → Θ(n log n) [Merge sort]
// T(n) = T(n-1) + Θ(n)           → Θ(n²)     [Selection sort]

// ===== EXAM TIPS =====
// 1. For recursion tree: draw carefully, calculate level costs, sum geometric series
// 2. For substitution: substitute 3-4 times to find pattern
// 3. Always verify base case works with your pattern
// 4. Know geometric series formulas by heart
// 5. Common mistake: forgetting to account for all nodes at each tree level

// ===== QUICK RECOGNITION GUIDE =====
// If you see T(n/2): likely Θ(log n) or Θ(n log n)
// If you see T(n-1): likely Θ(n) or Θ(n²)
// If you see 2T(n/2): check the +term to distinguish Θ(n) vs Θ(n log n)
// Multiple recursive calls (like T(n/4) + T(n/2)): use recursion tree