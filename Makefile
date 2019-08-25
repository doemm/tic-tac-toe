play: play.cc tic_tac_toe.cc
	g++ -std=c++17 -O2 -Wall play.cc tic_tac_toe.cc -o play

clean:
	rm play
