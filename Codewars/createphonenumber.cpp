//createphonenumber

#include <string>

std::string createPhoneNumber(const int arr [10]){
  std::string format {"(xxx) xxx-xxxx"};
  std::string phonenumber {""};
  int x_counter = 0;
  int format_len = format.length(); 
  for (int i = 0; i < format_len; ++i){
    phonenumber = format[i] == 'x'
      ? (phonenumber += arr[x_counter++] + '0')
      : (phonenumber += format[i]); 
  }
  return phonenumber; 
}