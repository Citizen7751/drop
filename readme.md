# Drop - Random Bible Verses

This program just prints out random verses from the KJV Bible in the commandline.

It has 2 color modes. The default is RGB, since every computer with a graphical interface supports RGB, even in the commandline. However, if your computer does not have any GUI installed, it cannot display RGB colors. For this, it has something called ANSI mode, meaning it uses ANSI colors.

**RGB Mode**\
![](drop.png)

**ANSI Mode**\
![](drop_ansi.png)

## Usage
Upon opening, the user is greeted with a random verse. Hitting ```Enter``` brings up new verses. Exiting is done through first hitting ```Space``` and then ```Enter```.\
To activate ANSI colors, use the program with the ```-ansi``` keyword (see above).\
**Note:** To understand what the verse actually means, you need to know the context. (duh!)

## Build
**Requirements:** [GCC](https://gcc.gnu.org/) or [Clang](https://clang.llvm.org/) (or any other C compiler)

### Building on Windows:
GCC: ```gcc -o Drop.exe *.c```\
Clang:```clang -o Drop.exe *.c```

### Building on Linux:
GCC: ```gcc -o Drop *.c```\
Clang:```clang -o Drop *.c```

### Note
If you don't have any standalone compilers installed, but have Microsoft Visual Studio, you can copy-paste the sourcefiles into a new C/C++ project and execute it that way.

## License
This software is under the MIT License.
