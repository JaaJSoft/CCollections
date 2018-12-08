CFLAGS =
CC = gcc
LDFLAGS =
SRCDIR = src/
OBJDIR = obj/
LIB =
SRC = $(wildcard $(SRCDIR)*.c)
OBJ  = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
outputdir = bin/

.PHONY: clean all

all: $(outputdir)libCCollections.a

$(outputdir)libCCollections.a: $(OBJ)
	@ar rcs $@ $^

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) -o $@ -c $< -I include/ $(CFLAGS) -O2

clean :
	rm -f $(OBJDIR)*.o $(OBJDIR)*~

doc :
	doxygen Doxyfile
