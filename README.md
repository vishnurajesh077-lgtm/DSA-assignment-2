Assignment 2: Government Database ID Search Analysis (Q11)
**Course:** PCCST303 - Data Structures and Algorithms  
**Department:** Computer Science & Design (CSD) | Vimal Jyothi Engineering College  

---
1. Problem Statement
A government database stores the following identification numbers:  
`A102, A25, A7, B100, B12, A120, B3, A45`

* **(a)** Implement a Binary Search Tree (BST) to organize the identification numbers and display its inorder traversal.
* **(b)** Compare the search performance of BST Search vs. Linear Search for selected identification numbers and record the number of comparisons observed.
* **(c)** Analyze how varying key lengths and insertion order affect BST height and search performance, comparing observed results with theoretical best-case and worst-case complexities. Suggest a suitable scalable approach.

---
2. Input Data & Execution Results

### Input Sequence
`["A102", "A25", "A7", "B100", "B12", "A120", "B3", "A45"]`

### Terminal Output
```text
=== GOVERNMENT DATABASE IDENTIFICATION SEARCH SYSTEM ===

1. Inserting Identification Numbers into BST:
Inserted: A102
Inserted: A25
Inserted: A7
Inserted: B100
Inserted: B12
Inserted: A120
Inserted: B3
Inserted: A45

2. Inorder Traversal (Sorted Identification Numbers):
A102 A120 A25 A45 A7 B100 B12 B3 

3. Search Performance Comparison:
-------------------------------------------------------------------
| Target ID | BST Found? | BST Comparisons | Linear Search Comp | 
-------------------------------------------------------------------
| A120      | YES        | 3               | 6                  |
| B3        | YES        | 3               | 7                  |
| A999      | NO         | 3               | 8                  |
-------------------------------------------------------------------
-assignment-2