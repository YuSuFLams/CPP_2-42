# CPP_2-42

# Casting:
In C++, casting is a way to explicitly convert a value from one data type to another. There are several types of casts in C++, including static_cast, dynamic_cast, const_cast, and reinterpret_cast. Let's discuss each one of them.

## 1. `static_cast`:

`static_cast` is the most common and safest casting operator. It is used for implicit conversions that are considered safe by the compiler.

```cpp
int intValue = 10;
double doubleValue = static_cast<double>(intValue);
```

## 2. `dynamic_cast`:

`dynamic_cast` is primarily used for polymorphic types (i.e., classes with virtual functions). It is used for safe downcasting during runtime.

```cpp
class Base {
public:
    virtual void someFunction() {}
};

class Derived : public Base {};

Base* basePtr = new Derived();
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

if (derivedPtr) {
    // dynamic_cast successful
} else {
    // dynamic_cast failed
}
```
## 3. `const_cast`:

`const_cast` is used to add or remove the const qualifier from a variable.

```cpp
const int constValue = 5;
int nonConstValue = const_cast<int>(constValue);
```

## 4. `reinterpret_cast`:

`reinterpret_cast` is a powerful and unsafe casting operator that can be used to convert between unrelated types, such as between pointers to objects and pointers to functions.

```cpp
int intValue = 42;
char* charPtr = reinterpret_cast<char*>(&intValue);
```

# Templates:
Templates in C++ are a powerful feature that allows you to write generic code, making it possible to create functions and classes that work with different data types.

## Function Templates:
### Basic Syntax:
```cpp
// Template function
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int sumInt = add(5, 7);
    double sumDouble = add(3.14, 2.71);

    return 0;
}
```

In this example, `add` is a template function that can add two values of any type `T`. The compiler generates the appropriate code for each type used.
### Explicit Specialization:
```cpp
// Template function
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Explicit specialization for strings
template <>
std::string add(std::string a, std::string b) {
    return a + " " + b;
}

int main() {
    int sumInt = add(5, 7);
    double sumDouble = add(3.14, 2.71);
    std::string concatenatedString = add("Hello", "World");

    return 0;
}
```

Explicit specialization allows you to provide a specific implementation for a particular data type.



## Class Templates:

### Basic Syntax:
```cpp
// Template class
template <typename T>
class Pair {
public:
    T first;
    T second;

    Pair(T f, T s) : first(f), second(s) {}
};

int main() {
    Pair<int> intPair(5, 7);
    Pair<double> doublePair(3.14, 2.71);

    return 0;
}
```

Here, `Pair` is a template class that holds two values of type `T`.


### Template Class with Non-Type Parameters:
```cpp
// Template class with a non-type parameter
template <typename T, int size>
class Array {
public:
    T elements[size];
};

int main() {
    Array<int, 5> intArray;
    Array<double, 10> doubleArray;

    return 0;
}
```

In this example, `Array` is a template class with a non-type parameter `size`.


## Variadic Templates:

```cpp
// Variadic template function
template <typename T>
void print(T value) {
    std::cout << value << std::endl;
}

template <typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    print(args...);
}

int main() {
    print(1, 2.5, "Hello");

    return 0;
}
```

Variadic templates allow you to create functions or classes that accept a variable number of arguments.


# Casting Operators in C++:

1. static_cast
2. dynamic_cast
3. const_cast
4. reinterpret_cast

#  static_cast: 
The static_cast operator is the most commonly used casting operator in C++. It performs compile-time type conversion and is mainly used for explicit conversions that are considered safe by the compiler. 


### Syntax of static_cast
```cpp
static_cast <new_type> (expression);
```

where,
* expression: Data to be converted.
* new_type: Desired type of expression

The ``static_cast`` can be used to convert between related types, such as numeric types or pointers in the same inheritance hierarchy.

#### Example of static_cast: 

```cpp
// C++ program to illustrate the static_cast 
#include <iostream> 
#include <typeinfo> 

int main() 
{ 

	int num = 10; 

	// converting int to double 
	double numDouble = static_cast<double>(num); 

	// printing data type 
	std::cout << typeid(num).name() << std::endl; 

	// typecasting 
	std::cout << typeid(static_cast<double>(num)).name() << std::endl; 

	// printing double type t 
	std::cout << typeid(numDouble).name() << std::endl; 

	return 0;
}

```
Output

```cpp
i
d
d
```

In this example, we have included the “typeinfo” library so that we can use typeid() function to check the data type. We have defined an integer variable ‘num’ and converted it into a double using static_cast. After that, we print the data types of variables and pass static_cast<double>(num) in typeid() function to check its data type. we can see the output “i, d, d” is printed where ‘i’ denotes integer and ‘d’ denotes double.

# dynamic_castdivBlock

The dynamic_cast operator is mainly used to perform downcasting (converting a pointer/reference of a base class to a derived class). It ensures type safety by performing a runtime check to verify the validity of the conversion.

### Syntax of dynamic_cast
```cpp
dynamic_cast <new_type> (expression);
```
If the conversion is not possible, dynamic_cast returns a null pointer (for pointer conversions) or throws a bad_cast exception (for reference conversions).

