
#ifndef INTRO_DECK_H
#define INTRO_DECK_H


#include <vector>
#include <deque>
#include <string>


class Deck {

public:
  Deck(const std::vector<int> &);

  int draw_top();

  void insert_to_bottom(int card);

  int get_score();

  int get_cards_amount();

  bool has_cards();

  Deck get_new_deck(int limit);

  std::string get_hash();

private:
  std::deque<int> deck;
};

#endif //INTRO_DECK_H
