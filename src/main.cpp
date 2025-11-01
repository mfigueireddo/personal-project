#include "common_std_libraries.h"
#include "common_project_libraries.h"

Manager::Error::errors before_loop();
Manager::Error::errors loop();
Manager::Error::errors after_loop();

Manager::Error::errors status;

int main(const int argc, char* argv[])
{
    if (argc != 1)
    {
        constexpr Manager::Error::errors error = Manager::Error::errors::WRONG_USAGE;
        Manager::Log::register_error(error, __FILE__);
        return error;
    }

    // --- --- --- ---

    if ( (status = before_loop()) )
    {
        Manager::Log::register_error(status, __FILE__);
        return status;
    }

    if ( (status = loop()) )
    {
        Manager::Log::register_error(status, __FILE__);
        return status;
    }

    if ( (status = after_loop()) )
    {
        Manager::Log::register_error(status, __FILE__);
        return status;
    }

    // --- --- --- ---

    return 0;
}

Manager::Error::errors before_loop()
{
    if ( (status = Manager::Log::open_error_manager()) )
    {
        Manager::Log::register_error(status, __FILE__);
        return status;
    }

    return Manager::Error::errors::SUCCESS;
}

Manager::Error::errors loop()
{
    return Manager::Error::errors::SUCCESS;
}

Manager::Error::errors after_loop() {
    if ( (status = Manager::Log::close_error_manager()) )
    {
        Manager::Log::register_error(status, __FILE__);
        return status;
    }

    if ( (status = Manager::ObjectDestroyer::delete_objects()) )
    {
        Manager::Log::register_error(status, __FILE__);
        return status;
    }

    return Manager::Error::errors::SUCCESS;
}