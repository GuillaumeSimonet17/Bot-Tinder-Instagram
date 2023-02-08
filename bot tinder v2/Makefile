NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

NAME =	read

PATH_OBJ = ./.objs/

SRC =   read.c \
		gnl.c \
		split.c \

LIST_OBJS = $(patsubst %.c, %.o, $(SRC))
OBJ = $(addprefix $(PATH_OBJ), $(LIST_OBJS))

FLAGS = -Wall -Wextra -Werror
HEADER = read.h

all: $(NAME)

$(PATH_OBJ):
	@mkdir -p $(PATH_OBJ)

$(PATH_OBJ)%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	$(CC) $(FLAGS) -I $(HEADER) -c -I. $< -o $@ 

$(NAME): $(PATH_OBJ) $(OBJ)
	@cc $(FLAGS) $(OBJ) -o $(NAME) 
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@echo $(GREEN)"- Compiled -"$(NONE)

clean:
	@echo $(CURSIVE) $(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(PATH_OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf  $(PATH_OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re