CC := gcc
FLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -lSDL2_image -lm -Wall -lpthread
HDRS := $(wildcard src/c/*.h) 
SRCS := $(wildcard src/c/*.c)
OBJS := $(SRCS:src/c/%.c=tmp/%.o)
EXEC := out/PrehistoricWorld
#---------------------------------------------------------- test
FLAGS_TEST    := $(FLAGS)
SRCS_TEST     := $(wildcard test/c/*.c)
OBJS_TEST     := $(filter-out tmp/main.o, $(OBJS)) $(SRCS_TEST:test/c/%.c=tmp/%.o)
EXEC_TEST     := out/test

.SUFFIXES:
#---------------------------------------------------------- Targets

.PHONY: all

all: $(EXEC)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(FLAGS) && echo "EXEC [OK]  $@"

# --------------------------------------------------------------

.PHONY: test

test: $(EXEC_TEST)

$(EXEC_TEST): $(OBJS_TEST)
	$(CC) -o $@ $(OBJS_TEST) $(FLAGS_TEST) && echo "EXEC_TEST [OK] $@"

# --------------------------------------------------------------

tmp/%.o: src/c/%.c
	@$(CC) $(FLAGS) -c $< -o $@ && echo "tmp/%.o: src/c/%.c [OK]  $@"

tmp/%.o: test/c/%.c
	@$(CC) $(FLAGS_TEST) -c $< -o $@ && echo "tmp/%.o: test/c/%.c [OK]  $@"

.PHONY: clean, clear

clean clear:
	@rm -f out/* && echo "[CL]  out/"
	@rm -f tmp/* && echo "[CL]  tmp/"
