#include "../Downloads/dealer.hpp"
using namespace std;
//создание функций
namespace dealer
{
    int get_random_card()
    {
        return 1 + (rand() % 10);
    }

    vector<int> generate_dealer_cards()
    {
        vector<int> cards = { get_random_card(), get_random_card() };

        while (get_card_values(cards) < 17)
        {
            cards.push_back(get_random_card());
        }

        return cards;
    }

    int get_card_values(vector<int> cards)
    {
        int total = 0;

        for (const int card : cards)
        {
            total += card;
        }

        return total;
    }

    void display_card_value(int card)
    {
        if (card == 1)
        {
            cout << "A\n";
        }
        else if (card > 1 && card < 10)
        {
            cout << card << '\n';
        }
        else
        {
            int chance = rand() % 101;

            if (chance < 10)
            {
                cout << "10\n";
            }
            else if (chance < 30)
            {
                cout << "J\n";
            }
            else if (chance < 60)
            {
                cout << "Q\n";
            }
            else
            {
                cout << "K\n";
            }
        }
    }


    void print_dealer_cards(vector<int> cards, int dealer_total)
    {

        cout << " Карты дилера : \n";

        for (const int card : cards)
        {
            dealer::display_card_value(card);
        }
        cout << "Сумма дилера: " << dealer_total << '\n';
    }
}
