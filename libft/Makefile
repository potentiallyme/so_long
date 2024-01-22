# **************************************************************************** #
# 								NAME PROJECT								   #
# **************************************************************************** #
NAME	=	libft.a

# **************************************************************************** #
# 								  COMMANDS									   #
# **************************************************************************** #
CC		=	@clang
CFLAGS	=	-Wall -Wextra -Werror
IFLAGS	=	-Iinc
MK		=	@mkdir -p
RM		=	@rm -rf
FILE	=	$(shell ls -lR src/ | grep -F .c | wc -l)
CMP		=	1
CLEAR	=	@clear

# **************************************************************************** #
# 								   COLORS									   #
# **************************************************************************** #

BOLD	= 	\e[1m
FAINT	=	\e[2m
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
GREY	=	\e[38;5;254m
RESET	=	\e[00m

# **************************************************************************** #
# 								   PRINTS									   #
# **************************************************************************** #

RNBW	=	@printf "\r$(RED). $(ORANGE). $(YELLOW). $(GREEN). $(LBLUE). $(BLUE). $(INDI). $(PURPLE). $(RED). $(ORANGE). $(YELLOW). $(GREEN).                       \n\r$(ITA)$(RED)li$(ORANGE)bf$(YELLOW)t i$(GREEN)s re$(LBLUE)ad$(BLUE)y to$(INDI) us$(PURPLE)e..$(FADE)$(GREY)\n\n"
# **************************************************************************** #
# 								   SOURCES									   #
# **************************************************************************** #

# CHECK
CHECK_DIR	:=	check
SRC_CHECK	:=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isvals.c \
				ft_iterate_double.c
CHECK		:=	$(SRC_CHECK:%=$(CHECK_DIR)/%)

#LIST
LIST_DIR	:=	list
SRC_LIST	:=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
				ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
LIST		:=	$(SRC_LIST:%=$(LIST_DIR)/%)

# MEMORY
MEM_DIR		:=	memory
SRC_MEM		:=	ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
MEM			:=	$(SRC_MEM:%=$(MEM_DIR)/%)

# PRINT
PRINT_DIR	:=	print
SRC_PRINT	:=	ft_printf.c ft_printf_num.c ft_printf_hex.c
PRINT		:=	$(SRC_PRINT:%=$(PRINT_DIR)/%)

# PUT
PUT_DIR		:= 	put
SRC_PUT		:= 	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putstr.c \
				ft_putstr_double.c
PUT			:=	$(SRC_PUT:%=$(PUT_DIR)/%)

# STRING
STRING_DIR	:=	string
SRC_STRING	:=	ft_atoi.c ft_itoa.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lines_double.c \
				ft_strlen_double.c ft_strlen_comp.c
STRING		:=	$(SRC_STRING:%=$(STRING_DIR)/%)

# GNL	
GNL_DIR		:= 	gnl
SRC_GNL		:= 	get_next_line.c get_next_line_utils.c
GNL			:= 	$(SRC_GNL:%=$(GNL_DIR)/%)

#ALL SOURCES
SRCS_DIR	:=	src
ALL_SRCS	:=	$(CHECK) $(GNL) $(LIST) $(MEM) $(PRINT) $(PUT) $(STRING) 
SRCS		:=	$(ALL_SRCS:%=$(SRCS_DIR)/%)

# OBJECTS
OBJS_DIR	:=	.objs
OBJS		:=	$(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

# **************************************************************************** #
# 								     RULES									   #
# **************************************************************************** #

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	$(MK) $(@D)
	@printf "\r$(FAINT)$(SPINK)Compiling $(RESET)$(GREEN)$<$(BLUE) [$(SPINK)$(CMP)$(BLUE)/$(SPINK)$(FILE)$(BLUE)]$(RESET)                       \r"
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o  $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	$(RNBW)	

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# **************************************************************************** #
# 								 EXTRA RULES								   #
# **************************************************************************** #

run: re
	-./$(NAME)

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

print-%:
	$(info '$*'='$($*)')

update:
	git stash
	git pull
	git submodule update --init
	git stash pop

.PHONY: all clean fclean re run update