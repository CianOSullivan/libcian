all: install

install: symlink

symlink: move
	ln -sf /usr/lib/libcian.so.1.0 /usr/lib/libcian.so.1
	ln -sf /usr/lib/libcian.so.1.0 /usr/lib/libcian.so

move: compile
	mkdir -p /usr/include/libcian
	cp include/libcian/*.h /usr/include/libcian
	mv libcian.so.1.0 /usr/lib

compile:
	gcc -Wall -Werror -fPIC -Iinclude/libcian -c src/*.c
	gcc -shared -o libcian.so.1.0 *.o

clean_docs:
	rm -fr docs/html
	rm -fr docs/latex

docs: clean_docs
	doxygen docs/Doxyfile
