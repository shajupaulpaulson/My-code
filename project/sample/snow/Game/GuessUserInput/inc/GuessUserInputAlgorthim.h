// License : No Information
//
//
//
// Author: Shajupaul Paulson
#ifndef GAME_GUESSUSERINPUT_GUESSUSERINPUTALGORTHIM_H
#define GAME_GUESSUSERINPUT_GUESSUSERINPUTALGORTHIM_H

#include <string>
#include <map>
#include <iostream>

namespace GuessUserInput{
  namespace guessuserinputalgorthim{
//Class GuessUserInputAlgorthim will perform the algorthim to
//match with random sequence generated it alsom maintains keypostion
//added by user
  class GuessUserInputAlgorthim{
  public:
    GuessUserInputAlgorthim();
    ~GuessUserInputAlgorthim();

    static GuessUserInputAlgorthim* getInstance();
    void updateSeqence(const std::string &seq);
    bool checkKeycombination(const int &key);
    void initallize(std::map<int, char> & temp);

  private:
    inline void updatekey(){ (keyposition<2)?keyposition++:keyposition=0 ;};
    bool keyPos0(char &key)const;
    bool keyPos1(char &key)const;
    bool keyPos2(char &key)const;
    void printRed()const{std::cout << "\033[1;41m \033[0m" << std::flush;};
    void printOrange()const{std::cout << "\033[1;48:2:255:165:0m \033[0m" << std::flush;};
    void printGreen()const{std::cout << "\033[1;42m \033[0m" << std::flush;};

    static GuessUserInputAlgorthim* m_guessuserinputalgorthim;
    std::map<int,char> m_charMap;
    std::string currentGameSequence;
    int keyposition;
    bool bPosA, bPosB, bPosC;

  };

  }

}









#endif
