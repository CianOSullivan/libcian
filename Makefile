all: install example

.PHONY: example clean_docs cleanup checkroot

# Install the standard library so it can be accessed by gcc
install: checkroot symlink

# Quit compilitation if user is not root
checkroot:
ifneq ($(shell id -u), 0)
	@echo "You must be root to perform this action."
	false
endif

# Add version numbers and link these to .so file
symlink: compile cleanup
	ln -sf /usr/lib/libcian.so.1.0 /usr/lib/libcian.so.1
	ln -sf /usr/lib/libcian.so.1.0 /usr/lib/libcian.so

# Move the header files to an include directory and the shared 
# library to a standard library directory
move: 
	mkdir -p /usr/include/libcian
	cp include/libcian/*.h /usr/include/libcian

# Compile the libcian source files and link them
compile: move
	gcc -g -Wall -Werror -fPIC -Iinclude/libcian -c src/*.c
	gcc -shared -o libcian.so.1.0 *.o
	mv libcian.so.1.0 /usr/lib

example:
	cd example && $(MAKE)
	./example/testProgram

# Remove the generated .o files
cleanup:
	rm -f *.o

# Generate libcian documentation into the docs directory
docs: clean_docs
	doxygen docs/Doxyfile

# Remove the html and latex files
clean_docs:
	rm -fr docs/html
	rm -fr docs/latex

