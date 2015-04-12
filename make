large_number.o : large_number.cpp large_number.h
        g++ -Wall -g -c large_number.cpp

25.o : 25.cpp
        g++ -Wall -g -c 25.cpp

25 : 25.o large_number.o
        g++ -g 25.o largenumber.o -lm -o 25

32 : 32.cpp
        g++ -Wall -g 32.cpp -o 32