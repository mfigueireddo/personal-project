#include "common_std_libraries.h"
#include "common_project_libraries.h"

int before_loop();
int loop();
int after_loop();

int status;

int main(const int argc, char* argv[])
{
    if (argc != 1) return Manager::Error::errors::WRONG_USAGE;

    // --- --- --- ---

    if ( (status = before_loop()) ) return status;

    if ( (status = loop()) ) return status;

    if ( (status = after_loop()) ) return status;

    // --- --- --- ---

    return 0;
}

int before_loop()
{
    if ( (status = Manager::Log::open_error_manager()) ) return status;

    return Manager::Error::errors::SUCCESS;
}

int loop()
{
    return Manager::Error::errors::SUCCESS;
}

int after_loop()
{
    if ( (status = Manager::Log::close_error_manager()) ) return status;

    if ( (status = Manager::ObjectDestroyer::delete_objects()) ) return status;

    return Manager::Error::errors::SUCCESS;
}