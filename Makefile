CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBMLX = ./minilibx-linux
LIBMLXA = ./minilibx-linux/libmlx.a
NAME = fractol

SRC_PATH = .
OBJ_PATH = .
SRC_LIST =	$(SRC_PATH)/fractol.c \
        	$(SRC_PATH)/init.c \
            $(SRC_PATH)/events.c \
            $(SRC_PATH)/math_utils.c \
            $(SRC_PATH)/render.c \
            $(SRC_PATH)/utils.c
OBJ_LIST = $(SRC_LIST:$(SRC_PATH)/%.c=$(SRC_PATH)/%.o)

INCLUDES = -I$(LIBMLX)

all: $(NAME) 

$(NAME): $(OBJ_LIST) $(LIBMLXA)
	$(CC) $(OBJ_LIST) -o $(NAME) $(LIBMLX)/libmlx.a -lX11 -lXext -lm

$(LIBMLXA) : $(LIBMLX)
	@make -C minilibx-linux > /dev/null 2>&1

$(SRC_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(SRC_PATH)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re