time complexity-->o(N)
types of two pointer
1)opposite direction(meet int the middle)
Use case: Sorted arrays, Palindrome checking.

Logic: One pointer starts at 0, the other at n-1. They move toward each other based on a condition.

2)Same Direction (Fast & Slow):
Use case: Removing duplicates, moving zeros, merging sorted arrays.

Logic: A "Fast" pointer scans the array, and a "Slow" pointer tells us where the next valid element should go.

