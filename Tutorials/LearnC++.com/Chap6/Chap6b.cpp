#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include <string>

enum CardSuit
{
	SUIT_CLUBS,
	SUIT_SPADES,
	SUIT_DIAMONDS,
	SUIT_HEARTS,
	MAX_SUITS
};

enum CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANK
};

struct Card 
{
	CardSuit suit;
	CardRank rank;
};

void printCard(const Card card)
{
	switch (card.rank)
	{
		case RANK_2: 		std::cout << "2"; 	break;
		case RANK_3: 		std::cout << "3"; 	break;
		case RANK_4: 		std::cout << "4"; 	break;
		case RANK_5: 		std::cout << "5"; 	break;
		case RANK_6: 		std::cout << "6"; 	break;
		case RANK_7: 		std::cout << "7"; 	break;
		case RANK_8: 		std::cout << "8"; 	break;
		case RANK_9: 		std::cout << "9"; 	break;
		case RANK_10: 		std::cout << "T"; 	break;
		case RANK_JACK: 	std::cout << "J"; 	break;
		case RANK_QUEEN: 	std::cout << "Q"; 	break;
		case RANK_KING: 	std::cout << "K"; 	break;
		case RANK_ACE: 		std::cout << "A"; 	break;
		default:			std::cout << "-";	break;
	}

	switch(card.suit)
	{
		case SUIT_SPADES:	std::cout << "S";	break;
		case SUIT_HEARTS:	std::cout << "H";	break;
		case SUIT_DIAMONDS:	std::cout << "D";	break;
		case SUIT_CLUBS:	std::cout << "C";	break;
		default:			std::cout << "-";	break;
	}

	// std::cout << "  ";
}

void printDeck(const std::array<Card, 52> &deck)
{
	for (auto const &card : deck)
		printCard(card);
	std::cout << "\n";
}

void swapCard(Card &card1, Card &card2)
{
	Card tempCard = card1;
	card1 = card2;
	card2 = tempCard;
}

void shuffleDeck(std::array<Card, 52> &deck)
{

	std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
	std::uniform_int_distribution<> die(1, 52);

	using index_t = std::array<Card, 52>::size_type;
	for (index_t i = 0; i < 52; i++)
		swapCard(deck[i], deck[static_cast<index_t>(die(mersenne))]);
}

int getCardValue(Card card) 
{
	switch (card.rank)
	{
		case RANK_2 : 		return 2;
		case RANK_3 : 		return 3;
		case RANK_4 : 		return 4;
		case RANK_5 : 		return 5;
		case RANK_6 : 		return 6;
		case RANK_7 : 		return 7;
		case RANK_8 : 		return 8;
		case RANK_9 : 		return 9;
		case RANK_10 : 		return 10;
		case RANK_JACK : 	return 10;
		case RANK_QUEEN : 	return 10;
		case RANK_KING : 	return 10;
		case RANK_ACE : 	return 11;
		default:			return -1;
	};
}


int dealCard(std::array<Card, 52> &deck, std::array<Card, 52>::size_type &i)
{

	printCard(deck[i]);
	int value = getCardValue(deck[i]);
	i++;
	return value;
}


int playBlackjack(std::array<Card, 52> &deck)
{
	// std::cout << "Welcome to blackjack!\n";
	// std::cout << "Please enter your name: ";
	// std::string name; 
	// std::cin >> name;
	// std::cout << "Welcome " << name << "!\n";

	int gameCounter = 1;
	std::cout << "\n";
	std::cout << "##########\n";
	std::cout << "# Game " << gameCounter << " #\n";
	std::cout << "##########\n";
	std::cout << "\n";

	// deal 1 card to the dealer
	using card_index = std::array<Card, 52>::size_type;
	card_index i = 0;
	int dealer = 0;
	std::cout << "Dealer draws ";
	dealer += dealCard(deck, i);
	std::cout << " (dealer score = " << dealer << ")\n";
	std::cout << "\n";

	// deal 2 cards to player
	int player = 0;
	std::cout << "You draw ";
	player += dealCard(deck, i);
	std::cout << " and ";
	player += dealCard(deck, i);
	std::cout << " (player score = " << player << ")\n";

	bool keepDrawing = true;
	do 
	{
		bool keepAsking = true;		
	    while (true) // Loop until user enters a valid input
	    {
	        std::cout << "Do you want to stick (s) or twist (t)?";
	        char st;
	        std::cin >> st;
	 
	        if (std::cin.fail()) // has a previous extraction failed?
	        {
	            // yep, so let's handle the failure
	            std::cin.clear(); // put us back in 'normal' operation mode
	            std::cin.ignore(32767,'\n'); // and remove the bad input
	        }
	        else // else our extraction succeeded
	            return x; // so return the value we extracted
	    }
	} while (keepDrawing == true);

	return 0;
}


int main()
{

	std::array<Card, 52> deck;
	int k = 0;
	for (int i = 0; i < MAX_SUITS; i++)
		for (int j = 0; j < MAX_RANK; j++)
		{
			deck[k].suit = static_cast<CardSuit>(i);
			deck[k].rank = static_cast<CardRank>(j);
			k++;
		}

	shuffleDeck(deck);
			
	playBlackjack(deck);

	return 0;
}