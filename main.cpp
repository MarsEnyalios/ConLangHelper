/*****************************************************************************
 * Program: Constructed Language Helper v 0.3.1 - GNU 3.0 License
 * @author M. Burkett
 *
 * Purpose: This is a tool for constructing languages from scratch. The
 *          default values are most of the phonetic sounds used in English and
 *          basic syllable structures. The user can change the consonants,
 *          vowels, and syllables structures at will.
 *
 *          From these basic language blocks, the program can generate roots,
 *          from which a conlanger can make the lexicon of a constructed
 *          language.
 *
 * == Notes ==================================================================
 *
 * -- New in 0.3.1 -----------------------------------------------------------
 *
 *      - Language object
 *      - ability to alter values of alphabet and syllables
 *      - use of "using std::<keyword>" instead of "using namespace std" for
 *        future compatibility
 *      - ability to import and export language files
 *      - Pretty commenting!!
 *
 * -- Goals ------------------------------------------------------------------
 *
 *      - have a user defined delimiter for parsing (if no spaces)
 *      - thorough error checking (currently volatile)
 *      - IPA to Englishy sound conversion
 *      - IPA Symbols default
 *      - select roots to save to an array and/or class
 *      - export saved roots to text file
 *      - randomly? assign meanings to roots
 *      - save roots and associated meanings to text file
 *      - create a word generator from roots
 *      - save words & meanings to an array/class
 *      - export saved words & meanings to text file
 *      - edit words & meanings in lexicon
 *
 *  Currently do not have the skill for:
 *      - GUI implementation
 *
 *  Pipe dream?:
 *      - integrate zompist SCA2? Email Mark Rosenfelder about it
 *
 *****************************************************************************/

#include <iostream>
#include <random> // "random_device" is utterly useless. Found this online.
#include <fstream>
#include <sstream>

#include "randutils.hpp"
#include "language.h"

// instead of using namespace std ...
using std::cout; using std::cin; // iostream
using std::ifstream; using std::ofstream; // fstream
using std::endl;   // make my lines pretty pls
using std::string; // strings! are! useful!

// Seeds the random number generator
std::mt19937 gen{randutils::auto_seed_128{}.base()};

// Prototypes
void mainMenu(Language myLang);
void generateRoots(Language x);
int randGen(int x);
int parse(string x, string y[]);
Language loadLang();
void saveLang(Language x);
void getFileName(string & filename);

/**** int main ***************************************************************
 * Purpose: store important variables, drive program
 *****************************************************************************/
int main()
{
    int choice = 0;

    cout << "Welcome to Root Generator 0.3.1!\n" << endl
         << "\t1. Load Project" << endl
         << "\t2. Default Values" << endl

         << "You choose: ";

    cin >> choice;
    cin.clear();
    cin.ignore(100, '\n');

    cout << endl;

    if (choice == 1)
    {
        Language myLang = loadLang();
        mainMenu(myLang);
    }
    else
    {
        Language myLang;
        mainMenu(myLang);
    }

    return 0;
}

/**** void mainMenu **********************************************************
 * Purpose: Display program options to the user.
 * Parameters: Language myLang - contains alphabet and syllable types
 * Input: - int choice (user defined)
 */
void mainMenu(Language myLang)
{
    int choice;

    do {
        cout << "MAIN MENU \n\t1. Generate Roots" << endl
             << "\t2. View Alphabet & Syllables" << endl
             << "\t3. Change Something" << endl
             << "\t4. Save Project" << endl
             << "\t5. Exit\n" << endl

             << "You choose: ";
        cin >> choice;

        cin.clear();
        cin.ignore(100, '\n');

        if (choice == 1)
            generateRoots(myLang);
        else if (choice == 2)
            myLang.display();
        else if (choice == 3)
            myLang.changeStuff();
        else if (choice == 4)
            saveLang(myLang);
        else if (choice == 5)
            return;
        else
        {
            cout << "Not an option! Try again, punk." << endl;
        }
    } while (!isdigit(choice) || choice > 5 || choice < 1 );

        return;
}

// ************************************************************************ //
// * Generate Roots
// ************************************************************************ //

