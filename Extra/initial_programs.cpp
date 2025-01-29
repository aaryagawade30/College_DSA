#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    int cnt = 0;
    for (int i = 2; i <= (n / 2); i++)
    {
        if (n % i == 0)
        {
            cnt += 1;
            break;
        }
    }
    if (cnt == 1)
        return false;

    else
        return true;
}

bool num_palindrome(int n)
{
    int orig_n = n, last_dig, rev_num = 0;
    while (n != 0)
    {
        last_dig = n % 10;
        n = n / 10;
        rev_num = rev_num * 10 + last_dig;
    }

    cout << rev_num << endl;
    if (rev_num == orig_n)
        return true;
    else
        return false;
}

// learn what is happening in first if.
bool rev_s(int i, string &s)
{
    if (i >= s.size() / 2)
        return true;
    if (s[i] != s[s.size() - i - 1])
        return false;
    return rev_s(i + 1, s);
}

void cnt_dig(int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
}

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int sqrRt(int n)
{
    return sqrt(n);
}

void swapWoTemp(int x, int y)
{
    x = x + y;
    y = x - y;
    x = x - y;
    cout << "x = " << x << " y = " << y;
}

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

void star_pyr(int n)
{
    for (int i = 0; i <= n; i++)
    {
        // spaces
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j <= i - 1; j++)
        {
            cout << "* ";
        }

        for (int j = 0; j <= 4 - i - 1; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

void num_recur(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void num_norec(int n)
{
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << start << " ";
            start++;
        }
        cout << endl;
    }
}

int main()
{
    cout << is_prime(7) << endl;
    cout << num_palindrome(121);
    string s = "madam";
    cout << rev_s(0, s);
    //cout<< cnt_dig(1212);
    for( int i = 0; i < 4; i++){
        cout << fib(i)<<" ";
        cout << fact(i)<<" ";
    }
    

    star_pyr(5);
    num_norec(4);
    cout << sqrRt(4);
    swapWoTemp(3, 4);

    
    int sum = 0;
    int n = 7;
    for(int i = 2; i <= n; i++) {
        if(is_prime(i) == 1) sum += i;
    }
    cout << sum;
    return 0;
}