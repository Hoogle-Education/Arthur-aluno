#this target will compile all
default:
	make project

# make targets ###########################

project: tadlista.o taddic.o main.o
	gcc tadlista.o taddic.o main.o -o project
	make clean_objects

make run:
	cd Debug/
	./project
	cd ..

##########################################

# OBJECT FILES#######################
main.o: main.c
	gcc -c main.c

taddic.o: taddic.c taddic.h
	gcc -c taddic.c

tadlista.o: tadlista.c tadlista.h 
	gcc -c tadlista.c

# ###################################3333

clean_objects:
	rm -rf *.o *.out

clean:
	rm -rf .*o *.out test project

# g++ -c files.cpp -o files.o
# g++ -c test.cpp -o test.o
# g++ files.o files.o -o this
# ./this