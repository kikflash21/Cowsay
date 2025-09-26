all: new wild reading

new: newcow.c
	clang -o new newcow.c

wild: wildcow.c
	clang -o wild wildcow.c 

reading: reading_cow.c 
	clang -o reading reading_cow.c

automates: automates.c
	clang -o automates automates.c
