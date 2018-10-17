NAME := vkorniie.visual

LIB_DIR := ../libft/
SRC_DIR := 
OBJ_DIR := ./objects/
INC_DIR := ../

SRCS := main.c visual_second.c
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC := gcc
FLAGS :=  -g -Wall -Wextra -Werror

LIBFT = $(LIB_DIR)libft.a
LIBFT_FLAGS := -L $(LIB_DIR) -lft
LIBFT_INC := $(LIB_DIR)includes

HDR_FLAGS := -I $(LIBFT_INC) -I $(INC_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ $(CC) $(OBJ) $(FLAGS) $(HDR_FLAGS) -o $(NAME) $(LIBFT) -lmlx -framework OpenGL -framework AppKit

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@ mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) -c $< -o $@ $(FLAGS) $(HDR_FLAGS)

$(LIBFT):
	@ make -C $(LIB_DIR)

clean:
	@ make clean -C $(LIB_DIR)
	@ rm -f $(OBJ)
	

fclean:
	@ make fclean -C $(LIB_DIR)
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_DIR)

re: fclean all
