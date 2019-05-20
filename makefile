all : a.out

a.out : main.o user.o handle_input.o publisher.o film.o comment.o notification.o reply.o netflix.o
	g++ main.o user.o handle_input.o publisher.o film.o comment.o notification.o reply.o netflix.o -o a.out

main.o: main.cpp netflix.h
	g++ -c main.cpp -o main.o

user.o : user.cpp user.h film.h notification.h
	g++ -c user.cpp -o user.o

handle_input.o : handle_input.cpp handle_input.h film.h
	g++ -c handle_input.cpp -o handle_input.o

publisher.o : publisher.cpp publisher.h user.h film.h
	g++ -c publisher.cpp -o publisher.o

film.o : film.cpp film.h comment.h
	g++ -c film.cpp -o film.o

comment.o : comment.cpp comment.h reply.h
	g++ -c comment.cpp -o comment.o

reply.o : reply.cpp reply.h
	g++ -c reply.cpp -o reply.o

netflix.o : netflix.cpp netflix.h handle_input.h
	g++ -c netflix.cpp -o netflix.o