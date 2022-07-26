_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m
_END= 	$'\033[37m

CC		= 	cc
NAME	= 	philo
INCLUDE = 	includes/
LIBFT	= 	libft/libft.a
CFLAGS	= 	-Wall -Werror -Wextra -D_REENTRANT -DWin32
HEADER	= 	includes/philo.h
BONUS_H	= 	includes/philo_bonus.h
RM		=	rm -rf
SRCS	= 	sources/main.c \
			sources/parsing.c \
			sources/create_philo.c \
			sources/utils.c \
			sources/error.c \
			sources/eat.c
BONUS	=	sources_bonus/main.c \
			sources_bonus/parsing.c \
			sources_bonus/create_philo.c \
			sources_bonus/error.c \
			sources_bonus/utils.c \
			sources_bonus/eat.c

OBJS_PATH = objs/
OBJS	= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
B_OBJS	= $(addprefix $(OBJS_PATH), $(BONUS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADER)
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $@ -lpthread
	@printf "\n${_GREEN}${_BOLD}[Philo OK]${_END}\n"

$(OBJS_PATH)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"	

$(LIBFT):
	$(MAKE) --no-print-directory -C ./libft

bonus : $(LIBFT) $(B_OBJS) $(BONUS_H)
	@printf "%-15s ${_PURPLE}${_BOLD}philo bonus${_END}...\n" "Compiling"
	@$(CC) $(B_OBJS) $(LIBFT) $(CFLAGS) -o philo_bonus -lpthread
	@printf "\n${_GREEN}${_BOLD}[Philo bonus OK]${_END}\n"

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS) 
	$(RM) $(OBJS_PATH)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re:	fclean all