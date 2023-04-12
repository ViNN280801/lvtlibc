# lvtlibc

<p>it does not represent a specific library, (yes, I know, the name of the repository does not correspond to the content). This repository was created in order to access it using its functions in your projects. The functions are separated by preprocessor directives <code>#ifndef</code>. cmake file just for my training in writing similar files.</p>

## Compiling

### Using CMake & GNU GCC

<b>Attention.</b> These commands creating new subdirectory with shared library in your "/opt" directory.

```console
cmake .
cmake --build .
sudo mkdir -p /opt/lvtc
sudo mv *.so* /opt/lvtc
gcc -g -c main.c -lm -std=c2x -Wall -Wpedantic -Wextra -o main.o
gcc main.o -L/opt/lvtc -llvt -lm -std=c2x -o a.out
rm main.o
LD_LIBRARY_PATH=/opt/lvtc ./a.out
```

Command <code>cmake --build .</code> can be replaced with <code>make</code>
File <b>main.c</b> presented your source file with the "main()" function

### Using GNU GCC

<b>Attention.</b> These commands creating new subdirectory with shared library in your "/opt" directory.

```console
gcc -g -c lvt.c -lm -std=c2x -fPIC -Wall -Wpedantic -Wextra -o lvt.o
gcc -shared lvt.o -o liblvtc.so
sudo mkdir -p /opt/lvtc
sudo mv liblvtc.so /opt/lvtc
gcc -g -c main.c -lm -std=c2x -Wall -Wpedantic -Wextra -o main.o
gcc main.o -L/opt/lvtc -llvt -lm -std=c2x -o a.out
rm lvt.o main.o
LD_LIBRARY_PATH=/opt/lvtc ./a.out
```

- 1st line - compiling with "[-g](https://www.rapidtables.com/code/linux/gcc/gcc-g.html)" (default info about debug), "[-c](https://www.rapidtables.com/code/linux/gcc/gcc-c.html)" (means compile), "[-std=c2x](https://gcc.gnu.org/onlinedocs/gcc/Standards.html)" (A further version of the C standard, known as C2X, is under development), "[-fPIC](https://www.rapidtables.com/code/linux/gcc/gcc-fpic.html)" (position independent code. It's nead to compile shared library), "[-Wall](https://www.rapidtables.com/code/linux/gcc/gcc-wall.html) [-Wpedantic -Wextra](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)" (connects all kinds of warnings), "[-o](https://www.rapidtables.com/code/linux/gcc/gcc-o.html#output%20file)" (output file)
- 2nd line - "[-shared](https://www.rapidtables.com/code/linux/gcc/gcc-shared.html)" - compiling shared library with ".so" extension - UNIX/Linux dynamic library
- 3rd line - ("ls" doesn't counts) compiling source code with "main()" function to an object file
- 4th line - copying path of working directory (pwd) to the
- 5th line - Linking object files with shared library ("[-L](https://www.rapidtables.com/code/linux/gcc/gcc-l.html)"), "-llvt" means that compiler GNU GCC have to search such kinds of files (on UNIX/Linux OS): liblvt.a (static library) or liblvtc.so (dynamic library)
- 6th line - Adding new path to environment variable "[LD_LIBRARY_PATH](https://linuxhint.com/what-is-ld-library-path/)" and running executive file, at the same time it is not necessary that executive file must have ".out" extension.
