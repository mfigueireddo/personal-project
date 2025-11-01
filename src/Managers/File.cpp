#include "File.h"
#include "../common_project_libraries.h"

namespace Manager
{
    // private

    std::string File::get_type_extension(const types type)
    {
        switch (type)
        {
            case types::TXT:
                return ".txt";
            default:
                return "Unknown type";
        }
    }

    File::File(std::string path, const types type)
    :  m_path(std::move(path)), m_type(type) {};

    std::string File::get_full_path() const
    {
        const std::string extension = get_type_extension(m_type);
        if (extension == "Unknown type") return "Unknown type";

        std::string full_name = m_path + extension;
        return full_name;
    }

    // public

    File* File::create(const std::string &path, const types type)
    {
        const auto object = new File(path, type);
        ObjectDestroyer::register_object( new std::any( std::unique_ptr<File>(object).get() ) );
        return object;
    }

    // --- --- Read --- ---

    Error::errors File::read()
    {
        const std::string file_path = get_full_path();
        if ( file_path == "Unknown type" )
        {
            constexpr Error::errors error = Error::errors::UNKNOWN_EXTENSION;
            Log::register_error(error, __FILE__);
            return error;
        }

        m_file = fopen(file_path.c_str(), "r");
        if (!m_file)
        {
            constexpr Error::errors error = Error::errors::FILE_NOT_FOUND;
            Log::register_error(error, __FILE__);
            return error;
        }

        char buffer[1024];
        while (fgets(buffer, 1024, m_file))
        {
            m_parsed_file.append(buffer);
        }

        fclose(m_file);

        return Error::errors::SUCCESS;
    }

    Error::errors File::print() const
    {
        std::cout << m_parsed_file << std::endl;
        return Error::errors::SUCCESS;
    }

    // --- --- Write --- ---

    Error::errors File::open_to_write()
    {
        const std::string file_path = get_full_path();
        if (file_path.empty())
        {
            constexpr Error::errors error = Error::errors::UNKNOWN_EXTENSION;
            Log::register_error(error, __FILE__);
            return error;
        }

        m_file = fopen(file_path.c_str(), "w");
        if (!m_file)
        {
            constexpr Error::errors error = Error::errors::FILE_NOT_FOUND;
            Log::register_error(error, __FILE__);
            return error;
        }

        return Error::errors::SUCCESS;
    }

    Error::errors File::write(const std::string& content)
    {
        if (!m_file)
        {
            constexpr Error::errors error = Error::errors::FILE_NOT_FOUND;
            Log::register_error(error, __FILE__);
            return error;
        }

        fwrite(content.c_str(), 1, content.size(), m_file);
        m_parsed_file.append(content);

        return Error::errors::SUCCESS;
    }

    Error::errors File::close() const
    {
        if (!m_file)
        {
            constexpr Error::errors error = Error::errors::FILE_NOT_FOUND;
            Log::register_error(error, __FILE__);
            return error;
        }

        fclose(m_file);

        return Error::errors::SUCCESS;
    }
}