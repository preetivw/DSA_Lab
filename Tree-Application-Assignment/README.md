# Application of Trees – Library Management System

## Scenario

In a library, books need to be stored in a structured way so that operations like searching, inserting, and deleting books can be performed efficiently.

A Binary Search Tree (BST) is used where each node represents a book with a unique Book ID. The tree structure allows fast retrieval and maintains sorted order.

---

## Justification

* BST provides efficient searching compared to linear search.
* Data is stored in sorted order automatically.
* Insertion and deletion operations are faster than arrays for large data.
* Suitable for dynamic data like library records.

---

## Time Complexity Analysis

| Operation | Time Complexity                  |
| --------- | -------------------------------- |
| Insertion | O(log n) (average), O(n) (worst) |
| Search    | O(log n) (average), O(n) (worst) |
| Deletion  | O(log n) (average), O(n) (worst) |
| Traversal | O(n)                             |

---

## Program Features

* Insert book
* Search book
* Delete book
* Display books in sorted order

---

## Conclusion

Binary Search Tree is an efficient data structure for managing hierarchical and dynamic data such as library systems.
