#pragma once

#include "Error.h"
#include "../common_std_libraries.h"

namespace Manager
{
    class ObjectDestroyer
    {
    private:

        ObjectDestroyer() = default;
        ~ObjectDestroyer() = default;

        static bool is_object_in_vector(std::any* object);

    public:

        static Error::errors register_object(std::any* object);
        static Error::errors unregister_object(std::any* object);
        static Error::errors delete_objects();

    private:

        inline static std::vector<std::any*> m_objects;
    };
}