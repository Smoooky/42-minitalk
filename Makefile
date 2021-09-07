CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = minitalk
CLT = client
SRV = server
CLT_DIR =$(CLT)/
SRV_DIR =$(SRV)/
SRC = ./source/
SRV_SRC = $(SRC)$(SRV_DIR)$(SRV).c\
	$(SRC)$(SRV_DIR)server_sub.c
CLT_SRC = $(SRC)$(CLT_DIR)$(CLT).c\
	$(SRC)$(CLT_DIR)client_sub.c
OBJ_DIR = ./objects/
SRV_OBJS = $(OBJ_DIR)$(SRV_DIR)$(SRV).o\
	$(OBJ_DIR)$(SRV_DIR)server_sub.o
CLT_OBJS = $(OBJ_DIR)$(CLT_DIR)$(CLT).o\
	$(OBJ_DIR)$(CLT_DIR)client_sub.o
SRV_HDRS = ./include/$(SRV).h
CLT_HDRS = ./include/$(CLT).h
LIB = -L$(SRC)printf -lftprintf
PRINTF = $(SRC)printf/libftprintf.a

all:	$(NAME)

$(NAME): $(SRV) $(CLT)

$(SRV): $(SRV_OBJS) $(PRINTF)
	$(CC) -o $@ $(SRV_OBJS) $(LIB)

$(CLT): $(CLT_OBJS) $(PRINTF)
	$(CC) -o $@ $(CLT_OBJS) $(LIB)

$(PRINTF):
	$(MAKE) -C $(SRC)printf

$(SRV_OBJS): $(OBJ_DIR) $(SRV_SRC) $(SRV_HDRS)
	$(CC) $(FLAGS) -c $(SRC)$(SRV_DIR)$(SRV).c -o $(OBJ_DIR)$(SRV_DIR)$(SRV).o
	$(CC) $(FLAGS) -c $(SRC)$(SRV_DIR)server_sub.c -o $(OBJ_DIR)$(SRV_DIR)server_sub.o

$(CLT_OBJS): $(OBJ_DIR) $(CLT_SRC) $(CLT_HDRS)
	$(CC) $(FLAGS) -c $(SRC)$(CLT_DIR)$(CLT).c -o $(OBJ_DIR)$(CLT_DIR)$(CLT).o
	$(CC) $(FLAGS) -c $(SRC)$(CLT_DIR)client_sub.c -o $(OBJ_DIR)$(CLT_DIR)client_sub.o

$(OBJ_DIR):
	mkdir $@
	mkdir $@/$(CLT_DIR)
	mkdir $@/$(SRV_DIR)

clean:
	$(MAKE) -C $(SRC)printf clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(SRC)printf fclean
	rm -f $(SRV)
	rm -f $(CLT)

re: fclean all