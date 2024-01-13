# CPP_2-42

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

