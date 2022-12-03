# How to Run & Test

## Building/Compiling
To compile the program, first move into the folder directory. Then type ```g++ main.cpp array.cpp```, and finally ```./a``` to execute.

## Testing

Most of the functions behave as they were expected to by the professor, but some additional documentation will be provided.

### <ins>Constructors</ins>

#### Default constructor: ```Array()```
- Initializes both ```_size``` and ```_data``` to zero.

#### Copy constructor: ```Array(const Array &other)```
- Initialized the array's information to that of array ```other```.

#### Constructor w/ size & initialization value: ```Array(unsigned n, double v)```
- Initializes ```this``` array of size ```n``` with all elements equal to ```v```. All array elements are initialized to ```0.0``` if otherwise not specified.
- E.g.) ```arr1(5)``` --> Array of size 5 with all elements equal to 0
- E.g.) ```arr1(5,1)``` --> Array of size 5 with all elements equal to 1

#### Destructor: ```~Array()```
- Frees the memory.

### <ins>Misc. Member Functions</ins>

#### Size: ```size()```
- Returns the size of an array.

#### Data pointer: ```*data()```
- Overloaded function. Returns the address of the data array pointer as either a reference or copy.

#### Copy: ```copy(const Array &rhs)```
- Copies over ```rhs``` array information into ```this``` array as long as both are of equal size.
- If both arrays are not of the same size, the function will return nothing and an error will be thrown.
- E.g.) ```arr1.copy(arr2)``` --> If both ```arr1``` and ```arr2``` have the same size, then effectively: ```arr1 = arr2```

#### Indexing: ```&at(unsigned index)```
- Overloaded function. Returns the value of the indexed element in ```this``` array.
- E.g.) If ```arr1 = [2, 3, 6, 4]```, then ```arr1.at(2)``` is equal to ```6```.

#### Resize: ```resize(unsigned new_size, bool prsv)```
- Resizes ```this``` array to size ```new_size```. The ```prsv``` flag preserves the elements of the array prior to resizing. It is ```true``` by default. 
- If ```new_size``` is larger than the old array size, its new elements will be set to zero.
- E.g.) If ```arr1 = [1 2 3]```, then ```arr1.resize(5)``` becomes ```arr1 = [1 2 3 0 0]```
- E.g.) If ```arr1 = [1 2 3]```, then ```arr1.resize(5,false)``` becomes ```arr1 = [0 0 0 0 0]```

### <ins>Math Member Functions</ins>

#### Norm of array: ```norm()```
- Returns the magnitude of ```this``` array.

#### Sum of array: ```sum()```
- Returns the sum of all ```this``` array elements.

#### Maximum element of array: ```max()```
- Returns the maximum element of ```this``` array via a linear search.

#### Minimum element of array: ```min()```
- Returns the minimum element of ```this``` array via a linear search.

#### Dot product: ```dot(const Array &rhs)```
- Takes the dot product of ```this``` array and array ```rhs```. Both arrays must be of the same size.
- If both arrays are not of the same size, the function will return a value of ```-1``` and an error will be thrown.
- E.g.) ```arr1.dot(arr2)```

#### Add two arrays: ```add(const Array &rhs)```
- Adds the corresponding elements of ```this``` array and array ```rhs```.
- The new array created has the same size as ```rhs```.
- E.g.) If ```arr1 = [1 2 3]``` and ```rhs = [9 3 4 2 5]```, then ```arr1.add(rhs)``` is equal to ```[10 5 7 2 5]```

#### Subtracts two arrays: ```sub(const Array &rhs)```
- Subtracts the corresponding elements of ```this``` array and array ```rhs```.
- The new array created has the same size as ```rhs```.
- E.g.) If ```arr1 = [1 2 3]``` and ```rhs = [9 3 4 2 5]```, then ```arr1.add(rhs)``` is equal to ```[-8 -1 -1 -2 -5]```

#### Terminal print array: ```print()```
- Prints out ```this``` array information in the terminal.
- E.g.) ```arr1.print()``` --> ```Size: 5, Elements: [1 2 3 4 5]```

### <ins>Operators</ins>

#### The ```[]``` operator:
- Used to index the element of an array.
- E.g.) ```arr[i]``` where ```0 <= i < _size```

#### The ```=``` operator:
- Used to assign one Array object to another.
- E.g.) ```Array arr3 = arr1 + arr2```

#### The ```+``` operator:
- Returns the sum of two arrays. Simpler version of ```add()```
- E.g.) ```arr1 + arr2```

#### The ```-``` operator:
- Returns the difference between two arrays. Simpler version of ```sub()```
- E.g.) ```arr1 - arr2```
