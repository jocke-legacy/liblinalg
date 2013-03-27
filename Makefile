PREFIX = /usr/local

CC = gcc

NAME = liblinalg

CFLAGS = -I. -Wall -Wextra -Werror -pedantic -O2

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	@echo " [ AR ] $(NAME).a"
	@ar rcs $(NAME).a $(OBJS)

install:
	@echo " [INST] linalg.h"
	@install -m 0755 linalg.h $(PREFIX)/include/linalg.h
	@echo " [INST] liblinalg.a"
	@install -m 0755 liblinalg.a $(PREFIX)/lib/liblinalg.a
	@echo "Done!"

clean:
	@echo " [ RM ] $(OBJS)"
	@rm -f $(OBJS)
	@echo " [ RM ] $(NAME).a"
	@rm -f $(NAME).a

%.o: %.c
	@echo " [ CC ] $<"
	@$(CC) -c $(CFLAGS) $<
