all: install

install: symlink

symlink: move
	ln -sf /usr/lib/libcian.so.1.0 /usr/lib/libcian.so.1
	ln -sf /usr/lib/libcian.so.1.0 /usr/lib/libcian.so

move: compile
	mkdir -p /usr/include/libcian
	cp *.h /usr/include/libcian
	mv libcian.so.1.0 /usr/lib

compile:
	gcc -Wall -Werror -fPIC -c c_str.c
	gcc -shared -o libcian.so.1.0 *.o
