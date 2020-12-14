// 1-800-code-war

std::set<std::string> check1800(const std::string &str)
{
  std::set<std::string> _result;
  
  //initialize phone digits
  std::vector<std::string> _digits{"0", "0"};    
  _digits.push_back("ABC");
  _digits.push_back("DEF");
  _digits.push_back("GHI");
  _digits.push_back("JKL");
  _digits.push_back("MNO");
  _digits.push_back("PQRS");
  _digits.push_back("TUV");
  _digits.push_back("WXYZ");
  
  //get phone number in chrs
  std::string _code = str.substr(6,str.length() );
  size_t pos = _code.find("-");
  _code.erase(pos,1);  
  
  //get first and last 3-4 numbers combination
  std::vector<int> firstThreeCode;  
  std::vector<int> firstFourCode;  
  std::vector<int> lastFourCode;  
  std::vector<int> lastThreeCode; 
  
  size_t count = 0;
  for(char elem : _code)
  { 
    for(size_t i = 2; i < _digits.size(); ++i)
    {
        if(_digits[i].find(elem) != std::string::npos)
        {
            count++;
            if(count < 4)
            {
              firstThreeCode.push_back(i);
              firstFourCode.push_back(i);
            }
            else if(count == 4)
            {
              firstFourCode.push_back(i);
              lastFourCode.push_back(i);
            }
            else if(count > 4)
            {
              lastFourCode.push_back(i);
              lastThreeCode.push_back(i);
            }          
            break;
        }        
     }
  }

  std::vector<std::string> goodFirstWords;
  std::vector<std::string> goodSecondWords;

  //get accepted words from given set
  for(std::string goodWord : preloaded::words)
  {
    //check 3-letter words
    if(  goodWord.length() == 3  )
    {
      if( _digits[ firstThreeCode[0] ].find(goodWord[0]) != std::string::npos &&
          _digits[ firstThreeCode[1] ].find(goodWord[1]) != std::string::npos &&
          _digits[ firstThreeCode[2] ].find(goodWord[2]) != std::string::npos   )
      {
        goodFirstWords.push_back(goodWord);
      }
      
      if( _digits[ lastThreeCode[0] ].find(goodWord[0]) != std::string::npos &&
          _digits[ lastThreeCode[1] ].find(goodWord[1]) != std::string::npos &&
          _digits[ lastThreeCode[2] ].find(goodWord[2]) != std::string::npos   )
      {
        goodSecondWords.push_back(goodWord);
      }
      
     }
   //check 4-letter words
   else
   {    
      if(  _digits[ firstFourCode[0] ].find(goodWord[0]) != std::string::npos &&
           _digits[ firstFourCode[1] ].find(goodWord[1]) != std::string::npos &&
           _digits[ firstFourCode[2] ].find(goodWord[2]) != std::string::npos &&
           _digits[ firstFourCode[3] ].find(goodWord[3]) != std::string::npos   )
      {
        goodFirstWords.push_back(goodWord);
      }
      
      if(  _digits[ lastFourCode[0] ].find(goodWord[0]) != std::string::npos &&
           _digits[ lastFourCode[1] ].find(goodWord[1]) != std::string::npos &&
           _digits[ lastFourCode[2] ].find(goodWord[2]) != std::string::npos &&
           _digits[ lastFourCode[3] ].find(goodWord[3]) != std::string::npos   )
      {
        goodSecondWords.push_back(goodWord);
      }
  
    }
    
  }
 
  //check words combination and add them to the set
  for(std::string fWord : goodFirstWords)
  {
    for(std::string sWord : goodSecondWords)
    {
      if(fWord.length() + sWord.length() == 7)
      {
        std::string res = "1-800-" + fWord + "-" + sWord;
        _result.insert(res);
      }
    }
  }
  
  return _result;    
}