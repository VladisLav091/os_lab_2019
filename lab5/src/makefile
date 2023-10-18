mutex :
	gcc mutex.c -o mutex -lpthread

locked_mutex :
	gcc locked_mutex.c -o locked_mutex -lpthread

deadlock : 
	gcc deadlock.c -o deadlock -lpthread

modul :
	gcc modul.c -o modul -pthread

all : mutex locked_mutex modul deadlock

clear :
	rm mutex locked_mutex modul deadlock
