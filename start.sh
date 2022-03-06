export LIBRARY_PATH="$LIBRARY_PATH:/opt/homebrew/lib"
g++ index_sdl.cpp -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -o hello_sdl2.out -lSDL2
./hello_sdl2.out