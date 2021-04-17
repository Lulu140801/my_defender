
##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC = gcc

RM = rm -f

SRC_DIR = src

SRC_DIR2 = test

SRC = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/init_all.c \
		$(SRC_DIR)/animation.c \
		$(SRC_DIR)/display_game.c \
		$(SRC_DIR)/sort_event.c \
		$(SRC_DIR)/create_tower.c \
		$(SRC_DIR)/manage_sound.c \
		$(SRC_DIR)/update_ui.c \
		$(SRC_DIR)/sup_init.c \
		$(SRC_DIR)/grab_function.c \
		$(SRC_DIR)/reset_pos_tower.c

SRC2 = $(SRC_DIR2)/tests.c

TEST = test/tests.c

TEST_NAME = unit_tests

CFLAGS += -Iinclude -W -Wall -Wextra -Llib/my -lmy -l csfml-graphics -l csfml-system -l csfml-audio -g3

NAME = my_defender

all: create_binary

create_binary:
		@make re -C lib/my
		$(CC) -o $(NAME) $(SRC) $(CFLAGS)

tests_run:
		@make re -C lib/my
		gcc src/convertion_base.c src/palindrome_rec.c $(SRC2) -L lib/my -lmy -lcriterion --coverage
		./a.out
		gcovr

clean:
		@make clean -C lib/my

fclean: clean
		$(RM) $(NAME)
		$(RM) $(TEST_NAME)
		$(RM) *.gc*
		rm -f ./a.out

debug:
		@make -C lib/my
		@gcc -o $(NAME) $(SRC) -g3 -L lib/my/ -lmy
		@echo -e "\033[1;91mDebug mod enabled !\033[0;39m"

re: fclean all

.PHONY: all debug clean fclean re

