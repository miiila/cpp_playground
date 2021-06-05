
#include <iostream>
#include "Deck.h"

Deck::Deck(const std::vector<int>& input) {
  for (int i : input) {
    deck.push_back(i);
  }
}

int Deck::draw_top() {
  int& top = deck.front();
  deck.pop_front();
  return top;
}

void Deck::insert_to_bottom(int card) {
  return deck.push_back(card);
}

int Deck::get_score() {
  int score = 0;
  int mult = deck.size();
  for (int i : deck) {
    score += i*mult--;
  }
  return score;
}

bool Deck::has_cards() {
  return !deck.empty();
}

std::string Deck::get_hash() {
 std::string hash;
 for (auto i : deck) {
   hash += std::to_string(i);
 }
 return hash;
}

int Deck::get_cards_amount() {
   return deck.size();
}

Deck Deck::get_new_deck(int limit) {
  std::vector<int> a(begin(deck), begin(deck)+limit);
  return Deck(a);
}