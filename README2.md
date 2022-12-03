# How to Run & Test

## Building/Compiling
To compile the program, first move into the folder directory. Then type ```g++ main.cpp array.cpp```, and finally ```./a``` to execute.

## Testing

Most of the functions behave as they were expected to by the professor, but some additional documentation will be provided.

### Constructors

#### Default constructor: ```Array()```
- Initializes both ```_size``` and ```_data``` to zero.

#### Copy constructor: ```Array(const Array &other)```
- Initialized the array's information to that of array ```other```.

#### Constructor w/ size & initialization value: ```Array(unsigned n, double v)```
- Initializes an array of size ```n``` with all elements equal to ```v```. All array elements are initialized to ```0.0``` if otherwise not specified.

#### Destructor: ```~Array()```
- Frees the memory.

### Member Functions

#### Size: ```size()```
- Returns the size of an array.

#### Data pointer: ```*data()```
- Overloaded function. Returns the address of the data array pointer as either a reference or copy.

#### Copy: ```copy(const Array &rhs)```
- Places the
