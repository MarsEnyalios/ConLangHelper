# ConLangHelper
A tool to help construct languages.

 Program: Constructed Language Helper v 0.3.1 - GNU 2.0 License
 @author M. Burkett
 
 Purpose: This is a tool for constructing languages from scratch. The
          default values are most of the phonetic sounds used in English and
          basic syllable structures. The user can change the consonants,
          vowels, and syllables structures at will.
          From these basic language blocks, the program can generate roots,
          from which a conlanger can make the lexicon of a constructed
          language.
 
 == Notes ==================================================================
 
 -- New in 0.3.1 -----------------------------------------------------------
 
      - Language object
      - ability to alter values of alphabet and syllables
      - use of "using std::<keyword>" instead of "using namespace std" for
        future compatibility
      - ability to import and export language files
      - Pretty commenting!!
 
 -- Goals ------------------------------------------------------------------
 
      - have a user defined delimiter for parsing (if no spaces)
      - thorough error checking (currently volatile)
      - IPA to Englishy sound conversion
      - IPA Symbols default
      - select roots to save to an array and/or class
      - export saved roots to text file
      - randomly? assign meanings to roots
      - save roots and associated meanings to text file
      - create a word generator from roots
      - save words & meanings to an array/class
      - export saved words & meanings to text file
      - edit words & meanings in lexicon
 
    Currently do not have the skill for:
      - GUI implementation
 
    Pipe dream?:
      - integrate zompist SCA2? Email Mark Rosenfelder about it
