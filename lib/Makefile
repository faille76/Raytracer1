##
## Makefile for Make in /
##
## Made by Frederic ODDOU
## Login oddou_f <frederic.oddou@epitech.eu>
##
## Started on  Wed Nov 18 22:13:28 2015 Frederic ODDOU
## Last update Thu Dec 31 12:04:23 2015 oddou_f
##

NAME=	libmy.a

LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm

FLAG		=	-W -Wall -ansi -pedantic -I/home/${USER}/.froot/include/ -I./../include/

SRC=	tekpixel.c \
	tekline.c \
	tekcercle.c \
	tekcarre.c \
	tekcoords.c \
	tekpolice.c \
	setcolor.c \
	getpixel.c \
	load_bmp.c \
	my_putchar.c \
	my_putstr.c \
	my_putnbr.c \
	my_strlen.c \
	my_getnbr.c \
	my_strdup.c \
	my_atoi.c \
	my_strcmp.c

ECHO		=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED			=	"\033[0;31m"

OBJ=	$(SRC:.c=.o)

EXEC	= execfile

all:	$(EXEC) $(NAME)

$(EXEC):
	@$(ECHO) $(GREEN)"-> Compilation de la librairie $(NAME) :"$(DEFAULT)

$(NAME):$(OBJ)
	@ar rc $(NAME) $(OBJ) && \
	 $(ECHO) $(GREEN) "[AR]" $(TEAL) $(NAME) $(DEFAULT) || \
	 $(ECHO) $(RED) "[XX]" $(TEAL) $(NAME)
	@ranlib $(NAME) && \
	 $(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) || \
	 $(ECHO) $(RED) "[XX]" $(TEAL) $(NAME)

clean:
	@rm -f $(OBJ)
	@$(ECHO) $(GREEN)"-> Clean $(NAME) effectué."$(DEFAULT)

fclean:	clean
	@rm -f $(NAME)
	@$(ECHO) $(GREEN)"-> La librairie $(NAME) a été supprimée avec succès."$(DEFAULT)

re:	fclean all

.c.o:
	@gcc $(LIB) $(FLAG) -c $< -o $@ && \
	 $(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
	 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)
