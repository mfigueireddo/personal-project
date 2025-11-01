#pragma once

#include "../common_libraries.h"

namespace Manager
{
    class Log
    {
        private:

            Log() = default;

        public:

            static Log* create();
            ~Log() = default;

            // -- --- File management --- ---

            static int open_error_manager();
            static int close_error_manager();

            // -- --- Writing --- ---

            static int register_error(Error::errors error, const std::filesystem::path& file);

        private:

            inline static File* m_error_manager = nullptr;

    };
}