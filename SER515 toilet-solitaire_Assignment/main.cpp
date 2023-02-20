#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include<cstdlib>
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
       vector<Card> hand;

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

    void deal_card_basic()
    {
        int hand_size = hand.size();
        cout << "draw 4 cards first" << endl;
        for (int x = 0; x < 4; x++)
        {
            hand.push_back(cards[x]);
            cards.pop_back();
        }
        print_hand();
        cout << endl;
        basic_rule(hand_size);
        hand_size = hand.size();

        for (int i = 47; i > 0; i = i)
        {
            
            if (hand_size < 4)
            {
                for (int j = hand_size; j <= 4; j++)
                {
                    hand.push_back(cards[i]);
                    cards.pop_back();
                    i--;
                }
                cout << "after draw " << 4 - hand_size << "cards, the cards on your hand is " << endl;
                print_hand();
                cout << endl;
                basic_rule(hand_size);
            }
            else
            {
                hand.push_back(cards[i]);
                cards.pop_back();
                i--;
                cout << "after draw one card, the cards on your hand is " << endl;
                print_hand();
                cout << endl;

                basic_rule(hand_size); 
            }
        }
        
    }

   void deal_card_Intermediate()
    {
       int hand_size = hand.size();
       cout << "draw 4 cards first" << endl;
       for (int x = 0; x < 4; x++)
       {
           hand.push_back(cards[x]);
           cards.pop_back();
       }
       print_hand();
       cout << endl;
       Intermediate_rule(hand_size);
       hand_size = hand.size();

        for (int i = 47; i >0; i = i)
        {
            
            if (hand_size < 4)
            {
                for (int j = hand_size; j <= 4; j++)
                {
                    hand.push_back(cards[i]);
                    cards.pop_back();
                    i--;
                }
                cout << "after draw " << 4 - hand_size << "cards, the cards on your hand is " << endl;
                print_hand();
                cout << endl;
                Intermediate_rule(hand_size);
            }
            else
            {
                hand.push_back(cards[i]);
                cards.pop_back();
                i--;
                cout << "after draw one card, the cards on your hand is " << endl;
                print_hand();
                cout << endl;

                Intermediate_rule(hand_size);
            }
        }
    }

   void deal_card_House_Rule()
   {
       int hand_size = hand.size();
       cout << "draw 4 cards first" << endl;
       for (int x = 0; x < 4; x++)
       {
           hand.push_back(cards[x]);
           cards.pop_back();
       }
       print_hand();
       cout << endl;
       House_rule(hand_size);
       hand_size = hand.size();

       for (int i = 47; i > 0; i = i)
       {
           if (hand_size < 4)
           {
               for (int j = hand_size; j <= 4; j++)
               {
                   hand.push_back(cards[i]);
                   cards.pop_back();
                   i--;
               }
               cout << "after draw " << 4 - hand_size << "cards, the cards on your hand is " << endl;
               print_hand();
               cout << endl;
               House_rule(hand_size);
           }
           else
           {
               hand.push_back(cards[i]);
               cards.pop_back();
               i--;
               cout << "after draw one card, the cards on your hand is " << endl;
               print_hand();
               cout << endl;

               House_rule(hand_size);
           }
       }
   }

    void print_hand()
    {
        for (const auto& card : hand)
        {
            cout << card.fullname << endl;
        }
    }

    void basic_rule(int hand_sizeb)
    {
        
        hand_sizeb = hand.size();
        int last_element = hand_sizeb - 1;
        int last_4thelement = hand_sizeb - 4;
        if (hand.at(last_element).value == hand.at(last_4thelement).value)
        {
            hand.erase(hand.end()-4, hand.end());
            cout << "remove last four cards" << endl;
            cout << "after reomove 4 cards, the left hand in your hand is "<<endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_element).suit == hand.at(last_4thelement).suit)
        {
            hand.erase(hand.end() - 4);
            hand.pop_back();
            cout << "remove 1th and 4th card" << endl;
            cout << "after reomove 2 cards, the left hand in your hand is "<<endl;
            print_hand();
            cout << endl;
        }
        else
        {
            cout << "no cards need to remove" << endl;
            cout << endl;
        }

        
    }

    void Intermediate_rule(int hand_sizeI)
    {
        hand_sizeI = hand.size();
        int last_element = hand_sizeI - 1;
        int last_2thelement = hand_sizeI - 2;
        int last_3thelement = hand_sizeI - 3;
        int last_4thelement = hand_sizeI - 4;
        if (hand.at(last_element).value == hand.at(last_2thelement).value)
        {
            hand.erase(hand.end() - 2, hand.end());
            cout << "remove last 2 cards" << endl;
            cout << "after reomove 2 cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_2thelement).value == hand.at(last_3thelement).value)
        {
            hand.erase(hand.end() - 3, hand.end() - 1);
            cout << "remove last 2th and last 3th cards" << endl;
            cout << "after reomove last 2th and last 3th cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_3thelement).value == hand.at(last_4thelement).value)
        {
            hand.erase(hand.end() - 4, hand.end() - 2);
            cout << "remove last fourth and last third cards" << endl;
            cout << "after reomove last fourth and last third cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_element).value == hand.at(last_4thelement).value)
        {
            hand.erase(hand.end() - 4, hand.end());
            cout << "remove last four cards" << endl;
            cout << "after reomove 4 cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_element).suit == hand.at(last_4thelement).suit)
        {
            hand.erase(hand.end() - 4);
            hand.pop_back();
            cout << "remove 1th and 4th card" << endl;
            cout << "after reomove 2 cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else
        {
            cout << "no cards need to remove" << endl;
            cout << endl;
        }
    }

    void House_rule(int hand_sizeR)
    {
        hand_sizeR = hand.size();
        int last_element = hand_sizeR - 1;
        int last_2thelement = hand_sizeR - 2;
        int last_3thelement = hand_sizeR - 3;
        int last_4thelement = hand_sizeR - 4;
        if (hand.at(last_element).suit == hand.at(last_4thelement).suit && hand.at(last_element).value == hand.at(last_2thelement).value)
        {
            hand.erase(hand.end() - 3, hand.end());
            cout << "remove last 3 cards" << endl;
            cout << "after reomove 3 cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_element).suit == hand.at(last_4thelement).suit && hand.at(last_2thelement).value == hand.at(last_3thelement).value)
        {
            hand.erase(hand.end() - 3, hand.end());
            cout << "remove last 3 cards" << endl;
            cout << "after reomove 3 cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_element).suit == hand.at(last_4thelement).suit && hand.at(last_3thelement).value == hand.at(last_4thelement).value)
        {
            hand.erase(hand.end() - 4, hand.end() - 1);
            cout << "remove first 3 cards" << endl;
            cout << "after reomove 3 cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_element).value == hand.at(last_2thelement).value)
        {
            hand.erase(hand.end() - 2, hand.end());
            cout << "remove last 2 cards" << endl;
            cout << "after reomove 2 cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_2thelement).value == hand.at(last_3thelement).value)
        {
            hand.erase(hand.end() - 3, hand.end() - 1);
            cout << "remove last 2th and last 3th cards" << endl;
            cout << "after reomove last 2th and last 3th cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_3thelement).value == hand.at(last_4thelement).value)
        {
            hand.erase(hand.end() - 4, hand.end() - 2);
            cout << "remove last fourth and last third cards" << endl;
            cout << "after reomove last fourth and last third cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_element).value == hand.at(last_4thelement).value)
        {
            hand.erase(hand.end() - 4, hand.end());
            cout << "remove last four cards" << endl;
            cout << "after reomove 4 cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else if (hand.at(last_element).suit == hand.at(last_4thelement).suit)
        {
            hand.erase(hand.end() - 4);
            hand.pop_back();
            cout << "remove 1th and 4th card" << endl;
            cout << "after reomove 2 cards, the left hand in your hand is " << endl;
            print_hand();
            cout << endl;
        }
        else
        {
            cout << "no cards need to remove" << endl;
            cout << endl;
        }
    }

    void Result()
    {

    }
};

int main()
{
    Deck deck;
    deck.printDeck();
    cout << "card initialized" << endl;
    cout << endl;
    cout << endl;


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
                deck.deal_card_basic();
                
            }
            else if (rule_choice == 2)
            {
                deck.deal_card_Intermediate();
            }
            else if (rule_choice == 3)
            {
                deck.deal_card_House_Rule();
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