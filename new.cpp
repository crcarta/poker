#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
} Suit;

typedef enum {
	TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, 
	EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
} Rank;

typedef struct {
	Rank rank;
	Suit suit;
} Card;


#define DECK_SIZE 52

void init_deck(Card deck[DECK_SIZE]) {
	int index = 0;
	for (int s = 0; s < 4; s++ ) {
		for (int r = 2; r<= 14; r++) {
		deck[index].rank = (Rank)r;
		deck[index].suit = (Suit)s;
		index++;
		}
	}
}

void shuffle_deck(Card deck[DECK_SIZE]) {
	for(int i = 0; i < DECK_SIZE; i++) {
	int j = rand() % DECK_SIZE;
	Card tmp = deck[i];
	deck[i] = deck[j]; 
	deck[j] = tmp;
	}
}

int main() {
	srand(time(NULL));
	Card deck[DECK_SIZE];
	init_deck(deck);
	shuffle_deck(deck);
	for( int i = 0; i < 5; i++){
		printf("Card %d: rank=%d suit=%d\n", i, deck[i].rank, deck[i].suit);
	}
}
