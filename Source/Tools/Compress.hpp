#ifndef CONFICIA_COMPRESS_HPP
#define CONFICIA_COMPRESS_HPP

#include <cstring>
#include <string>
#include <sstream>
#include <vector>

#include <zlib.h>

/// You need to add : "z" in your lib list or "-lz"

namespace cf
{

class Compress
{
    public:
        static bool uncompress(std::string& line);
        static bool compress(std::string& line);

    protected:
        static bool base64_encode(std::string& data);
        static bool base64_decode(std::string& data);

        static bool decompressString(std::string& data);
        static bool compressString(std::string& data);

        static const std::string base64_table;

        static inline bool is_valid_base64(unsigned char c)
        {
            return (isalnum(c) || (c == '+') || (c == '/'));
        }
};

}

#endif // CONFICIA_COMPRESS_HPP
