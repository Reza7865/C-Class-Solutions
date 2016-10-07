/* Filename: main.cpp
*  Author: Reza Jafar
*
*  Description: You have invented a vending machine capable of deep frying
*  twinkies. Write a program to simulate the vending machine. It costs $3.50 to
*  buy a deep-fried twinkie, and the machine only takes coins in denominations
*  of a dollar, quarter, dime, or nickel. Write code to simulate a person
*  putting money into the vending machine by repeatedly prompting the user for
*  the next coin to be inserted. Output the total entered so far when each coin
*  is inserted. When $3.50 or more is added, the program should output “Enjoy
*  your deep-fried twinkie” along with any change that should be returned. Use
*  top-down design to determine appropriate functions for the program. 
*    
*/

#include <iostream>

using namespace std;


const int DOLLAR = 100, QUARTER = 25,DIME = 10 ,NICKEL = 5;
const int TWINKIE_PRICE = 350;

void prompt_next_coin();
bool is_valid(int);


int main()
{
    prompt_next_coin();
    return 0;
}

void prompt_next_coin()
{
    int coin, total;

    //Keep prompting user for next coin
    //Keep count of total coins
    do  
    {   
        cout << "Enter the next coin (100 = dollar, 25 = quarter, 10 = dime, 5 = nickel): ";
        cin >> coin;
        
        if(is_valid(coin))
        {
            total += coin;
            cout << "Total added: " << total << " cents" << endl;
        }
        else
        {
            cout << "Invalid entry, try again" << endl;
        }
    } while (total < TWINKIE_PRICE);

    cout << "Enjoy you twinkie" << endl;

    if (total > TWINKIE_PRICE)
    {
        cout << "Your change is: " << total - TWINKIE_PRICE << " cents" << endl;
    }
}

bool is_valid(int i)
{
    if (i == DOLLAR || i == QUARTER || i == DIME || i == NICKEL)
        return true;
    else
        return false;
}
                                                                                                                                                     70,1          Bot
