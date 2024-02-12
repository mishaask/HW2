all: my_graph my_Knapsack libmy_mat.a

my_graph: my_graph.o libmy_mat.a
	gcc -Wall -g -o my_graph  my_graph.o my_mat.o libmy_mat.a

my_Knapsack: my_Knapsack.o
	gcc -Wall -g my_Knapsack.o -o my_Knapsack

my_Knapsack.o:my_Knapsack.c my_mat.h
	gcc -c my_Knapsack.c

my_graph.o: my_graph.c my_mat.h
	gcc -c my_graph.c

my_mat.o: my_mat.c my_mat.h
	gcc -c my_mat.c

libmy_mat.a: my_mat.o
	ar -rcs libmy_mat.a my_mat.o
	ranlib libmy_mat.a

.PHONY: clean all

clean:
	rm -f *.o *.a my_graph my_Knapsack