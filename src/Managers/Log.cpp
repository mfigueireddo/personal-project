#include "Log.h"
#include "../common_project_libraries.h"

namespace Manager
{
    

    Log* Log::create()
    {
        const auto object = new Log();
        ObjectDestroyer::register_object( new std::any( std::unique_ptr<Log>(object).get() ) );
        return object;
    }

    // -- --- File management --- ---

    int Log::open_error_manager()
    {
        m_error_manager = File::create("files/log/error", File::types::TXT);

        if (const int status = m_error_manager->open_to_write()) return status;

        return Error::errors::SUCCESS;
    }

    int Log::close_error_manager()
    {
        if (const int status = m_error_manager->close()) return status;

        return Error::errors::SUCCESS;
    }

    // -- --- Writing --- ---

    int Log::register_error(const Error::errors error,  const std::filesystem::path& file)
    {
        std::ostringstream formated_message;

        formated_message
            << "Error at: " << file.string() << std::endl
            << "Obtained from: " << Error::get_module(error) << std::endl
            << Error::get_message(error) << ": " << Error::get_description(error) << std::endl
        ;

        m_error_manager->write(formated_message.str());

        return Error::errors::SUCCESS;
    }
}