alchemy_main:
	cc market_state.c -o market_state.o -c
	cc alchemy_main.c -lncurses -o main.o -c
	cc -o alchemy_main main.o market_state.o -lncurses