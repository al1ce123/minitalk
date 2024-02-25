CC = gcc
CFLAGS = -Wall -Wextra -g

NAME = minitalk
SRCDIR = src/
SRC = server.c client.c
SRCS = $(addprefix $(SRCDIR),$(SRC))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

server: $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(SRCDIR)server.o -o server -L./libft -lft

client: $(OBJS)
	$(CC) $(CFLAGS) $(SRCDIR)client.o -o client -L./libft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): server client

clean:
	rm -rf $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf server client
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all re clean fclean



