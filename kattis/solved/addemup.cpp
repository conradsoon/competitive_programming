#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

//template ends
unordered_map<char, char> flippable_digits({{'1', '1'}, {'2', '2'}, {'5', '5'}, {'6', '9'}, {'8', '8'}, {'9', '6'}});
int flip(int n)
{
    string no = to_string(n);
    string flipped_no = "";
    for (auto it = no.crbegin(); it != no.crend(); ++it)
    {
        flipped_no += flippable_digits[*it];
    }
    return stoi(flipped_no);
}

bool is_flippable_no(int n)
{
    string no = to_string(n);
    return all_of(no.begin(), no.end(), [](char i) { return flippable_digits.find(i) != flippable_digits.end(); });
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    unordered_map<int, int> cards;
    unordered_map<int, int> flipped_cards;
    bool possible = false;
    while (n--)
    {
        int input;
        cin >> input;
        cards[input]++;
        if (is_flippable_no(input))
        {
            int flipped_input = flip(input);
            //check it does not equal its own flip
            if (flipped_input != input)
            {
                cards[flipped_input]++;
            }
            flipped_cards.insert({input, flipped_input});
            flipped_cards.insert({flipped_input, input});
        }
    }
    for (auto element : cards)
    {
        int card = element.first, qty = element.second;
        int card_to_find = s - card;
        // finds if card_to_find is in cards
        if (cards.find(card_to_find) != cards.end())
        {
            //checking against using its own flip
            if (card_to_find == flipped_cards[card])
            {
                if (cards[card] > 1)
                {
                    possible = true;
                    break;
                }
            }
            else
            {
                possible = true;
                break;
            }
        }
    }
    cout << (possible ? "YES" : "NO");
    return 0;
}