/**** void generateRoots *****************************************************
 * Purpose: Display a selected amount of lines of randomly generated roots
 * Parameters: - Language x
 *             - string cons[] & string vows[]
 *             - char sylls[]
 * Input: - int amount (user defined)
 * Processes: - assigns Language x cons, vows, & sylls to temp string
 *            - parses strings cons and vows by spaces and saves as arrays
 *            - parses string sylls character by character
 *            - generates roots from syll pattern types (c = cons, v = vows)
 */
void generateRoots(Language x)
{
    int plays = 0;    // How many times the user wants to run the gen
    string temp = ""; // holds the string to be parsed (cons, then vows)
    string syllables = x.getSylls();

    int consAmmo = 0;
    int vowsAmmo = 0;

    string cons[500]; // Array of cons
    string vows[500]; // Array of vows
    int sel = 0;      // selector for cons & vows (set equal to randGen)

    // Parse cons & vows //
    temp = x.getCons();
    consAmmo = parse(temp, cons) - 1;

    temp = x.getVows();
    vowsAmmo = parse(temp, vows) - 1;

    // How long's the loop? //
    cout << "\nHow many to run?: ";
    cin >> plays;


    // Let's gennnNNERRRATE //
    for (int j = 0; j < plays; j++)
    {
        cout << "\t";

        for (unsigned i = 0; i < syllables.length(); i++)
        {
            if (syllables.at(i) == 'c')
            {
                sel = randGen(consAmmo);
                cout << cons[sel];
            }
            else if (syllables.at(i) == 'v')
            {
                sel = randGen(vowsAmmo);
                cout << vows[sel];
            }
            else
                cout << syllables.at(i);
        }

        cout << endl;
    }

    cout << endl;
}

/**== int randGen ============================================================
 * Purpose: Generates a random number between 0 and the upper limit
 * Parameters: int x - the upper limit
 * Output: returns resulting random number
 */
int randGen(int x)
{
    std::uniform_int_distribution<> rand{0, x};

    return rand(gen);
}

/**== int parse ==============================================================
 * Purpose: Separates a string by spaces
 * Parameters: - string x
 *             - string line[]
 * Output: - changes line[] (saves parsed strings to line[])
 *         - returns int ammo (how many strings are in line[])
 */
int parse(string x, string y[])
{
    int ammo = 0;

    std::string segment;
    std::stringstream ssin(x);

    while(std::getline(ssin, segment, ' '))
    {
       y[ammo] = segment;
       ammo++;
    }

    return (ammo - 1); /// I was getting an occasional blank output in the gen
                       /// -1 fixed it
}

// ************************************************************************ //
// * Import/Export
// ************************************************************************ //

/**== Language loadLang ======================================================
 * Purpose: imports a Language from a 3-line text file (cons, vows, sylls).
 * Output: sets beginning Language to file input
 */
Language loadLang()
{
    string filename;
    string cons;
    string vows;
    string sylls;
    Language x;

    ifstream fin;

    getFileName(filename);

    fin.open(filename.c_str());

    if (fin.is_open())
    {
        while (isalnum(fin.peek()))
        {
            getline(fin, cons);
            getline(fin, vows);
            getline(fin, sylls);
        }
    }
    fin.close();

    x.setCons(cons);
    x.setVows(vows);
    x.setSylls(sylls);

    return x;
}

/**== void saveLang ==========================================================
 * Purpose: exports myLang to a text file.
 * Parameters: - Language myLang
 * Output: <myLang>.txt (three lines: cons, vows, sylls)
 */
void saveLang(Language x)
{
    string filename;
    string cons = x.getCons();
    string vows = x.getVows();
    string sylls = x.getSylls();

    ofstream fout;

    getFileName(filename);

    fout.open(filename.c_str());

    if (fout.is_open())
    {
        fout << cons << endl
             << vows << endl
             << sylls << endl;
    }
    fout.close();
}

/**-- void getFileName -------------------------------------------------------
 * Purpose: Get the path to a text file.
 * Parameters: string & filename - path to file
 * Input: - string file (user defined)
 * Output: - returns user-inputted path
 */
void getFileName(string & filename)
{
    cout << "Enter the file name without type: ";
    cin >> filename;
    cin.clear();
    cin.ignore(100, '\n');

    filename.append("txt");
}
