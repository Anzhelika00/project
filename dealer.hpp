#pragma once

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

namespace dealer
{
    int get_random_card();

    vector<int> generate_dealer_cards();

    int get_card_values(vector<int> cards);

    void display_card_value(int card);

    void print_dealer_cards(vector<int> cards, int dealer_total);
}
