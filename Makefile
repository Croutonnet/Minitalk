CC = gcc -Wall -Werror -Wextra
CLIENT = client
SERV = server

SFILE = server.c
OBSERV = $(SFILE:.c=.o)
CFILE = client.c
OBCLIENT = $(CFILE:.c=.o)

LIBFT = libft.a
LIBDIR = Libft/


all: libft clex servex

clex:	$(OBCLIENT)
		@echo Compiling client...
		@$(CC) $(OBCLIENT) $(LIBDIR)$(LIBFT) -o $(CLIENT)

servex: $(OBSERV)
		@echo Compiling server...
		@$(CC) $(OBSERV) $(LIBDIR)$(LIBFT) -o $(SERV)

clean :
		@echo Cleaning...
		@rm -f $(LIBDIR)*.o *.o

fclean:	clean
		@rm -f $(SERV) $(CLIENT)
		@rm -f $(LIBDIR)$(LIBFT)

libft:
		@$(MAKE) -C $(LIBDIR)

re:	fclean all

.PHONY: all libft