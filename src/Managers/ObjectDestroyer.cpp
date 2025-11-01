#include "ObjectDestroyer.h"
#include "../common_project_libraries.h"

namespace Manager
{
    // private

    bool ObjectDestroyer::is_object_in_vector(std::any* object)
    {
        return std::ranges::find
        (
            m_objects.begin(),
            m_objects.end(),
            object
        ) != m_objects.end();
    }

    // public

    Error::errors ObjectDestroyer::register_object(std::any* object)
    {
        if (!object)
        {
            constexpr Error::errors error = Error::errors::NULL_OBJECT;
            Log::register_error(error, __FILE__);
            return error;
        }

        if (is_object_in_vector(object))
        {
            constexpr Error::errors error = Error::errors::OBJECT_ALREADY_REGISTERED;
            Log::register_error(error, __FILE__);
            return error;
        }

        m_objects.push_back(object);

        return Error::errors::SUCCESS;
    }

    Error::errors ObjectDestroyer::unregister_object(std::any* object)
    {
        if (!object)
        {
            constexpr Error::errors error = Error::errors::NULL_OBJECT;
            Log::register_error(error, __FILE__);
            return error;
        }

        if (!is_object_in_vector(object))
        {
            constexpr Error::errors error = Error::errors::OBJECT_NOT_REGISTERED;
            Log::register_error(error, __FILE__);
            return error;
        }

        std::erase(m_objects, object);

        return Error::errors::SUCCESS;
    }

    Error::errors ObjectDestroyer::delete_objects()
    {
        for (const auto* object : m_objects)
        {
            delete object;
        }

        m_objects.clear();

        return Error::errors::SUCCESS;
    }
}