/*****************************************************************************
 * File: language.cpp
 * @author M. Burkett
 * Purpose: contains the method bodies for the Language class (language.h)
 *****************************************************************************/

#include <iostream>
#include <sstream>
#include "language.h"

using std::cout; using std::cin;
using std::endl; using std::string;

// ************************************************************************ //
// Constructors
// ************************************************************************ //

/**== Language :: Language ===================================================
 * Purpose: Default constructor for Language class
 * Output: assigns values to all private variables
 */
Language :: Language()
{
    consonants = "b c cH d f g h j k l m n nG p q r s sH t tH TH v w x z zH";
    vowels = "ay aa ee eh i iH oH aH u uH uH! oo aw oi ow ew ar or ur air";
    syllables = "cv vc cvc cvcc vcvv";
}

/**-- Language :: Language ---------------------------------------------------
 * Purpose: Parameterized constructor for Language class - used in loadLang()
 * Parameters: three strings
 * Output: assigns values to all private variables
 */
Language :: Language(string x, string y, string z)
{
    consonants = x;
    vowels = y;
    syllables = z;
}

// ************************************************************************ //
// Getters
// ************************************************************************ //

/**-- Language :: string getCons ---------------------------------------------
 * Purpose & output: Accesses and returns value of private consonant string
 */
string Language :: getCons() const
{
    return consonants;
}

/**-- Language :: string getVows ---------------------------------------------
 * Purpose & output: Accesses and returns value of vowels
 */
string Language :: getVows() const
{
    return vowels;
}

/**-- Language :: string getSylls --------------------------------------------
 * Purpose & output: Accesses and returns value of syllables
 */
string Language :: getSylls() const
{
    return syllables;
}

// ************************************************************************ //
// Setters
// ************************************************************************ //

/**-- Language :: void setCons -----------------------------------------------
 * Purpose: Mutator for consonants.
 * Parameters: string x - a string of consonants
 * Output: changes the consonants
 */
void Language :: setCons(string x)
{
    consonants = x;
}

/**-- Language :: void setVows -----------------------------------------------
 * Purpose: Mutator for vowels.
 * Parameters: string x - a string of vowels
 * Output: changes the vowels
 */
void Language :: setVows(string x)
{
    vowels = x;
}

/**-- Language :: void setSylls ----------------------------------------------
 * Purpose: Mutator for syllables
 * Parameters: string x - a string of syllable types
 * Output: changes the syllable string
 */
void Language :: setSylls(string x)
{
    syllables = x;
}

// ************************************************************************ //
// Displays & Prompts
// ************************************************************************ //

/**** Language :: void display ***********************************************
 * Purpose: Display consonants, vowels, and syllables
 */
void Language :: display() const
{
    cout << "\nC: " << consonants << endl
         << "V: " << vowels << endl
         << "S: " << syllables << endl << endl;
}

/**** Language :: void changeStuff *******************************************
 * Purpose: Prompt the user for alphabet or syllable changes
 */
void Language :: changeStuff()
{
    int choice = 0;

    do {
        cout << "\n\t1. Change All" << endl
             << "\t2. Change Cons & Vows" << endl
             << "\t3. Change Cons" << endl
             << "\t4. Change Vows" << endl
             << "\t5. Change Sylls" << endl
             << "\t6. Main Menu" << endl

             << "You choose: ";
        cin >> choice;
        cin.clear();
        cin.ignore(100, '\n');

        if (choice == 1)
        {
            setPrompt("consonants");
            setPrompt("vowels");
            setPrompt("syllables");
        }
        else if (choice == 2)
        {
            setPrompt("consonants");
            setPrompt("vowels");
        }
        else if (choice == 3)
            setPrompt("consonants");
        else if (choice == 4)
            setPrompt("vowels");
        else if (choice == 5)
            setPrompt("syllables");
        else if (choice == 6)
            return;
        else
        {
            cout << "Not an option! Try again, punk." << endl;
        }
    } while (!isdigit(choice) || choice > 5 || choice < 1 );
}

/**== Language :: void setPrompt =============================================
 * Purpose: change either consonants, vowels, or syllables
 * Parameters: string x - either "consonants", "vowels", or "syllables"
 * Input: - user defines the string to use
 */
void Language :: setPrompt(string x)
{
    string temp = "";
    char choice = ' ';

    cout << "Enter " << x << " (separate by spaces): ";
    getline(cin, temp);

    cout << "Are you sure you want to change the " << x << " to: "
         << temp << "? (y/n)";

    cin >> choice;
    cin.clear();
    cin.ignore(100, '\n');

    if (choice == 'y' || choice == 'Y')
    {
        if (x == "consonants")
            setCons(temp);
        else if (x == "vowels")
            setVows(temp);
        else if (x == "syllables")
            setSylls(temp);
        else
            cout << "\nThis isn't supposed to happen D:" << endl;

        return;
    }
    else
        return;

    return;
}
