NAME = minitalk.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

PRINTF = printf/libftprintf.a

CLIENT = client
SERVER = server

SRC = client.c server.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(SERVER) $(CLIENT) $(OBJ)

$(SERVER) : $(OBJ)
			make -C ./printf
			$(CC) $(CFLAGS) server.c $(PRINTF) -o server

$(CLIENT) : $(OBJ)
			$(CC) $(CFLAGS) client.c $(PRINTF) -o client

clean:
		make clean -C ./printf
		$(RM) $(OBJ)

fclean: clean
		make fclean -C ./printf
		$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re