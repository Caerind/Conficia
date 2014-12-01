#ifndef TME_PARSERUTILS_HPP
#define TME_PARSERUTILS_HPP

#include <cstring>
#include <string>
#include <sstream>
#include <vector>

#include <zlib.h>

namespace tme
{

class ParserUtils
{
    public:
        static bool base64_encode(std::string& data);
        static bool base64_decode(std::string& data);
        static bool decompressString(std::string& data);
        static bool compressString(std::string& data);

    private:
        static const std::string base64_table;

        static inline bool is_valid_base64(unsigned char c)
        {
            return (isalnum(c) || (c == '+') || (c == '/'));
        }
};

} // namespace tme

#endif // TME_PARSERUTILS_HPP
