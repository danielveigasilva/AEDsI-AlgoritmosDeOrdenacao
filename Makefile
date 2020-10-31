ifdef OS
   CREATE_DIR = if not exist "build\" mkdir "build\"
   REMOVE_FILE = rd
   FILE_NAME = main.exe
else
   ifeq ($(shell uname), Linux)
      CREATE_DIR = mkdir -p build
	  REMOVE_FILE = rm build/
	  FILE_NAME = main.out
   endif
endif

LIBS = -lsort -lhelper

build: folder compilacao $(LIBS) main run

folder:
	@$(CREATE_DIR)

compilacao: 
	@echo Compilando Libs...
	@cd build && gcc -c ../libs/*.c

-lhelper: 
	cd build && ar rcs libhelper.a $(shell dir /b/s "helper*.o")

-lsort:
	cd build && ar rcs libsort.a $(shell dir /b/s "sort*.o")

main:
	@echo Building...
	@gcc -static src/main.c -L ./build -I ./libs $(LIBS) -o build/$(FILE_NAME)

run:
	@echo Executando:
	@./build/$(FILE_NAME)

