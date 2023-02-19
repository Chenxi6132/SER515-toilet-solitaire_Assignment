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

    do {
        cout << "please enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 'a':
            deck.shuffle();
            cout << "cards shuffled" << endl;
            cout << endl;
            break;

        case 'b':
            cout << "please select rule to play:" << endl;
            cout << "1. Basic (1st & 4th same Suit --> remove middle two, 1st & 4th same rank --> remove all 4)" << endl;
            cout << "2. Intermediate --> neighbors are same rank --> remove pair!" << endl;
            cout << "3. House Rules --> (1st & 4th same Suit AND 3rd & 4th same rank --> remove last 3) " << endl;
            cout << "Please enter a number for slecting rules" << endl;
            cin >> rule_choice;

            if (rule_choice == 1)
            {
                
            }
            else if (rule_choice == 2)
            {

            }
            else if (rule_choice == 3)
            {

            }
            break;

        case 'q':
            cout << "exit" << endl;
            cout << endl;
            return 0;
            break;
        default:
            cout << "please enter a valid option" << endl;
            cout << endl;
            break;

        }
    } while (choice == 'a' || choice == 'b' || choice == 'q' || choice != true);
    
    system("pause");
}