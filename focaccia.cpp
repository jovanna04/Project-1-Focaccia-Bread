/**
 * focaccia.cpp
 *
 * EECS 183: Project 1, Fall 2022
 *
 * Jovanna Gallegos
 * jovanna@umich.edu
 *
 * Purchasing "the correct amount of ingredients to make focaccia bread for a party"
 *
 * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);



int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;
    
    // TODO: add your code below
/** "you need to make" statement and loaves section*/
    double loaves_before = 4;
    double loaves_needed = ceil(people / loaves_before);
    cout << "You need to make: " << loaves_needed
        << pluralize(" loaf", " loaves", loaves_needed) << " of focaccia"
        << endl << endl;
    
/** shopping list statement*/
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl << endl;
    
/** flour section*/
    const double FLOUR_CUPS_PER_LOAF = 5 / 1;
    const double FLOUR_CUPS_PER_BAG = 20 / 1;
    const double LOAVES_PER_FLOUR_BAG = FLOUR_CUPS_PER_BAG / FLOUR_CUPS_PER_LOAF;
    int flour_bags = ceil(loaves_needed / LOAVES_PER_FLOUR_BAG);
    cout << flour_bags << pluralize(" bag", " bags", flour_bags) << " of flour"
        << endl;
    
/** instant yeast section*/
    const double TSP_PER_LOAF = 1.75;
    const double TSP_PER_PACKAGE = 2.25;
    int yeast_packs = ceil((loaves_needed * TSP_PER_LOAF) / TSP_PER_PACKAGE);
    cout << yeast_packs << pluralize(" package", " packages", yeast_packs)
        << " of yeast" << endl;
    
/** salt section*/
    const double GRAMS_PER_LOAF = 15;
    const double GRAMS_PER_CAN = 48;
    int salt_cans = ceil((loaves_needed * GRAMS_PER_LOAF) / GRAMS_PER_CAN);
    cout << salt_cans << pluralize(" canister", " canisters", salt_cans) <<
        " of salt" << endl;
    
/** olive oil section */
    const double ML_PER_LOAF = 29.6;
    const double ML_PER_BOTTLE = 500;
    int olive_bottles = ceil((loaves_needed * ML_PER_LOAF) / ML_PER_BOTTLE);
    cout << olive_bottles << pluralize(" bottle", " bottles", olive_bottles) <<
        " of olive oil" << endl << endl;
    
/** total expected cost  section */
    double flour_cost = flour_bags * 2.69;
    double yeast_cost = yeast_packs * 0.40;
    double salt_cost = salt_cans * 0.49;
    double olive_oil_cost = olive_bottles * 6.39;
    double total_cost = flour_cost + yeast_cost + salt_cost + olive_oil_cost;
    cout << "Total expected cost of ingredients: $" << total_cost << endl << endl;
    
/** ending statement*/
    cout << "Have a great party!" << endl;
    
    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
