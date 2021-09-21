---

This report was generated for **ivette2** using **7032d1fc15412f3292883c51af1ab6a513441b36** (latest commit as of **September 20th 2021, 11:59 pm**)

---




## Score: 54/61 (88.52%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c Image.cpp -o .objs/Image.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c StickerSheet.cpp -o .objs/StickerSheet.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-part1.cpp -o .objs/tests/tests-part1.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-part2.cpp -o .objs/tests/tests-part2.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/Image.o .objs/StickerSheet.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests-part1.o .objs/tests/tests-part2.o .objs/cs225/catch/catchmain.o  -std=c++14 -stdlib=libc++ -lc++abi -o test

```


### ✓ - [1/1] - Image lighten() lightens pixels by 0.1

- **Points**: 1 / 1





### ✓ - [1/1] - Image lighten() does not lighten a pixel above 1.0

- **Points**: 1 / 1





### ✓ - [1/1] - Image darken(0.2) darkens pixels by 0.2

- **Points**: 1 / 1





### ✓ - [1/1] - Image darken(0.2) does not darken a pixel below 0.0

- **Points**: 1 / 1





### ✓ - [1/1] - Image saturate() saturates a pixels by 0.1

- **Points**: 1 / 1





### ✓ - [1/1] - Image rotateColor(double) rotates the color

- **Points**: 1 / 1





### ✓ - [1/1] - Image rotateColor(double) keeps the hue in the range 0..360

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(2.0) results in the correct width/height

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(0.5) results in the correct width/height

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(2) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(0.5) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(10000\, 200) results in the correct width/height

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(720\, 10000) results in the correct width/height

- **Points**: 1 / 1





### ✗ - [0/1] - Image scale(240\, 50) results in the correct width/height

- **Points**: 0 / 1


```
Original: img.height() * 0.5 == result.height()
Expanded: 50.0 == 0
```


### ✗ - [0/1] - Image scale(180\, 80) results in the correct width/height

- **Points**: 0 / 1


```
Original: img.height() * 0.5 == result.height()
Expanded: 50.0 == 0
```


### ✓ - [1/1] - Image scale(10000\, 200) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(720\, 10000) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✗ - [0/1] - Image scale(240\, 50) scales pixel data in a reasonable way

- **Points**: 0 / 1


```
Fatal Error: SIGABRT - Abort (abnormal termination) signal
```


### ✗ - [0/1] - Image scale(180\, 80) scales pixel data in a reasonable way

- **Points**: 0 / 1


```
Fatal Error: SIGABRT - Abort (abnormal termination) signal
```


### ✓ - [3/3] - Image doesn't have any memory erorrs

- **Points**: 3 / 3

```
==112== Memcheck, a memory error detector
==112== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==112== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==112== Command: ./test -r xml "Image\ doesn't\ have\ any\ memory\ erorrs"
==112== 
==112== 
==112== HEAP SUMMARY:
==112==     in use at exit: 0 bytes in 0 blocks
==112==   total heap usage: 2,589 allocs, 2,589 frees, 333,480 bytes allocated
==112== 
==112== All heap blocks were freed -- no leaks are possible
==112== 
==112== For counts of detected and suppressed errors, rerun with: -v
==112== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - A basic StickerSheet works

- **Points**: 5 / 5





### ✓ - [1/1] - StickerSheet::changeMaxStickers() does not discard stickers when resized larger

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::changeMaxStickers() does not discard original stickers when resized smaller

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::changeMaxStickers() can increase the number of stickers on an image

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::changeMaxStickers() discards stickers beyond the end of a smaller StickerSheet

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::removeSticker() can remove the last sticker

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::removeSticker() can remove the first sticker

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::removeSticker() can remove all stickers

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::getSticker() returns the sticker

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::getSticker() returns NULL for a non-existant sticker

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::getSticker() returns NULL for a removed sticker

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::translate() translates a sticker's location

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::translate() returns false for a non-existant sticker

- **Points**: 1 / 1





### ✓ - [5/5] - A complex StickerSheet is correct

- **Points**: 5 / 5





### ✓ - [2/2] - StickerSheet's copy constructor makes an independent copy

- **Points**: 2 / 2





### ✓ - [2/2] - StickerSheet's assignment operator makes an independent copy

- **Points**: 2 / 2





### ✗ - [0/3] - StickerSheet doesn't have any memory errors

- **Points**: 0 / 3

