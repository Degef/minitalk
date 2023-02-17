LIB = ./libft/libft.a 
LIBFT = cd libft && make

SERVER_SRC = src/server.c
CLIENT_SRC = src/client.c
SERVER_BONUS_SRC = src/server_bonus.c
CLIENT_BONUS_SRC = src/client_bonus.c 
SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRC:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRC:.c=.o)
OBJS = $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

GCC = gcc
FLAGS = -Wall -Wextra -Werror

 
all: ft_server ft_client

bonus: ft_server_bonus ft_client_bonus

ft_server: $(SERVER_OBJS)
		$(LIBFT)
		@$(GCC) $(FLAGS) $(SERVER_OBJS) $(LIB) -o server

ft_client: $(CLIENT_OBJS)
		$(LIBFT)
		@$(GCC) $(FLAGS) $(CLIENT_OBJS) $(LIB) -o client

ft_server_bonus: $(SERVER_BONUS_OBJS)
		$(LIBFT)
		@$(GCC) $(FLAGS) $(SERVER_BONUS_OBJS) $(LIB) -o server_bonus

ft_client_bonus: $(CLIENT_BONUS_OBJS)
		$(LIBFT)
		@$(GCC) $(FLAGS) $(CLIENT_BONUS_OBJS) $(LIB) -o client_bonus

%.o: %.c
	$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean

fclean: clean
	@rm -rf server client server_bonus client_bonus
	@cd libft && make fclean

re:	fclean all