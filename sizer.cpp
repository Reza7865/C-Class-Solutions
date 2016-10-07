
/* Author: Reza Jafar
*  Filename: main.cpp
*  Description:     
*
*  Write a program that asks for the user’s height, weight, and age, and then computes clothing sizes according to the formulas;
*
*   a) Hat size = weight in pounds divided by height in inches and all that multiplied by 2.9
*
*   b) Jacket size (chest in inches) = height times weight divided by 288 and then adjusted by adding 1/8 of an inch for each 10 years over age 30.
*      (Note that the adjustment only takes place after a full 10 years. So, there is no adjustment for ages 30 through 39, but 1/8 of an inch is added for age 40.)
*
*   c) Waist in inches = weight divided by 5.7 and then adjusted by adding 1/10 of an inch for each 2 years over age 28. 
*      (Note that the adjustment only takes place after a full 2 years. So, there is no adjustment for age 29, but 1/10 of an inch is added for age 30.
*
*   Use functions for each calculation. Your program should allow the user to repeat this calculation as often as the user wishes.
*    
*/


#include <iostream>
#include <math.h>

using namespace std;

float hatSize(float, float);
float jacketSize(float, float, int);
float waistSize(float, int);

int main()
{
     char answer;
     do {
    float height, weight;
    int age;

    cout << "Give me your height in inches, weight in pounds, and age in years and I will give you your hat size, jacket size (inches at chest) and your waist size in inches." << endl;
    cout << "Enter height in inches: ";
    cin >> height;

    cout << "Enter weight in lbs: ";
    cin >> weight;
                                                                                                         1,5           Top
    cout << "Enter age: ";
    cin >> age;

    float h = hatSize(weight, height);
    cout << endl << "Hat size = " << roundf(h * 100) / 100 << endl;

    float j = jacketSize(height, weight, age);
    cout << "Jacket size = " << roundf(j * 100) / 100<< endl;

    float w = waistSize(weight, age);
    cout << "Waist size = " << roundf(w * 100) / 100 << endl;

    cout << endl << "enter Y or y to repeat, any other character ends: ";
    cin >> answer;

     } while (answer == 'Y' || answer == 'y');
}

float hatSize(float weight, float height)
{
    return weight / height * 2.9;
}

float jacketSize(float height, float weight, int age)
{
    if (age < 30) {
         return height * weight / 288;
         } else {
         return height * weight / 288 + ((age - 30) / 10) * .125;
         }
}

float waistSize(float weight, int age)
{
    if (age < 28) {
        return weight / 5.7;
    } else {
        return weight / 5.7 + ((age - 28) / 2) * .10;
    }
}
