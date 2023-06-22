#include <bits/stdc++.h>
using namespace std;

/*
@ Problem
You are an owner of lemonade island, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by given array bills[]). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

NOTE: At first, you do not have any bill to provide changes with. You can provide changes from the bills that you get from the previous customers.

Given an integer array bills of size N where bills [ i ] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.



    The first customer must pay with a $5 bill. If the first customer does not pay $5, it immediately returns false since it is not possible to provide change without any starting bills.

    The code maintains three variables: fives, tens, and twenties, which represent the number of $5 bills, $10 bills, and $20 bills available, respectively.

    It iterates through the array of bills and performs the following checks for each bill:

        If the bill is $5, it increments the count of fives.

        If the bill is $10, it checks if there is at least one $5 bill available. If there is, it increments the count of tens and decrements the count of fives by one. Otherwise, it returns false since it cannot provide the correct change.

        If the bill is $20, it checks the availability of bills to provide the correct change. There are two cases to consider:

            If there is at least one $10 bill and one $5 bill available, it decrements the count of tens and fives by one each.

            If there are at least three $5 bills available, it decrements the count of fives by three.

            If none of the above conditions are satisfied, it returns false since it cannot provide the correct change.

    After processing all the bills, if it has reached this point without returning false, it means that it can provide the correct change for each customer, and it returns true.

The intuition behind this code is to keep track of the available bills and ensure that there are enough bills to provide the correct change. It prioritizes using $10 bills first when giving change for $20 bills, as using a $10 bill and a $5 bill is preferable to using three $5 bills.

EXAMPLE

Let's go through the example again using the provided input [5, 5, 10, 10, 20]:

Initially, fives = 0, tens = 0, twenties = 0.

    The first customer pays with a $5 bill. Increment fives by one.
        Current state: fives = 1, tens = 0, twenties = 0.

    The second customer pays with a $5 bill. Increment fives by one.
        Current state: fives = 2, tens = 0, twenties = 0.

    The third customer pays with a $10 bill. Check if there is at least one $5 bill available. Decrement fives by one and increment tens by one.
        Current state: fives = 1, tens = 1, twenties = 0.

    The fourth customer pays with a $10 bill. Check if there is at least one $5 bill available. Decrement fives by one and increment tens by one.
        Current state: fives = 0, tens = 2, twenties = 0.

    The fifth customer pays with a $20 bill. Check if there is at least one $10 bill and one $5 bill available. Since there are two $10 bills and no $5 bills available, the code cannot provide the correct change and should return false.

Therefore, for the given example [5, 5, 10, 10, 20], the output will be false.

 */

bool lemonadeChange(int N, vector<int> &bills)
{
    if (bills.front() != 5)
        return false;
    // code here
    int fives = 0;
    int tens = 0;
    int twenties = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            fives++;
        }
        else if (bills[i] == 10)
        {
            if (fives > 0)
            {
                tens++;
                fives--;
            }
            else
                return false;
        }
        else
        {
            twenties++;
            if (fives < 1)
                return false;
            if (tens < 1 and fives < 3)
                return false;
            if (tens > 0 and fives > 0)
                tens--, fives--;
            else
                fives -= 3;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{

    return 0;
}
