#include <iostream>
#include <string>
#include <vector>

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
struct node
{
    node *prev = nullptr;
    node *next = nullptr;
    int e;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int size = 2;
    int mid_index = 0;
    node *head = new node;
    node *tail = new node;
    head->next = tail;
    tail->prev = head;
    node *mid = head;
    while (n--)
    {
        string com;
        int arg;
        cin >> com >> arg;
        if (com == "push_front")
        {
            node *temp = new node;
            temp->e = arg;
            temp->next = head->next;
            (head->next)->prev = temp;
            temp->prev = head;
            head->next = temp;
            if (size == 2)
            {
                mid = mid->next;
            }
            if (size % 2 == 1)
            {
                mid = mid->prev;
            }
            size++;
        }
        else if (com == "push_middle")
        {
            node *temp = new node;
            temp->e = arg;
            (mid->next)->prev = temp;
            temp->next = mid->next;
            mid->next = temp;
            temp->prev = mid;
            if (size % 2 == 0)
            {
                mid = mid->next;
            }
            size++;
        }
        else if (com == "push_back")
        {
            node *temp = new node;
            temp->e = arg;
            temp->prev = tail->prev;
            (tail->prev)->next = temp;
            temp->next = tail;
            tail->prev = temp;
            if (size % 2 == 0)
            {
                mid = mid->next;
            }
            size++;
        }
        else if (com == "get")
        {
            node *pter = head->next;
            for (int i = 0; i < arg; i++)
            {
                pter = pter->next;
            }
            cout << pter->e << "\n";
        }
    }
    return 0;
}