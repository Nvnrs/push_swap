SRC_DIR = ./src
SRC= $(SRC_DIR)/main.c \
	$(SRC_DIR)/parsing/checks.c \
	$(SRC_DIR)/parsing/parse.c \
	$(SRC_DIR)/parsing/tab_strs_to_int.c \
	$(SRC_DIR)/stack/stack_init.c \
	$(SRC_DIR)/stack/stacks_init.c \
	$(SRC_DIR)/stack/stack_functions.c \
	$(SRC_DIR)/stack/stack_utils.c \
	$(SRC_DIR)/sort/sort.c \
	$(SRC_DIR)/sort/costs_a.c \
	$(SRC_DIR)/sort/costs_b.c \
	$(SRC_DIR)/sort/total_costs.c \
	$(SRC_DIR)/sort/costs_init.c \
	$(SRC_DIR)/operations/swap.c \
	$(SRC_DIR)/operations/push.c \
	$(SRC_DIR)/operations/rotate.c \
	$(SRC_DIR)/operations/reverse_rotate.c \
	$(SRC_DIR)/operations/operations_utils.c \

OBJ = $(SRC:.c=.o)
# CFLAGS += -Wall -Wextra -Werror
NAME = push_swap

LIB_DIR = ./lib
MYLIB42_DIR = $(LIB_DIR)/MYLIB42
MYLIB42 = $(MYLIB42_DIR)/mylib42.a

all : $(NAME)

$(NAME) :  $(MYLIB42) $(OBJ)
	gcc -g $(CFLAGS) $(OBJ) $(MYLIB42) -o $(NAME)

$(MYLIB42_DIR) :
	git clone https://github.com/Nvnrs/MYLIB42.git $(MYLIB42_DIR)

$(MYLIB42) : $(MYLIB42_DIR)
	$(MAKE) -C $(MYLIB42_DIR)

clean :
	rm -rf $(OBJ)
	$(MAKE) clean -C $(MYLIB42_DIR)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIB_DIR)

re : fclean all

PHONY : clean fclean re all