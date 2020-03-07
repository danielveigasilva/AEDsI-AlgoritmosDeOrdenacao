LIBS ?= -lhelper -lsort

build: folder $(LIBS) main

folder:
	@mkdir -p build

-lhelper:
	@echo Compilando Lib: helper 
	@gcc -c lib/helper.c -o build/helper.o
	@ar rcs build/libhelper.a build/helper.o
	@rm build/helper.o

-lsort:
	@echo Compilando Lib: sort
	@gcc -c lib/sort.c -o build/sort.o
	@ar rcs build/libsort.a build/sort.o
	@rm build/sort.o

main:
	@echo Building...
	@gcc -static src/main.c -L ./build -I ./lib $(LIBS) -o build/main.out
	@echo Executando:
	@echo 
	@build/main.out

