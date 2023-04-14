CC = gcc -Wall -Werror -Wextra
CLIENT = client
SERV = server

SFILE = server.c
OBSERV = $(SFILE:.c=.o)
CFILE = client.c
OBCLIENT = $(CFILE:.c=.o)

SRCS =	ft_atoi.c\
		ft_bzero.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_strlen.c\
		ft_xfree.c\
		ft_calloc.c

OSRCS = $(SRCS:.c=.o)

all: clex servex

clex: $(OBCLIENT) $(OSRCS) $(CLIENT)

$(CLIENT): $(OSRCS)
		$(CC) $(CFILE) $(SRCS) -o $(CLIENT)

servex: $(OBSERV) $(OSRCS) $(SERV)

$(SERV): $(OSRCS)
		$(CC) $(SFILE) $(SRCS) -o $(SERV)

clean :
		@echo Cleaning...
		@rm -f $(LIBDIR)*.o *.o

fclean:	clean
		@rm -f $(SERV) $(CLIENT)

re:	fclean all

.PHONY: all libft