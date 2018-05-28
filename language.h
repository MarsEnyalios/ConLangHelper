/*****************************************************************************
 * File: language.h
 * @author M. Burkett
 *****************************************************************************/

#ifndef LANGUAGE_INCLUDED
#define LANGUAGE_INCLUDED

/**== class Language =========================================================
 * Purpose: Holds an alphabet and syllable types
 */
class Language {
    // Private vars //
    std::string consonants;
    std::string vowels;
    std::string syllables;
    int consAmmo;
    int vowsAmmo;
public:
    // Constructors //
    Language();
    Language(std::string, std::string, std::string);

    // Accessors //
    std::string getCons() const;
    std::string getVows() const;
    std::string getSylls() const;

    // Mutators //
    void setCons(std::string x);
    void setVows(std::string x);
    void setSylls(std::string x);

    // Displays and Prompts //
    void display() const;
    void changeStuff();
    void setPrompt(std::string x);
};



#endif // LANGUAGE_H_INCLUDED
