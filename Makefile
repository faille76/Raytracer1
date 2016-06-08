##
## Makefile for Makefile in /
##
## Made by Frederic ODDOU
## Login oddou_f <frederic.oddou@epitech.eu>
##
## Started on  Sun Oct 25 20:17:12 2015 Frederic ODDOU
## Last update Sun Jan 31 19:53:35 2016 oddou_f
##

ECHO		=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED			=	"\033[0;31m"

DIR	= ./src/
D_KEYS = ./src/keys/
D_GET = ./src/get_from_ini/
D_RT = ./src/rt/
D_CALC_OBJ = $(D_RT)calc_objs/
D_NORM_OBJ = $(D_RT)normal/
D_S_LIB = ./src/lib/
D_LIB	= ./lib/
D_INC	= ./include/

LIB		=	-L/home/${USER}/.froot/lib/ \
	-llapin \
	-L/usr/local/lib \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ -ldl \
	-lm \
	-lpthread \
	-lmy \
	-O3

FLAG		=	-W -Wall -ansi -pedantic \
		-I/home/${USER}/.froot/include/ \
		-I$(D_INC) \
		-L$(D_LIB) \
		-O3

SRC	= $(DIR)main.c \
	$(DIR)key_commands.c \
	$(DIR)mouse_commands.c \
	$(DIR)multi_thread.c \
	$(DIR)rt_free.c \
	$(D_GET)get_all.c \
	$(D_GET)get_view.c \
	$(D_GET)get_light.c \
	$(D_GET)get_plan.c \
	$(D_GET)get_cone.c \
	$(D_GET)get_sphere.c \
	$(D_GET)get_parabol.c \
	$(D_GET)get_cylindre.c \
	$(D_GET)get_obj_ini.c \
	$(D_RT)rt_exec.c \
	$(D_RT)rt_kmin.c \
	$(D_RT)rt_translation.c \
	$(D_RT)rt_light.c \
	$(D_RT)rt_normal.c \
	$(D_RT)rt_brillance.c \
	$(D_RT)rt_shadow.c \
	$(D_CALC_OBJ)calc_sphere.c \
	$(D_CALC_OBJ)calc_cone.c \
	$(D_CALC_OBJ)calc_plan.c \
	$(D_CALC_OBJ)calc_cylindre.c \
	$(D_CALC_OBJ)calc_parabol.c \
	$(D_CALC_OBJ)calc_screen.c \
	$(D_NORM_OBJ)normal_sphere.c \
	$(D_NORM_OBJ)normal_cone.c \
	$(D_NORM_OBJ)normal_plan.c \
	$(D_NORM_OBJ)normal_cylindre.c \
	$(D_NORM_OBJ)normal_parabol.c \
	$(D_KEYS)keys_move.c \
	$(D_KEYS)keys_view.c \
	$(D_KEYS)keys_get.c \
	$(D_S_LIB)take_int_from_ini.c \
	$(D_S_LIB)take_color_from_ini.c \
	$(D_S_LIB)take_nb_arg_from_ini.c \
	$(D_S_LIB)take_double_from_ini.c \
	$(D_S_LIB)tekmouse.c \
	$(D_S_LIB)antialiasing.c \
	$(D_S_LIB)cadre_effect.c \
	$(D_S_LIB)cpy_pix.c

OBJ=	$(SRC:.c=.o)

CC	= gcc

RM	= rm -f

NAME	= raytracer1

EXEC	= execfile

all:	$(EXEC) $(NAME)

$(EXEC):
	make -C $(D_LIB) -f Makefile
	@echo "\033[36;1m-> Compilation de $(NAME) :\033[0m"

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) $(FLAG) $(LIB) -o $(NAME)
	@echo "\033[32;1m-> Done"
	@echo "Usage : ./$(NAME)\033[0m"

clean:
	make clean -C $(D_LIB) -f Makefile
	@$(RM) $(OBJ)
	@echo "\033[32;1m-> Clean $(NAME) effectué.\033[0m"

fclean:	clean
	make fclean -C $(D_LIB) -f Makefile
	@$(RM) ./$(NAME)
	@echo "\033[32;1m-> L'executable $(NAME) a été supprimé avec succès.\033[0m"

re: fclean all

.c.o:
	@gcc -c $< -o $@ $(FLAG) && \
	 $(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
	 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

.PHONY: all clean fclean re
