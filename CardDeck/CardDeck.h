#pragma once
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
enum class rank_type
{
	Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace, Joker
};

enum class suit_type
{
	Club = 1, Diamond, Heart, Spade, none
};

class Card
{
private:

public:
	rank_type rank;
	suit_type suit;
	int position;
	Card(rank_type rank, suit_type suit, int position);
	Card();
};

class CardDeck
{
private:

public:
	vector<Card> deckOfCards;
	CardDeck();
	void print();
};

class CardUtilities
{
private:

public:
	void shuffle(CardDeck* cardDeck);
	void sort(CardDeck* cardDeck);
	Card* checkMissing(const CardDeck* cardDeck);
};