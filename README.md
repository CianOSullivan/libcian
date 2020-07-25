# Libcian

Personal standard library which may be used in my projects. This is an early stage project and will likely be grown over time.  

# Installation
There are no external dependencies for this project other than the C standard library.  

To install libcian:  

```
git clone https://github.com/CianOSullivan/libcian
cd libcian
sudo make install
```

All header files will be installed to /usr/include/ and the shared library to /usr/lib/.  

# Using libcian

To use libcian, use the following template when compiling projects using gcc:  

```
gcc -o progName progName.c -I/usr/include/libcian -L/usr/lib -lcian
```

Example usage of libcian can be found under [example](example/). This directory demonstrates usage of libcian through a series of unit tests which verify the usage of the library.

To generate documentation for libcian (requires doxygen):  

```
make docs
```

Feel free to contribute or suggest any useful changes!
