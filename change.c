/*
*   Author: Reza Jafar
*   Filename: main.cpp
*****************************************************************************
Write a program that tells what coins to give for any amount of change from 1
cent to 99 cents. For example, if the amount is 86 cents, the output would be
something like the following:

86 cents can be given as 
3 quarter(s) 1 dime(s) and 1 penny(pennies)

Use coin denominations of 25 cents (quarters), 10 cents (dimes), and 1 cent
(pennies). Do not use nickel and half-dollar coins. Your program will use the
following function (among others):

void compute_coins(int coin_value, int& num, int& amount_left);
//Precondition: 0 < coin_value < 100; 0 <= amount_left < 100.
//Postcondition: num has been set equal to the maximum number
//of coins of denomination coin_value cents that can be obtained
//from amount_left. Additionally, amount_left has been decreased
//by the value of the coins, that is, decreased by
//num * coin_value.

For example, suppose the value of the variable amount_left is 86. Then, after
the following call, the value of num will be 3 and the value of amount_left
will be 11 (because if you take 3 quarters from 86 cents, that leaves 11
cents):

compute_coins(25, num, amount_left)
(Hint: Use integer division and the % operator to implement this function.)


Include a loop that lets the user repeats this computation for new input values
until the user says he or she wants to end the program.
*******************************************************************************/

#include <iostream>


using namespace std;

const int QUARTER = 25;
const int DIME = 10;
const int PENNY = 1;

int quarterCount = 0;
int dimeCount = 0;
int pennyCount = 0;
int initialChange;
int coin_value, num, amountLeft;


void compute_coins(int coin_value, int& num, int& amount_left);

int main() 
{
    char answer;
    do 
    {
        //Get change from user between 0 - 100
        do
        {
        cout << "Enter change amount (between 1 - 99): ";
        cin >> initialChange;
        } while (initialChange< 1 || initialChange>= 100);

        //Function call
        compute_coins(QUARTER, num , initialChange);

        cout << "Would you like to enter more change? (y or Y = yes)" << endl;
        cin >> answer;

    } while (answer == 'y' || answer == 'Y');

    return 0;
}

void compute_coins(int coin_value, int& num, int& amount_left)
{
    //Calculate how many quarters can go into initial change amount
    num = initialChange / coin_value;
    amountLeft = initialChange - coin_value * num;

    //Calculate Dimes
    dimeCount = amountLeft / DIME;
    amountLeft = amountLeft % DIME;

    //Print how the change can be given
    cout << initialChange << " cents can be given as" << endl;
    cout << num << " quarter(s) " << dimeCount << " dime(s) " << amountLeft << " penny(pennies)" << endl;
}
