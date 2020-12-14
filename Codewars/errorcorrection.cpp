//error correction

#include <string>

int triple_bits(int byte)
{
    int result = 0;
    for (int i = 0; i < 8; ++i) {
        int bit = byte & 1;
        result |= ((bit * 7) << (i * 3));
        byte >>= 1;
    }
    return result;
}

const std::string s01[] = { "0", "1" };

std::string to_bits(int int24)
{
    std::string result;
    result.reserve(24);
    for (int i = 23; i >= 0; --i) {
        result += s01[(int24 >> i) & 1];
    }
    return result;
}

int from_bits(std::string bits)
{
    int result = 0;
    for (char c : bits) {
        result = (result << 1) | (c == '1');
    }
    return result;
}

int from_24_bits(int int24)
{
    static int bit8[8] { 0, 0, 0, 1, 0, 1, 1, 1 };
    int result = 0;
    for (int i = 21; i >= 0; i -= 3) {
        int triple = (int24 >> i) & 7;
        int bit = bit8[triple];
        result = (result << 1) | bit;
    }
    return result;
}

std::string encode(std::string text)
{
    std::string bits;
    bits.reserve(text.size() * 24);
    for (char c : text) {
        int triple = triple_bits(c);
        bits += to_bits(triple);
    }
    return bits;
}

std::string decode(std::string bits)
{
    std::string text;
    text.reserve(bits.size() / 24);
    for (std::size_t i = 0, n = bits.size(); i < n; i += 24) {
        int int24 = from_bits(bits.substr(i, 24));
        int c = from_24_bits(int24);
        text += char(c);
    }
    return text;
}

