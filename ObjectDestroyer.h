#pragma once

#include "common_libraries.h"

class ObjectDestroyer
{
    private:

        ObjectDestroyer() = default;
        ~ObjectDestroyer() = default;

        static bool is_object_in_vector(std::any* object);

    public:

        static int register_object(std::any* object);
        static int unregister_object(std::any* object);
        static int delete_objects();

    private:

        inline static std::vector<std::any*> m_objects;
};