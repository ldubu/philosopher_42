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
INCLUDE = 	includes/ \
			libft/includes/
LIBFT	= 	libft/libft.a
CFLAGS	= 	-Wall -Werror -Wextra -D_REENTRANT -DWin32
HEADER	= 	includes/philo.h
RM		=	rm -rf
SRCS	= 	sources/main.c \
			sources/parsing.c \
			sources/create_philo.c

OBJS_PATH = objs/
OBJS	= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADER)
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $@ -lpthread
	@printf "\n${_GREEN}${_BOLD}[Philo OK]${_END}\n"

$(OBJS_PATH)%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"	

$(LIBFT):
	$(MAKE) --no-print-directory -C ./libft

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS) 

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re:	fclean all