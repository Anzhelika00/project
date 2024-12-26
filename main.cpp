#include <iostream>
#include "../Downloads/dealer.hpp"
using namespace std;

void game()
{
    vector<int> dealer_cards = dealer::generate_dealer_cards();
    int dealer_total = dealer::get_card_values(dealer_cards);
    
    cout << "Твои карты :\n";
    vector<int> player_cards = {dealer::get_random_card(), dealer::get_random_card()};
    int player_total = dealer::get_card_values(player_cards);
    for (const int card : player_cards)
    {
        dealer::display_card_value(card);
    }
    cout << "Ваша общая сумма: " << player_total  << '\n';

    bool bust = false;

    while (bust == false)
    {   

        if (player_total == 21)
        {
            break;
        }


        cout << "взять еще (y) или стоп(n)?  " << player_total  << '\n';
        char answer;
        cin >> answer;

        if (answer == 'n')
        {
            break;
        }
        else if (answer == 'y')
        {
            int card = dealer::get_random_card();

            cout << "Ваша карта: ";
            dealer::display_card_value(card);

            player_cards.push_back(card);
            player_total = dealer::get_card_values(player_cards);
            cout << "Ваша общая сумма сейчас составляет: " << player_total  << '\n';
            
            if (player_total > 21)
            {
                bust = true;
            }
        }
        else if (answer != 'y' || answer != 'n')
        {
            cout << "Ответьте буквой y(если хотите взять) или n(если хотите стопнуть)!\n";
        }
    }
    dealer::print_dealer_cards(dealer_cards, dealer_total);
    if (bust)
    {
        if (dealer_total > 21)
        {
            cout << "Ничья! ”У вас и у дилера перебор.\n";
        }
        else
        {
        cout << "Тебя разорили! Дилер выигрывает.\n";
    }
}
    else
    {
        if (player_total == 21)
        {
            cout << "Блэкджек! Вы выиграли.\n";
            return;
        }
        
        if (dealer_total > 21)
        {
            cout << "Дилер разорен! Вы выиграли!\n";
        }
        else if (dealer_total > player_total)
        {
            cout << "У дилера рука лучше, чем у вас. Дилер выигрывает.\n";
        }
        else if (dealer_total == player_total)
        {
            cout << "Ничья! У вас и у дилера одинаковая сумма.\n";
        }
        else
        {
            cout << "У вас лучше рука, чем у дилера. Вы выиграли.\n";
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    bool is_running = true;

    while (is_running)
    {
        game();

        char answer;
        cout << "Вы хотите выйти ? (Y/N): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            is_running = false;
        else
            cout << "\n\n";
    }

    return 0;
}
