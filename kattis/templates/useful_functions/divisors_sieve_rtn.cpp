
vector<int> dvsrs(int n)
{
    vector<int> factors;
    factors.push_back(1);
    // Print the number of 2s that divide n
    // one element (Note i = i +2)
    for (int i = 2; i <= sqrt(n); i++)
    {
        // While i divides n, print i and divide n
        if (n % i == 0)
        {
            factors.push_back(i);
            factors.push_back(n/i);
        }
    }
    return factors;
}
//template ends