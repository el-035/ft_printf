CC = cc

CFILES = ft_printf.c ft_printstuff.c ft_printmore.c


#creates object files from the c files given
OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

# this sets the rule to compile all c files into o files $< is the prerequisite (aka the c files) and $@ is the target (aka the o files)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# all compiles all the c files into o files and archive them into libft.a
all: $(NAME)

#flags rcs: r adds o files to archive, c creates the archive if it doesnt exist yet, s for the index
$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

#gets rid of all o files after creating application
clean:
	rm -f $(OFILES)

#removes o files and library
fclean: clean
	rm -f $(NAME)

#to rebuild the whole project after cleaning everything
re: fclean all
