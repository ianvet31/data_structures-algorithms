---

This report was generated for **ivette2** using **c1b84961347011218ce59c7bfdb08a53712f8dfa** (latest commit as of **October 3rd 2021, 11:59 pm**)

---




## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
In file included from tests/tests.cpp:3:
In file included from tests/../util.h:3:
In file included from tests/../TreeTraversals/../binarytree.h:217:
tests/../binarytree.cpp:158:24: fatal error: too many arguments to function call, expected 0, have 2
    isOrderedRecursive(subRoot->left, vec);
    ~~~~~~~~~~~~~~~~~~ ^~~~~~~~~~~~~~~~~~
tests/../binarytree.cpp:138:5: note: in instantiation of member function 'BinaryTree<int>::isOrderedRecursiveHelp' requested here
    isOrderedRecursiveHelp(root, vec);
    ^
tests/tests.cpp:122:22: note: in instantiation of member function 'BinaryTree<int>::isOrderedRecursive' requested here
    REQUIRE(treeLeft.isOrderedRecursive() == false);
                     ^
tests/../binarytree.cpp:133:1: note: 'isOrderedRecursive' declared here
bool BinaryTree<T>::isOrderedRecursive() const
^
1 error generated.
make: *** [.objs/tests/tests.o] Error 1

```
```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c coloredout.cpp -o .objs/coloredout.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests.cpp -o .objs/tests/tests.o

```


---