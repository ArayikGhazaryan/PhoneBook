all: PhoneBook

PhoneBook: main.o phonebook.o
	g++ main.o phonebook.o -o PhoneBook

main.o: main.cpp
	g++ -c main.cpp

phonebook.o: phonebook.cpp
	g++ -c phonebook.cpp

clean:
	rm -rf *.o hello
