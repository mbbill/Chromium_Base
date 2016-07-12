# example build for OSX
all:
	clang++ test.cpp -std=c++14 -stdlib=libc++ -Wall -Llibs/macOS -lbase -Isrc -o test
	install_name_tool -change @rpath/libbase.dylib @executable_path/libs/macOS/libbase.dylib test
	#clang++ libs/macOS/libbase.a test.cpp -std=c++14 -stdlib=libc++ -Isrc -framework CoreFoundation -framework ApplicationServices  -framework AppKit -framework IOKit -framework Security -Wall  -o test
