#pragma once
#include <stdint>

enum class Suit: uint8_t {
	Clubs,
	Diamonds,
	Hearts,
	Spades
};

enum class Rank : uint8_t {
	Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
};

struct Card {
	Rank rank;
	Suit suit;
};
