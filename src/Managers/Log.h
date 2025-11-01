#pragma once

#include "Error.h"
#include "File.h"
#include "../common_std_libraries.h"

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

            static Error::errors open_error_manager();
            static Error::errors close_error_manager();

            // -- --- Writing --- ---

            static Error::errors register_error(Error::errors error, const std::filesystem::path& file);

        private:

            inline static File* m_error_manager = nullptr;

    };
}