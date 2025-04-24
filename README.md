## Compiling

### Windows

After installing [Mingw64](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-win32/seh/x86_64-8.1.0-release-win32-seh-rt_v6-rev0.7z/download), [SDL2](https://www.libsdl.org/download-2.0.php), [SDL_Image](https://www.libsdl.org/projects/SDL_image/) execute the following command in the project's root directory:

```
g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -I C:/mingw64/x86_64-w64-mingw32/include && g++ *.o -o bin/release/main -s -L C:/mingw64/x86_64-w64-mingw32/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image && start bin/release/main
```

```
C:/mingw64/bin/g++.exe -mwindows -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -I C:/mingw64/x86_64-w64-mingw32/include && C:/mingw64/bin/g++.exe -mwindows *.o -o bin/release/main -s -L C:/mingw64/x86_64-w64-mingw32/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image  && start bin/release/main
```

The compiled `.exe` is located in `./bin`. For it to run, you must copy the `./res` folder as well as all `.dll` files from your SDL installation to its directory.