#### Example of dynamic_cast
```cpp
// C++ program to illustrate the dynamic_cast 
#include <iostream> 

// Base Class 
class Animal { 
public: 
	virtual void speak() const
	{ 
		std::cout << "Animal speaks." << std::endl; 
	} 
}; 

// Derived Class 
class Dog : public Animal { 
public: 
	void speak() const override 
	{ 
		std::cout << "Dog barks." << std::endl; 
	} 
}; 

// Derived Class 
class Cat : public Animal { 
public: 
	void speak() const override 
	{ 
		std::cout << "Cat meows." << std::endl; 
	} 
}; 

int main() 
{ 
	// base class pointer to derived class object 
	Animal* animalPtr = new Dog(); 

	// downcasting 
	Dog* dogPtr = dynamic_cast<Dog*>(animalPtr); 

	// checking if the typecasting is successfull 
	if (dogPtr) { 
		dogPtr->speak(); 
	} 
	else { 
		std::cout << "Failed to cast to Dog." << std::endl; 
	} 

	// typecasting to other dervied class 
	Cat* catPtr = dynamic_cast<Cat*>(animalPtr); 
	if (catPtr) { 
		catPtr->speak(); 
	} 
	else { 
		std::cout << "Failed to cast to Cat." << std::endl; 
	} 

	delete animalPtr; 
	return 0; 
}

```
Output

```cpp
Dog barks.
Failed to cast to Cat.
```

Explanation : The first line of output is printed because the ‘animalPtr’ of the ‘Animal’ type is successfully cast to the ‘Dog’ type and speak() function of the Dog class is invoked but the casting of the ‘Animal’ type to ‘Cat’ type is failed because ‘animalPtr’ points to a ‘Dog’ object thus, the dynamic cast fails because the typecasting is not safe.

# const_cast

The const_cast operator is used to modify the const or volatile qualifier of a variable. It allows programmers to temporarily remove the constancy of an object and make modifications. Caution must be exercised when using const_cast, as modifying a const object can lead to undefined behavior.

### Syntax for const_cast
```cpp
const_cast <new_type> (expression);
```
#### Example of const_cast
```cpp
// C++ program to illustrate the const_cast 
#include <iostream> 

int main() 
{ 

	const int number = 5; 
	// Pointer to a const int 
	const int* ptr = &number; 

	// int* nonConstPtr = ptr; if we use this 
	// instead of without using const_cast 
	// we will get error of invalid conversion 
	int* nonConstPtr = const_cast<int*>(ptr); 
	*nonConstPtr = 10; 

	std::cout << "Modified number: " << *nonConstPtr << std::endl; 

	return 0; 
}

```
Output

```cpp
Dog barks.
Failed to cast to Cat.
```Output

```cpp
Modified number: 10
```
In the above example, we have modified the value of the const type pointer by changing its qualifier from const to non-const and then printing the modified value.

# reinterpret_cast
The reinterpret_cast operator is used to convert the pointer to any other type of pointer. It does not perform any check whether the pointer converted is of the same type or not.

The statement explains the behavior of the `reinterpret_cast` operator in C++. Let's break it down:

1. **Convert the pointer to any other type of pointer:**
   - `reinterpret_cast` allows you to convert a pointer of one type to a pointer of any other type. This means you can change the type of the pointer, regardless of the types involved.
2. **It does not perform any check:**
   - Unlike some other casting operators like `dynamic_cast`, `reinterpret_cast` does not perform any runtime type checking or validation. It simply assumes that the conversion is valid and directly manipulates the underlying binary representation of the pointer.
3. **Whether the pointer converted is of the same type or not:**
   - `reinterpret_cast` does not care about the compatibility or relationship between the types involved. It treats the bits of the original pointer as if they represent an object of the new type. This can be dangerous if the types are not related, as it may result in undefined behavior.

##### Here's an example:

```cpp
int intValue = 42;
double* doublePtr = reinterpret_cast<double*>(&intValue);
```

#### Syntax of reinterpret_cast
```cpp
reinterpret_cast <new_type> (expression);
```
#### Example of reinterpret_cast
```cpp
// C++ program to illustrate the reinterpret_cast 
#include <iostream> 

int main() 
{ 
	int num = 10; 
	// Store the address of number in numberPointer 
	int* numPtr = &num; 

	// Reinterpreting the pointer as a char pointer 
	char* charPtr = reinterpret_cast<char*>(numPtr); 

	// Printing the memory addresses and values 
	std::cout << "Integer Address: " << numPtr << std::endl; 
	std::cout << "Char Address: " << reinterpret_cast<void*>(charPtr) << std::endl; 
	return 0; 
}

```
Output
```cpp
Integer Address: 0x7fff64789f1c
Char Address: 0x7fff64789f1c
```
In the above example, we have defined an int variable ‘number’ and then store the address of ‘number’ in ‘numberPointer’ of the int type after that we have converted the ‘numberPointer’ of the int type into char pointer and then store it into ‘charPointer’ variable. To verify that we have printed the address of both numberPointer and charPointer. To print the address stored in ‘charPointer’ reinterpret_cast<void*> is used to bypass the type-checking mechanism of C++ and allow the pointer to be printed as a generic memory address without any type-specific interpretation.

```
Note: const_cast and reinterpret_cast are generally not recommended as they vulnerable to different kinds of errors.
```