```
==130== Memcheck, a memory error detector
==130== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==130== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==130== Command: ./test -r xml "StickerSheet\ doesn't\ have\ any\ memory\ errors"
==130== 
==130== 
==130== HEAP SUMMARY:
==130==     in use at exit: 120,960,211 bytes in 19 blocks
==130==   total heap usage: 3,452 allocs, 3,433 frees, 288,735,932 bytes allocated
==130== 
==130== 1 bytes in 1 blocks are definitely lost in loss record 1 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x409950: cs225::StickerSheet::changeMaxStickers(unsigned int) (StickerSheet.cpp:69)
==130==    by 0x432CF4: stickersheetStressTest(cs225::StickerSheet&) (tests-part2.cpp:276)
==130==    by 0x432F96: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:295)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130== 
==130== 1 bytes in 1 blocks are definitely lost in loss record 2 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x409950: cs225::StickerSheet::changeMaxStickers(unsigned int) (StickerSheet.cpp:69)
==130==    by 0x432CF4: stickersheetStressTest(cs225::StickerSheet&) (tests-part2.cpp:276)
==130==    by 0x432FD7: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:299)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130== 
==130== 1 bytes in 1 blocks are definitely lost in loss record 3 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x409950: cs225::StickerSheet::changeMaxStickers(unsigned int) (StickerSheet.cpp:69)
==130==    by 0x432CF4: stickersheetStressTest(cs225::StickerSheet&) (tests-part2.cpp:276)
==130==    by 0x432FE8: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:300)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130== 
==130== 16 bytes in 1 blocks are definitely lost in loss record 4 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x4092D8: cs225::StickerSheet::StickerSheet(Image const&, unsigned int) (StickerSheet.cpp:9)
==130==    by 0x432F01: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:284)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130==    by 0x45DBFA: Catch::Session::run() (catch.hpp:10106)
==130== 
==130== 16 bytes in 1 blocks are definitely lost in loss record 5 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x409313: cs225::StickerSheet::StickerSheet(Image const&, unsigned int) (StickerSheet.cpp:10)
==130==    by 0x432F01: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:284)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130==    by 0x45DBFA: Catch::Session::run() (catch.hpp:10106)
==130== 
==130== 16 bytes in 1 blocks are definitely lost in loss record 6 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x4092D8: cs225::StickerSheet::StickerSheet(Image const&, unsigned int) (StickerSheet.cpp:9)
==130==    by 0x432F66: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:291)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130==    by 0x45DBFA: Catch::Session::run() (catch.hpp:10106)
==130== 
==130== 16 bytes in 1 blocks are definitely lost in loss record 7 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x409313: cs225::StickerSheet::StickerSheet(Image const&, unsigned int) (StickerSheet.cpp:10)
==130==    by 0x432F66: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:291)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130==    by 0x45DBFA: Catch::Session::run() (catch.hpp:10106)
==130== 
==130== 16 bytes in 1 blocks are definitely lost in loss record 8 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x409480: cs225::StickerSheet::copy(cs225::StickerSheet const&) (StickerSheet.cpp:32)
==130==    by 0x4096D7: cs225::StickerSheet::operator=(cs225::StickerSheet const&) (StickerSheet.cpp:21)
==130==    by 0x432F7E: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:292)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130== 
==130== 16 bytes in 1 blocks are definitely lost in loss record 9 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x4094BE: cs225::StickerSheet::copy(cs225::StickerSheet const&) (StickerSheet.cpp:33)
==130==    by 0x4096D7: cs225::StickerSheet::operator=(cs225::StickerSheet const&) (StickerSheet.cpp:21)
==130==    by 0x432F7E: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:292)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130== 
==130== 80 bytes in 1 blocks are definitely lost in loss record 10 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x40936D: cs225::StickerSheet::StickerSheet(Image const&, unsigned int) (StickerSheet.cpp:11)
==130==    by 0x432F66: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:291)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130==    by 0x45DBFA: Catch::Session::run() (catch.hpp:10106)
==130== 
==130== 17,280,000 bytes in 1 blocks are possibly lost in loss record 11 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x40B3C9: cs225::PNG::_copy(cs225::PNG const&) (PNG.cpp:35)
==130==    by 0x40B62F: cs225::PNG::PNG(cs225::PNG const&) (PNG.cpp:55)
==130==    by 0x409FC7: Image::Image(Image const&) (Image.h:10)
==130==    by 0x4092F6: cs225::StickerSheet::StickerSheet(Image const&, unsigned int) (StickerSheet.cpp:9)
==130==    by 0x432F01: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:284)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130== 
==130== 17,280,000 bytes in 1 blocks are possibly lost in loss record 12 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x40B3C9: cs225::PNG::_copy(cs225::PNG const&) (PNG.cpp:35)
==130==    by 0x40B62F: cs225::PNG::PNG(cs225::PNG const&) (PNG.cpp:55)
==130==    by 0x409FC7: Image::Image(Image const&) (Image.h:10)
==130==    by 0x4092F6: cs225::StickerSheet::StickerSheet(Image const&, unsigned int) (StickerSheet.cpp:9)
==130==    by 0x432F66: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:291)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130== 
==130== 17,280,000 bytes in 1 blocks are possibly lost in loss record 13 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x40B3C9: cs225::PNG::_copy(cs225::PNG const&) (PNG.cpp:35)
==130==    by 0x40B62F: cs225::PNG::PNG(cs225::PNG const&) (PNG.cpp:55)
==130==    by 0x409FC7: Image::Image(Image const&) (Image.h:10)
==130==    by 0x4094A1: cs225::StickerSheet::copy(cs225::StickerSheet const&) (StickerSheet.cpp:32)
==130==    by 0x4096D7: cs225::StickerSheet::operator=(cs225::StickerSheet const&) (StickerSheet.cpp:21)
==130==    by 0x432F7E: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:292)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130== 
==130== 17,280,000 bytes in 1 blocks are possibly lost in loss record 14 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x40CA7D: cs225::PNG::resize(unsigned int, unsigned int) (PNG.cpp:191)
==130==    by 0x409D6C: cs225::StickerSheet::render() const (StickerSheet.cpp:117)
==130==    by 0x432CDB: stickersheetStressTest(cs225::StickerSheet&) (tests-part2.cpp:273)
==130==    by 0x432F96: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:295)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130== 
==130== 17,280,000 bytes in 1 blocks are possibly lost in loss record 15 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x40CA7D: cs225::PNG::resize(unsigned int, unsigned int) (PNG.cpp:191)
==130==    by 0x409D6C: cs225::StickerSheet::render() const (StickerSheet.cpp:117)
==130==    by 0x432CDB: stickersheetStressTest(cs225::StickerSheet&) (tests-part2.cpp:273)
==130==    by 0x432FE8: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:300)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130== 
==130== 17,280,016 (16 direct, 17,280,000 indirect) bytes in 1 blocks are definitely lost in loss record 18 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x409480: cs225::StickerSheet::copy(cs225::StickerSheet const&) (StickerSheet.cpp:32)
==130==    by 0x40941C: cs225::StickerSheet::StickerSheet(cs225::StickerSheet const&) (StickerSheet.cpp:15)
==130==    by 0x432F4C: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:288)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130== 
==130== 17,280,016 (16 direct, 17,280,000 indirect) bytes in 1 blocks are definitely lost in loss record 19 of 19
==130==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==130==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==130==    by 0x4094BE: cs225::StickerSheet::copy(cs225::StickerSheet const&) (StickerSheet.cpp:33)
==130==    by 0x40941C: cs225::StickerSheet::StickerSheet(cs225::StickerSheet const&) (StickerSheet.cpp:15)
==130==    by 0x432F4C: ____C_A_T_C_H____T_E_S_T____32() (tests-part2.cpp:288)
==130==    by 0x46AD42: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==130==    by 0x45B496: Catch::TestCase::invoke() const (catch.hpp:10793)
==130==    by 0x45B3CC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==130==    by 0x457926: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==130==    by 0x455EFE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==130==    by 0x45F296: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==130==    by 0x45DF32: Catch::Session::runInternal() (catch.hpp:10149)
==130== 
==130== LEAK SUMMARY:
==130==    definitely lost: 211 bytes in 12 blocks
==130==    indirectly lost: 34,560,000 bytes in 2 blocks
==130==      possibly lost: 86,400,000 bytes in 5 blocks
==130==    still reachable: 0 bytes in 0 blocks
==130==         suppressed: 0 bytes in 0 blocks
==130== 
==130== For counts of detected and suppressed errors, rerun with: -v
==130== ERROR SUMMARY: 17 errors from 17 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - myImage.png exists and contains stickers

- **Points**: 10 / 10





---