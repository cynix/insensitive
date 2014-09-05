insensitive.dylib: insensitive.c
	cc -arch i386 -arch x86_64 -Wall -Wno-deprecated-declarations -framework CoreServices -o insensitive.dylib -dynamiclib insensitive.c

.PHONY: clean run

clean:
	rm -rf insensitive.dylib

run: insensitive.dylib
	DYLD_INSERT_LIBRARIES=$(shell pwd)/insensitive.dylib "$(CMD)"
