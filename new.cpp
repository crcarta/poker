#include <stdio.h>
#include <stdlib.h>
#include <time.h>

constexpr int DECK_SIZE = 52;

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


struct Deck {
	Card cards[DECK_SIZE];
	int top;
};

struct Player {
	Card hole[2];
	int chips;
};

//F(x)

void init_deck(Deck* deck) 
{
	deck->top=0;
	int index=0;
	for (int s = 0; s < 4; s++ ) {
		for(int r = 2; r<= 14; r++) {
		deck->cards[index].rank = static_cast<Rank>(r);
		deck->cards[index].suit = static_cast<Suit>(s);
		index++;
		}
	}
}

void shuffle(Deck* deck)
{
	for(int i = 0; i < DECK_SIZE; i++) {
		int j = rand() % DECK_SIZE;
		Card tmp = deck->cards[i];
		deck->cards[i] = deck->cards[j]; 
		deck->cards[j] = tmp;
	}
	deck->top=0;
}

Card deal_card(Deck* deck) 
{
	Card c = deck->cards[deck->top];
	deck->top++;
	return c;
}

void deal_hole_cards(Player* players, int num_players, Deck* deck)
{
	for ( int i = 0; i < num_players; i++) {
		players[i].hole[0] = deal_card(deck);
		players[i].hole[1] = deal_card(deck);
	}
}



int main()
{
	srand(time(NULL));
	Deck deck; 
	init_deck(&deck);
	shuffle(&deck);
	Player players[3];
	for (int i =0; i < 3; i++)
		players[i].chips=500;
	
	deal_hole_cards(players, 3, &deck);

	for(int i=0; i < 3; i++) {
	printf("Player %d cards:\n", i+1);
		for(int x = 0 ; x < 2; x++)
		printf("    rank %d, suit %d\n",players[i].hole[x].rank, players[i].hole[x].suit);
	}

		
}
