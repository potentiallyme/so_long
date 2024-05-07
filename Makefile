# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 03:44:44 by lmoran            #+#    #+#              #
#    Updated: 2024/03/06 19:10:27 by lmoran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#...............................................#

NAME	= so_long
CC		= @clang -g3
CFLAGS	= -Wall -Werror -Wextra
RM		= @rm -f
CLEAR	= @clear
FILE	= $(shell ls -l src/ | grep -F .c | wc -l)
HEAD	= ./include/so_long.h
CMP		= 1

#...............................................#

SRC	= 	./src/main.c\
		./src/parse_core.c\
		./src/parse_utils.c\
		./src/solve_utils.c\
		./src/struct_utils.c\
		./src/frees.c\
		./src/frees_2.c\
		./src/errors.c\
		./src/make_game.c\
		./src/game_utils.c\
		./src/game_utils_2.c\
		./src/game_utils_3.c\
		./src/move_ments.c\
		./src/update_game.c\
		./src/make_trail.c\
		./src/recursive_checker.c\
		./src/game_ends.c\
		./src/asset_inits.c\
		./src/welcome_in.c\
		./src/static_anims.c\
		./src/print_moves.c
		

OBJ	= $(SRC:.c=.o)

#...............................................#

PRINT_PATH	= ./libft --no-print-directory
PRINT_NAME	= ./libft/libft.a

#...............................................#

MLX = minilibx-linux/libmlx_Linux.a
MLX_A = ./minilibx-linux/libmlx.a
MLX_PATH = minilibx-linux

#...............................................#

BOLD	= 	\e[1m
FADE	=	\e[2m
ITA		=	\e[3m
BLINK	=	\e[5m
GREEN	=	\e[38;5;76m
RED		=	\e[38;5;196m
YELLOW	=	\e[38;5;227m
ORANGE	=	\e[38;5;208m
PURPLE	=	\e[38;5;201m
LBLUE	=	\e[38;5;45m
BLUE	=	\e[38;5;27m
INDI	=	\e[38;5;91m
SPINK	=	\e[38;5;225m
PEACH	=	\e[38;5;223m
GREY	=	\e[38;5;254m
RESET	=	\e[00m

#...............................................#

RNBW	= @printf "                                                          \r$(ITA)$(GREEN)..s$(LBLUE)o_$(BLUE)lo$(INDI)ng i$(PURPLE)s re$(RED)ad$(ORANGE)y to$(YELLOW)o!\n\r$(GREEN). $(LBLUE). $(BLUE). $(INDI). $(PURPLE). $(RED). $(ORANGE). $(YELLOW). $(GREEN). $(LBLUE). $(BLUE). $(INDI).                      \n\n"

all: $(MLX) $(PRINT_NAME) $(NAME)

bonus : $(MLX) $(PRINT_NAME) $(NAME)

%.o: %.c $(HEAD)
	@printf "\r$(FADE)$(SPINK)Compiling $(RESET)$(GREEN)$<$(BLUE) [$(SPINK)$(CMP)$(BLUE)/$(SPINK)$(FILE)$(BLUE)]$(RESET)                       \r"
	$(CC) $(CFLAGS) -c $< -o $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(PRINT_NAME) -lXext -lX11 -lm -lz -o $(NAME) $(MLX)
	$(RNBW)

$(PRINT_NAME):
	@make -C $(PRINT_PATH)

$(MLX): minilibx-linux
	@printf "$(LBLUE)$(FADE)CLONING AND COMPILING MLX\n$(RESET)\n"
	@cd minilibx-linux && make
	@printf "\n$(LBLUE)$(FADE)$(BOLD)MINILIBX CLONED AND COMPILED\n\n$(RESET)"
	
minilibx-linux:
	@git clone https://github.com/42Paris/minilibx-linux.git $@ 

clean:
	@rm -f $(PRINT_NAME)
	@printf "\r\n\r$(BOLD)$(GREEN)ALL CLEAN!     \n\n$(RESET)"
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(PRINT_PATH)
	@rm -rf $(NAME) $(MLX) $(MLX_A)
	@printf "\b\b$(FADE)$(RED)(MLX REMOVED!)$(PEACH)\n\n"
	$(RM) $(NAME)

lib: $(PRINT_NAME)

re: fclean all

.PHONY: 
	all clean fclean re