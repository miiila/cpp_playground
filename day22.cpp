//
// Task https://adventofcode.com/2020/day/22
//

#include <fstream>
#include <iostream>
#include <list>
#include <array>
#include <set>
#include "day22.h"
#include "Deck.h"

using namespace std;

void day22() {
  array<vector<int>, 2> decks = readInput();
  Deck player1 = Deck(decks[0]);
  Deck player2 = Deck(decks[1]);

  solve_first(player1, player2);
  player1 = Deck(decks[0]);
  player2 = Deck(decks[1]);
  solve_second(player1, player2);
}

void solve_first(Deck& player1, Deck& player2) {
  while (player1.has_cards() && player2.has_cards()) {
    playRound(player1, player2);
  }

  cout << "Part1: ";
  if (player1.has_cards()) {
    cout << player1.get_score();
  } else {
    cout << player2.get_score();
  }
  cout << endl;
}

void solve_second(Deck& player1, Deck& player2) {
  GameStates games;
  int winner = playGameRec(player1, player2, games);

  cout << "Part2: ";
  cout << (winner == 0 ? player1.get_score() : player2.get_score());
  cout << endl;
}

unsigned long getGameState(Deck& player1, Deck& player2) {
  return player1.get_hash() ^ player2.get_hash();
}


std::array<std::vector<int>, 2> readInput() {
  std::array<std::vector<int>, 2> decks;
  int currentPlayer = -1;
  std::ifstream file("/Users/mila/Downloads/input");
  if (file.is_open())
  {
    std::string line;
    while (getline(file, line))
    {
      if (line.rfind("Player", 0) == 0) {
        currentPlayer++;
        continue;
      }
      if (!line.empty()) {
        decks[currentPlayer].push_back(stoi(line));
      }
    }
  }

  return decks;
}

void playRound(Deck &player1, Deck &player2) {
  int card1 = player1.draw_top();
  int card2 = player2.draw_top();
  if (card1 > card2) {
    player1.insert_to_bottom(card1);
    player1.insert_to_bottom(card2);
  } else {
    player2.insert_to_bottom(card2);
    player2.insert_to_bottom(card1);
  }
}

int playGameRec(Deck &player1, Deck &player2, GameStates &games) {
  while (player1.has_cards() && player2.has_cards()) {
    unsigned long gameState = getGameState(player1, player2);
    if (games.count(gameState)) {
      return 0;
    }
    games.insert(gameState);

    playRound(player1, player2, games);
  }

  if (player1.has_cards()) {
   return 0;
  } else {
    return 1;
  }
}


int playRound(Deck &player1, Deck &player2, GameStates &games) {
  int card1 = player1.draw_top();
  int card2 = player2.draw_top();
  if (player1.get_cards_amount() < card1 || player2.get_cards_amount() < card2) {
    if (card1 > card2) {
      player1.insert_to_bottom(card1);
      player1.insert_to_bottom(card2);

      return 0;
    } else {
      player2.insert_to_bottom(card2);
      player2.insert_to_bottom(card1);

      return 1;
    }
  }

  Deck new_deck_1 = player1.get_new_deck(card1);
  Deck new_deck_2 = player2.get_new_deck(card2);
  GameStates newGames;
  int winner = playGameRec(new_deck_1, new_deck_2, newGames);
  if (winner == 0) {
    player1.insert_to_bottom(card1);
    player1.insert_to_bottom(card2);
  } else {
    player2.insert_to_bottom(card2);
    player2.insert_to_bottom(card1);
  }

  return winner;
}

