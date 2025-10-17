PROJECT		= ft_printf
NAME		= libftprintf.a
INCLUDE		= -I inc -I bonus_inc -I libft
LIBFT		= libft
SRC_DIR		= src/
BNS_SRC_DIR	= bonus_src/
OBJ_DIR		= obj/
BNS_OBJ_DIR = bonus_obj/
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

# Colors

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
CYAN		= \033[0;36m
PURPLE		= \033[0;35m

#Sources

SRC_FILES		=	ft_printf print_nb print_txt
BNS_SRC_FILES	=	ft_printf_bonus print_format_bonus print_str_bonus utils_bonus \
					print_nb_bonus print_char_bonus print_uns_bonus print_ptr_bonus \
					utils2_bonus print_hex_bonus


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BNS_SRC		=	$(addprefix $(BNS_SRC_DIR), $(addsuffix .c, $(BNS_SRC_FILES)))
BNS_OBJ		= 	$(addprefix $(BNS_OBJ_DIR), $(addsuffix .o, $(BNS_SRC_FILES)))

###

OBJF		=	.cache_exists
BNS_OBJF	=	.bonus_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -s -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)$(PROJECT) done!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< "
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

bonus:		$(BNS_OBJ)
			@make -s -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(BNS_OBJ)
			@echo "$(PURPLE)$(PROJECT) bonus done!"

$(BNS_OBJ_DIR)%.o: $(BNS_SRC_DIR)%.c | $(BNS_OBJF)
			@echo "$(YELLOW)Compiling: $< "
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BNS_OBJF):
			@mkdir -p $(BNS_OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR) $(BNS_OBJ_DIR)
			@make clean -s -C $(LIBFT)
			@echo "$(BLUE)$(PROJECT) obj files removed"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)$(PROJECT) exec files removed"
			@echo "$(CYAN)$(LIBFT) exec files removed"

re:			fclean all
			@echo "$(GREEN)$(PROJECT) remade!"

rebonus:	fclean bonus
			@echo "$(PURPLE)$(PROJECT) bonuses remade"

.PHONY:		all clean fclean re norm