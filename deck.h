#pragma once
#include "card.h"
#include<vector>

class Deck {
public: 
	Deck();

	void shuffle();
	Card deal();
	bool empty() const;

private:
	std::vector<Card> cards_;
	std::size_t index_;
};

