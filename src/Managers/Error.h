#pragma once

#include "../common_libraries.h"

namespace Manager
{
    class Error
    {
        private:

            Error() = default;
            ~Error() = default;

        public:

            enum errors
            {
                SUCCESS,

                // Main
                WRONG_USAGE,

                // FileManager
                FILE_NOT_FOUND,
                UNKNOWN_EXTENSION,

                // ObjectDestroyer
                NULL_OBJECT,
                OBJECT_ALREADY_REGISTERED,
                OBJECT_NOT_REGISTERED
            };

            [[nodiscard]] static std::string get_message(errors error);
            [[nodiscard]] static std::string get_description(errors error);
            [[nodiscard]] static std::string get_module(errors error);
    };
}