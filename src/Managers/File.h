#pragma once

#include "../common_std_libraries.h"

namespace Manager
{
    class File
    {
        public:

            enum types
            {
                TXT,
            };

            static std::string get_type_extension(types type);

        private:

            File(std::string path, types type);

            [[nodiscard]] std::string get_full_path() const;

        public:

            static File* create(const std::string &path, const types type);
            ~File() = default;

            // --- --- Read --- ---

            int read();
            int print() const;

            // --- --- Write --- ---

            int open_to_write();
            int write(const std::string& content);
            int close() const;

            // --- --- Members --- ---

            [[nodiscard]] std::string get_path() const { return m_path; }
            [[nodiscard]] std::string get_parsed_content() const { return m_parsed_file; }
            [[nodiscard]] types get_type() const { return m_type; }

            void set_path(const std::string &path) { m_path = path; }
            void set_type(const types type) { m_type = type; }

        private:

            FILE* m_file = nullptr;

            std::string m_path;
            std::string m_parsed_file;

            types m_type;
    };
}