#include "ObjectDestroyer.h"

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

int ObjectDestroyer::register_object(std::any* object)
{
    if (!object) return Manager::Error::errors::NULL_OBJECT;

    if (is_object_in_vector(object)) return Manager::Error::errors::OBJECT_ALREADY_REGISTERED;

    m_objects.push_back(object);

    return Manager::Error::errors::SUCCESS;
}

int ObjectDestroyer::unregister_object(std::any* object)
{
    if (!object) return Manager::Error::errors::NULL_OBJECT;

    if (!is_object_in_vector(object)) return Manager::Error::errors::OBJECT_NOT_REGISTERED;

    std::erase(m_objects, object);

    return Manager::Error::errors::SUCCESS;
}

int ObjectDestroyer::delete_objects()
{
    for (const auto* object : m_objects)
    {
        delete object;
    }

    m_objects.clear();

    return Manager::Error::errors::SUCCESS;
}