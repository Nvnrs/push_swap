SRC_DIR = ./src
SRC= $(SRC_DIR)/main.c \


OBJ = $(SRC:.c=.o)
# CFLAGS += -Wall -Wextra -Werror
NAME = push_swap

LIB_DIR = ./lib
MYLIB42_DIR = $(LIB_DIR)/MYLIB42
MYLIB42 = $(MYLIB42_DIR)/mylib42.a

all : $(NAME)

$(NAME) : $(OBJ) $(MYLIB42)
	gcc $(CFLAGS) $(MYLIB42) $(OBJ) -o $(NAME)

$(MYLIB42) :
	git clone https://github.com/Nvnrs/MYLIB42.git $(MYLIB42_DIR)
	$(MAKE) -C $(MYLIB42_DIR)

clean :
	rm -rf $(OBJ)
	$(MAKE) clean -C $(MYLIB42_DIR)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(MYLIB42_DIR)

re : fclean all

PHONY : clean fclean re all