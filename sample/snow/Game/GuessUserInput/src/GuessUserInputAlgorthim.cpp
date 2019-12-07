// License : No Information
//
//
//
// Author: Shajupaul Paulson
#include "inc/GuessUserInputAlgorthim.h"

namespace GuessUserInput{
  namespace guessuserinputalgorthim {

//Constructor we set the keyposition to 0
//and all position guesses as false
    GuessUserInputAlgorthim* GuessUserInputAlgorthim::m_guessuserinputalgorthim= NULL;
    GuessUserInputAlgorthim::GuessUserInputAlgorthim()
    {
      keyposition=0;
      bPosA=false;
      bPosB=false;
      bPosC=false;
    }

//Destructor of the class kept open as it is a pointer for deletion in future
    GuessUserInputAlgorthim::~GuessUserInputAlgorthim()
    {

    }

//getInstance creates a class pointer. This is a static instance
//ensure only one instance of game algorthim is created
//this is to ensure that two class Game ang GuessUserInputMessagereceive
//are calling the same class for keyposition to be maintained
    GuessUserInputAlgorthim* GuessUserInputAlgorthim::getInstance()
    {
      if(m_guessuserinputalgorthim == NULL)
      {
        m_guessuserinputalgorthim=new(GuessUserInputAlgorthim);
      }
      return (m_guessuserinputalgorthim);

    }

//updates the map with keycode to char for further algorthin
    void GuessUserInputAlgorthim::initallize(std::map<int, char> & temp){
      m_charMap=temp;
    }

//New sequence from RandomGen is stored here
//and all pos is set as false
//keyposition intentioannly not set as zero is been set by keyposition counter
    void GuessUserInputAlgorthim::updateSeqence(const std::string &seq)
    {
        currentGameSequence=seq;
        bPosA=false;
        bPosB=false;
        bPosC=false;
    }

//This algorthim is to check for input when the keyposition is at 0
//It will print green if position matches
//It will print orange if available in other position
//It will print red if not found
//TODO:highly optimized for the current problem. Generic solution possible
//with string operation but it would be costly for the embedded system
    bool GuessUserInputAlgorthim::keyPos0(char &key)const{
        if( key == currentGameSequence[0]){
          printGreen();
          return true;
        }
        else if ( key == currentGameSequence[1] ||
                  key == currentGameSequence[2]     ){
          printOrange();
        }
        else
        {
          printRed();
        }
        return false;
    }

//This algorthim is to check for input when the keyposition is at 1
//It will print green if position matches
//It will print orange if available in other position
//It will print red if not found
//TODO:highly optimized for the current problem. Generic solution possible
//with string operation but it would be costly for the embedded system
    bool GuessUserInputAlgorthim::keyPos1(char &key)const{
      if( key == currentGameSequence[1]){
        printGreen();
        return true;
      }
      else if ( key == currentGameSequence[0] ||  key == currentGameSequence[2] ){
        printOrange();
      }
      else
      {
        printRed();
      }
      return false;
    }

//This algorthim is to check for input when the keyposition is at 2
//It will print green if position matches
//It will print orange if available in other position
//It will print red if not found
//TODO:highly optimized for the current problem. Generic solution possible
//with string operation but it would be costly for the embedded system
    bool GuessUserInputAlgorthim::keyPos2(char &key)const{
      if( key == currentGameSequence[2]){
        printGreen();
        return true;
      }
      else if ( key == currentGameSequence[0] ||  key == currentGameSequence[2] ){
        printOrange();
      }
      else
      {
        printRed();
      }
      return false;
    }

//The function is called when a keyinput is recieved
//It would take the key and based on keyposition call an algorthim needed
//Needs to be optimized for generic function
    bool GuessUserInputAlgorthim::checkKeycombination(const int& keycode)
    {
        char key=m_charMap[keycode];
        switch (keyposition){
          case 0:
          {
            bPosA=keyPos0(key);
            break;
          }
          case 1:
          {
            bPosB=keyPos1(key);
            break;
          }
          case 2:
          {
            bPosC=keyPos2(key);
            break;
          }
          default :
             std::cout << "Something wrong" << std::endl;
        }
        updatekey();
        if(bPosA && bPosB && bPosC ){
          std::cout << "   Combination judged correctly " <<currentGameSequence << std::endl;
          return true;
        }
        if(keyposition == 0){
          std::cout << std::endl;
          bPosA=false;
          bPosB=false;
          bPosC=false;
        }
        return false;
    }

  }//namespace guessuserinputalgorthim
}//namespace GuessUserInput
