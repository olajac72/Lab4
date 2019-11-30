// CardDeck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CardDeck.h"

int main()
{
	CardDeck cd;
	CardUtilities cu;

	cd.print();
	cu.shuffle(&cd);
	cd.print();
	cu.sort(&cd);
	cd.print();
}

CardDeck::CardDeck()
{
	int n = 0;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 2; j < 15; j++)
		{
			Card add = Card(static_cast<rank_type>(j), static_cast<suit_type>(i), n);
			deckOfCards.push_back(add);
			n++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		Card add = Card(static_cast<rank_type>(15), static_cast<suit_type>(5), n);
		deckOfCards.push_back(add);
		n++;
	}
}

Card::Card(rank_type rank, suit_type suit, int position) : rank(rank), suit(suit), position(position)
{

}


void CardDeck::print()
{
	for (int i = 0; i < deckOfCards.size(); i++)
	{
		cout << "Position : " << deckOfCards[i].position << " : ";
		if (deckOfCards[i].rank == static_cast<rank_type>(15))
		{
			cout << "Joker" << endl;
		}
		else
		{
			switch (deckOfCards[i].rank)
			{
			case rank_type::Two:
				cout << "Two"; break;
			case rank_type::Three:
				cout << "Three"; break;
			case rank_type::Four:
				cout << "Four"; break;
			case rank_type::Five:
				cout << "Five"; break;
			case rank_type::Six:
				cout << "Six"; break;
			case rank_type::Seven:
				cout << "Seven"; break;
			case rank_type::Eight:
				cout << "Eight"; break;
			case rank_type::Nine:
				cout << "Nine"; break;
			case rank_type::Ten:
				cout << "Ten"; break;
			case rank_type::Jack:
				cout << "Jack"; break;
			case rank_type::Queen:
				cout << "Queen"; break;
			case rank_type::King:
				cout << "King"; break;
			case rank_type::Ace:
				cout << "Ace"; break;
			default:
				cout << "none";
			}

			cout << " of ";

			switch (deckOfCards[i].suit)
			{
			case suit_type::Club:
				cout << "clubs"; break;
			case suit_type::Diamond:
				cout << "diamonds"; break;
			case suit_type::Heart:
				cout << "hearts"; break;
			case suit_type::Spade:
				cout << "spades"; break;
			default:
				cout << "none";
			}

			cout << endl;
		}

	}
}
Card::Card()
{
	rank = rank_type::Ace;
	suit = suit_type::Club;
	position = 0;

}
void CardUtilities::shuffle(CardDeck* cardDeck)
{
	Card card;

	srand(time(NULL));

	for (int i = 54 ; i > 0; i--)
	{
		int card1 = rand() % i;
		
		card = cardDeck->deckOfCards[card1];
		cardDeck->deckOfCards[card1] = cardDeck->deckOfCards[i];
		cardDeck->deckOfCards[i] = card;
	}
}

void CardUtilities::sort(CardDeck* cardDeck)
{
	Card card;

	int i, j;
	for (i = 0; i < 55 - 1; i++)
	{
		for (j = 0; j < (55 - i - 1); j++)
		{
			if (cardDeck->deckOfCards[j].position > cardDeck->deckOfCards[j + 1].position)
			{
				card = cardDeck->deckOfCards[j];
				cardDeck->deckOfCards[j] = cardDeck->deckOfCards[j + 1];
				cardDeck->deckOfCards[j + 1] = card;
			}
		}
	}
}

Card* CardUtilities::checkMissing(const CardDeck* cardDeck)
{
	Card* cd = NULL;

	return cd;
}