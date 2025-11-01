#include "Error.h"
#include "../common_project_libraries.h"

namespace Manager
{
    std::string Error::get_message(const errors error)
    {
        switch (error)
        {
            case errors::SUCCESS:
                return "Success";
            case errors::WRONG_USAGE:
                return "Wrong usage";
            case errors::FILE_NOT_FOUND:
                return "File not found";
            case errors::UNKNOWN_EXTENSION:
                return "Unknown extension";
            case errors::NULL_OBJECT:
                return "Null object";
            case errors::OBJECT_ALREADY_REGISTERED:
                return "Object already registered";
            case errors::OBJECT_NOT_REGISTERED:
                return "Object not registered";
            default:
                return "Unknown error";
        }
    }

    std::string Error::get_description(const errors error)
    {
        switch (error)
        {
            case errors::SUCCESS:
                return "";
            case errors::WRONG_USAGE:
                return "";
            case errors::FILE_NOT_FOUND:
                return "";
            case errors::UNKNOWN_EXTENSION:
                return "";
            case errors::NULL_OBJECT:
                return "";
            case errors::OBJECT_ALREADY_REGISTERED:
                return "";
            case errors::OBJECT_NOT_REGISTERED:
                return "";
            default:
                return "Unknown error";
        }
    }

    std::string Error::get_module(const errors error)
    {
        switch (error)
        {
            case errors::SUCCESS:
                return "";
            case errors::WRONG_USAGE:
                return "main";
            case errors::FILE_NOT_FOUND:
                return "Manager::File";
            case errors::UNKNOWN_EXTENSION:
                return "Manager::File";
            case errors::NULL_OBJECT:
                return "ObjectDestroyer";
            case errors::OBJECT_ALREADY_REGISTERED:
                return "ObjectDestroyer";
            case errors::OBJECT_NOT_REGISTERED:
                return "ObjectDestroyer";
            default:
                return "Unknown error";
        }
    }
}
