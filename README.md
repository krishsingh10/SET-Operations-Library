# SET Operations Library

This C++ library provides a comprehensive implementation for managing sets, supporting operations like insertion, deletion, membership checks, and set operations such as union, intersection, and difference. It allows efficient handling and manipulation of sets stored dynamically in a vector of vectors.




## Features

- Insert: Add an element to a set while maintaining the order.
- Delete: Remove an element from a set.
- Size: Get the size of a set.
- Belongsto: Check if an element belongs to a set.
- Union: Perform the union of two sets.
- Intersection: Compute the intersection of two sets.
- Difference: Calculate the difference between two sets.
- SymmetricDifference: Determine the symmetric difference between two sets.
- Print: Print the elements of a set.

## Usage
-  'setNum' 'setData': Insert 'setData' into 'set setNum'.
  
   0 5   # Inserts 5 into set 0
  
   0 3   # Inserts 3 into set 0
  
   0 8   # Inserts 8 into set 0

-  'setNum' 'setData': Delete 'setData' from 'set setNum'.

    0 3   # Deletes 3 from set 0

-  'setNum' 'setData': Check if 'setData' belongs to 'set setNum'.

    0 5   # Returns 1 if 5 is in set 0, otherwise 0

-  'setNum1' 'setNum2': Perform the union of sets 'setNum1' and 'setNum2' and store the result in 'setNum1'.

     0 1   # Union of sets 0 and 1, result stored in set 0

-  'setNum1' 'setNum2': Compute the intersection of sets 'setNum1' and 'setNum2' and store the result in 'setNum1'.

     0 1   # Intersection of sets 0 and 1, result stored in set 0

-  'setNum': Get the size of 'set setNum'.

     0     # Returns the size of set 0

-  'setNum1' 'setNum2': Calculate the difference of sets 'setNum1' and 'setNum2' and store the result in 'setNum1'.

    0 1   # Difference of sets 0 and 1, result stored in set 0

-  'setNum1' 'setNum2': Calculate the symmetric  difference of sets 'setNum1' and 'setNum2' and store the result in 'setNum1'.

    0 1   # Symmetric difference of sets 0 and 1, result stored in set 0

-  'setNum': Print the elements of set 'setNum'.

    9 0     # Prints the elements of set 0

### Example

```sh
1 0 5
1 0 3
1 0 8
9 0


## Implementation Details

The `SET` class encapsulates the set operations. It uses a private vector of vectors to store the sets. The public methods provide the functionality for manipulating the sets and performing various operations on them.



   



