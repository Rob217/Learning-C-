#include <iostream>
#include <array>
#include <ctime>
#include <random>
#include <cstdlib>
#include <string>

enum CardRank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    MAX_RANKS
};

enum CardSuit
{
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES,
    MAX_SUITS
};

struct Card
{
    CardRank rank;
    CardSuit suit;
};

void printCard(const Card &card)
{
    switch (card.rank)
    {
        case TWO:       std::cout << "2";   break;
        case THREE:     std::cout << "3";   break;
        case FOUR:      std::cout << "4";   break;
        case FIVE:      std::cout << "5";   break;
        case SIX:       std::cout << "6";   break;
        case SEVEN:     std::cout << "7";   break;
        case EIGHT:     std::cout << "8";   break;
        case NINE:      std::cout << "9";   break;
        case TEN:       std::cout << "T";   break;
        case JACK:      std::cout << "J";   break;
        case QUEEN:     std::cout << "Q";   break;
        case KING:      std::cout << "K";   break;
        case ACE:       std::cout << "A";   break;
        case MAX_RANKS: std::cout << "";    break;
    }

    switch (card.suit)
    {
        case CLUBS:     std::cout << "C";   break;
        case SPADES:    std::cout << "S";   break;
        case HEARTS:    std::cout << "H";   break;
        case DIAMONDS:  std::cout << "D";   break;
        case MAX_SUITS: std::cout << "";    break;
    }

}

void printDeck(const std::array<Card, 52> &deck)
{
    for (const auto card : deck)
    {
        printCard(card);
        std::cout << "  ";
    }
    std::cout << "\n";
}

void swapCard(Card &card1, Card &card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52> &deck)
{
    using t_index = std::array<Card, 52>::size_type;
    for (t_index c = 0; c < 52; c++)
    {
        t_index d = getRandomNumber(0, 51);
        swapCard(deck[c], deck[d]);
    }
}

int getCardValue(const Card &card)
{
    switch (card.rank)
    {
        case TWO:       return 2;
        case THREE:     return 3;
        case FOUR:      return 4;
        case FIVE:      return 5;
        case SIX:       return 6;
        case SEVEN:     return 7;
        case EIGHT:     return 8;
        case NINE:      return 9;
        case TEN:       return 10;
        case JACK:      return 10;
        case QUEEN:     return 10;
        case KING:      return 10;
        case ACE:       return 11;
        case MAX_RANKS: return 0;
    };
    return 0;
}

void drawCard(bool player, int &score, const Card *(&cardPtr))
{
    std::string name;
    if (player == true)
        name = "player";
    else
        name = "dealer";
    std::cout << name << " draws: ";
    printCard(*cardPtr);
    score += getCardValue(*cardPtr++);
    std::cout << " (" << name << " score = " << score << ")\n";

}

bool playBlackjack(const std::array<Card, 52> &deck)
{
    const Card *cardPtr = &deck[0];
    int playerScore = 0;
    int dealerScore = 0;
    
    // dealer gets one card
    drawCard(false, dealerScore, cardPtr);
   
    // player gets two cards
    drawCard(true, playerScore, cardPtr);
    drawCard(true, playerScore, cardPtr);

    // ask player whether they want to draw a card
    while (true)
    {
        std::cout << "Draw another card (y/n)? ";
        char yn;
        std::cin >> yn;
        if (yn == 'y')
        {
            drawCard(true, playerScore, cardPtr);
            if (playerScore > 21)
                return false;
        }
        else
            break;
    }

    // dealer draws cards
    while (dealerScore < 17)
    {
        drawCard(false, dealerScore, cardPtr);
        if (dealerScore > 22)
            return true;
    }

    if (playerScore > dealerScore)
        return true;

    return false;
}

int main() 
{
    srand(static_cast<unsigned int>(time(0)));
    rand();
    std::array<Card, 52> deck;

	using index_t = std::array<Card, 52>::size_type;
	index_t card = 0;

	for (int suit = 0; suit < MAX_SUITS; ++suit)
	for (int rank = 0; rank < MAX_RANKS; ++rank)
	{
		deck[card].suit = static_cast<CardSuit>(suit);
		deck[card].rank = static_cast<CardRank>(rank);
		++card;
	}

    shuffleDeck(deck);
    bool wonGame;
    wonGame = playBlackjack(deck);
    if (wonGame)
        std::cout << "Congratulations! You won! \n";
    else
        std::cout << "Oh no! You lost! \n";

    return 0;
}
