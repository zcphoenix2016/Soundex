UTLIB = googletest/build/googlemock/libgmock_main.a\
        googletest/build/googlemock/libgmock.a\
        googletest/build/googlemock/gtest/libgtest.a

UTINC = -isystem googletest/googlemock/include\
       -isystem googletest/googletest/include\

UTFLAG = -g -pthread -DUNIT_TEST -Wno-write-strings

all:
	g++ -std=c++14 *.cpp -o Soundex -g

ut:
	g++ -std=c++14 ${UTFLAG} ${UTINC} ${UTLIB} *.cpp Test_modules/*.cpp -o ut_Soundex

clean:
	rm -rf *.o
	rm -rf Test_modules/*.o
	rm -rf ./Soundex
	rm -rf ./ut_Soundex
