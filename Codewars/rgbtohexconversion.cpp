// RGB to hex conversion
class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b)
  {
    return convertToHex(r) + convertToHex(g) + convertToHex(b);
  }
  
  static inline std::string convertToHex(int number)
  {
    if (number <= 0) return "00";
    else if (number >= 255) return "FF";
    std::string out;
    if (number >= 160) out = char(55 + number / 16);
    else out = char(48 + number / 16);
    int second = number % 16;
    if (second >= 10) return out + char(55 + second);
    return out + char(48 + second);
  }
};