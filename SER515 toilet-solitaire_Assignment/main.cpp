#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

enum Suit {
    SPADES = 0,
    HEARTS,
    DIAMONDS,
    CLUBS
};

class Card {
public:
    Suit suit;
    int value;
    string valueOfName;
    string fullname;

    Card(Suit suit, int value)
        : suit(suit), value(value), valueOfName(valueToString(value)), fullname(valueOfName + " of " + suitToString(suit)) {}

    string suitToString(Suit suit) {
        switch (suit) {
        case SPADES:
            return "Spades";
        case HEARTS:
            return "Hearts";
        case DIAMONDS:
            return "Diamonds";
        case CLUBS:
            return "Clubs";
        }
    }

    string valueToString(int value) {
        switch (value) {
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
        case 14:
            return "Ace";
        default:
            return to_string(value);
        }
    }


};

class Deck
{
   public:
    vector<Card> cards;

    Deck() { fillDeck(); }

    void fillDeck()
    {
        for (int i = 2; i <= 14; i++)
        {
            cards.push_back(Card(SPADES, i));
            cards.push_back(Card(HEARTS, i));
            cards.push_back(Card(DIAMONDS, i));
            cards.push_back(Card(CLUBS, i));
        }
    }

    void printDeck() {
        for (const auto& card : cards) {
            cout << card.fullname << endl;
        }
    }

    void shuffle()
    {
        srand(time(NULL));
        random_shuffle(cards.begin(), cards.end());
    }
};

int main()
{
    Deck deck;
    deck.fillDeck();


    char choice;
    int rule_choice;
    cout << "a. shuffle" << endl;
    cout << "b. play " << endl;
    cout << "q. quit." << endl;
    cout << endl;

    system("pause");
}