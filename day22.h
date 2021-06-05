
#ifndef INTRO_DAY22_H
#define INTRO_DAY22_H

#include <vector>
#include <set>
#include <array>
#include "Deck.h"

void day22();
void solve_first(Deck& player1, Deck& player2);
void solve_second(Deck& player1, Deck& player2);
std::array<std::vector<int>, 2> readInput();

void playRound(Deck& player1, Deck& player2);
Deck& playRound(Deck& player1, Deck& player2, std::set<std::string> &games);
Deck& playGameRec(Deck &player1, Deck &player2, std::set<std::string> &games);
std::string getGameState(Deck& player1, Deck& player2);

#endif //INTRO_DAY22_H
