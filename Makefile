all: all-release

cmake-debug:
	mkdir -p build/debug
	cd build/debug && cmake -D CMAKE_BUILD_TYPE=Debug -DGTEST=ON ../..

build-debug: cmake-debug
	cd build/debug -DGTEST=ON && $(MAKE)

test-debug: build-debug
	cd build/debug -DGTEST=ON && $(MAKE) test

all-debug: build-debug

cmake-release:
	mkdir -p build/release
	cd build/release && cmake -D CMAKE_BUILD_TYPE=Release -DGTEST=OFF ../..

build-release: cmake-release
	cd build/release && $(MAKE)

build-static:
	mkdir -p build/static
	cd build/static && cmake -D CMAKE_BUILD_TYPE=Release -DGTEST=OFF ../..
	cd build/static && $(MAKE) SHARED=0 CC='gcc -static'

test-release: build-release
	cd build/release && $(MAKE) test

all-release: build-release

clean:
	rm -rf build

tags:
	ctags -R --sort=1 --c++-kinds=+p --fields=+iaS --extra=+q --language-force=C++ src contrib tests/gtest

.PHONY: all cmake-debug build-debug test-debug all-debug cmake-release build-release test-release all-release clean tags

