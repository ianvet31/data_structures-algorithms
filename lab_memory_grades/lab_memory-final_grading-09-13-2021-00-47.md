---

This report was generated for **ivette2** using **1bf71682288f74af7979be7b3434413cd4674c0b** (latest commit as of **September 12th 2021, 11:59 pm**)

---




## Score: 100/100 (100.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c letter.cpp -o .objs/letter.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c room.cpp -o .objs/room.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c allocator.cpp -o .objs/allocator.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c fileio.cpp -o .objs/fileio.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests.cpp -o .objs/tests/tests.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/letter.o .objs/room.o .objs/allocator.o .objs/fileio.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests.o .objs/cs225/catch/catchmain.o  -std=c++14 -stdlib=libc++ -lc++abi -o test

```


### ✓ - [5/5] - Test the constructor (valgrind)

- **Points**: 5 / 5

```
==62== Memcheck, a memory error detector
==62== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==62== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==62== Command: ./test -r xml "Test\ the\ constructor\ (valgrind)"
==62== 
==62== 
==62== HEAP SUMMARY:
==62==     in use at exit: 0 bytes in 0 blocks
==62==   total heap usage: 2,501 allocs, 2,501 frees, 280,552 bytes allocated
==62== 
==62== All heap blocks were freed -- no leaks are possible
==62== 
==62== For counts of detected and suppressed errors, rerun with: -v
==62== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - Test allocate() (valgrind)

- **Points**: 5 / 5

```
==64== Memcheck, a memory error detector
==64== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==64== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==64== Command: ./test -r xml "Test\ allocate()\ (valgrind)"
==64== 
==64== 
==64== HEAP SUMMARY:
==64==     in use at exit: 0 bytes in 0 blocks
==64==   total heap usage: 2,501 allocs, 2,501 frees, 278,360 bytes allocated
==64== 
==64== All heap blocks were freed -- no leaks are possible
==64== 
==64== For counts of detected and suppressed errors, rerun with: -v
==64== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [20/20] - Test printRooms() (valgrind)

- **Points**: 20 / 20

```
==66== Memcheck, a memory error detector
==66== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==66== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==66== Command: ./test -r xml "Test\ printRooms()\ (valgrind)"
==66== 
==66== 
==66== HEAP SUMMARY:
==66==     in use at exit: 0 bytes in 0 blocks
==66==   total heap usage: 2,505 allocs, 2,505 frees, 279,080 bytes allocated
==66== 
==66== All heap blocks were freed -- no leaks are possible
==66== 
==66== For counts of detected and suppressed errors, rerun with: -v
==66== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [30/30] - Test printRooms() for overall output

- **Points**: 30 / 30





### ✓ - [40/40] - Test printRooms() for individual output

- **Points**: 40 / 40





---