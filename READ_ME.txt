Debug:
g++ -c main.cpp -Isrc/include
g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system  
./main.exe

W folderze dla prowadzącego jest plik.exe, proszę otworzyć i przetestować.