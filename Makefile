##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile with makefile constructor
##

LIB_FOLDER	=	lib/

SRC	=	$(LIB_FOLDER)libbar.c	\
		$(LIB_FOLDER)libfoo.c	\
		$(LIB_FOLDER)libgra.c	\

CC	= g++ -std=c++20

RM	= rm -f

CFLAGS = -fPIC -Wall -Wextra -Werror

LDFLAGS	=	-shared

OBJ	=	$(SRC:.c=.so)

%.so: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

all: $(MAKE)

$(MAKE): $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) $(LIB_FOLDER)*.so

re: 	fclean all
