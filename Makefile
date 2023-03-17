##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile with makefile constructor
##

EXEC_NAME	=	bootstrap

LIB_FOLDER	=	lib/

SRC	=	src/main.cpp	\
		src/DisplayModule.cpp	\

LIB	=	$(LIB_FOLDER)libbar.c	\
		$(LIB_FOLDER)libfoo.c	\
		$(LIB_FOLDER)libgra.c	\

CC	= g++ -std=c++20

RM	= rm -f

CFLAGS = -fPIC -Wall -Wextra -Werror

LDFLAGS	=	-shared

OBJ	=	$(LIB:.c=.so)

LIBDLFLAG	=	-ldl

CPPFLAGS	=	-I./lib

%.so: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

all: $(MAKE)

$(MAKE): $(OBJ)
	$(CC) -o $(EXEC_NAME) $(SRC) $(LIBDLFLAG) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) $(LIB_FOLDER)*.so

re: 	fclean all
