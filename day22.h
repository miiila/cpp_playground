
#ifndef INTRO_DAY22_H
#define INTRO_DAY22_H

#include <vector>
#include <unordered_set>
#include <array>
#include "Deck.h"

typedef std::unordered_set<unsigned long> GameStates;

void day22();
void solve_first(Deck& player1, Deck& player2);
void solve_second(Deck& player1, Deck& player2);
std::array<std::vector<int>, 2> readInput();

void playRound(Deck& player1, Deck& player2);
int playRound(Deck& player1, Deck& player2, GameStates &games);
int playGameRec(Deck &player1, Deck &player2, GameStates &games);
unsigned long getGameState(Deck& player1, Deck& player2);

#endif //INTRO_DAY22_H
