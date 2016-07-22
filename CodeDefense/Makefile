test: main.c ./person/Person.o ./number/Number.o ./filehandler/Filehandler.o
	gcc -pedantic -Wall -Werror -Wextra -o test main.c ./person/Person.o ./number/Number.o ./filehandler/Filehandler.o

Person.o: ./person/Person.c ./person/Person.h
	gcc ./person/Person.c ./person/Person.h

Number.o: ./number/Number.c ./number/Number.h
	gcc ./number/Number.c ./number/Number.h

Filehandler.o: ./filehandler/Filehandler.c ./filehandler/Filehandler.h
	gcc ./filehandler/Filehandler.c ./filehandler/Filehandler.h

clean:
	rm test
	rm ./person/Person.o
	rm ./number/Number.o
	rm ./filehandler/Filehandler.o