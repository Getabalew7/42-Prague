#!/bin/bash

#remove the library if it exist
rm -f libft.a

#compile the fille
find . -name "*.c" -type f -exec gcc -Wall -Wextra -Werror -c {} \;

#create a library
ar rc libft.a *.o

#create an index to locate the content of the library
ranlib libft.a

#remove the object files
rm -f *.o
