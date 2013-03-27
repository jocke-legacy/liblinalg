CC = gcc

NAME = liblinalg

CFLAGS = -Wall -Wextra -Werror -pedantic -std=iso9899:2011 -O2 -D_USE_MATH_DEFINES

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	@echo " [ AR ] $(NAME).a"
	@ar rcs $(NAME).a $(OBJS)
	@echo " Done!"

clean:
	@echo " [ RM ] $(OBJS)"
	@rm -f $(OBJS)
	@echo " [ RM ] $(NAME).a"
	@rm -f $(NAME).a

%.o: %.c
	@echo " [ CC ] $<"
	@$(CC) -c $(CFLAGS) $<
