#ifndef HEADERSESOURCEMANAGEMENTESOURCEHOLDER_HPP
#define HEADERSESOURCEMANAGEMENTESOURCEHOLDER_HPP

#include <map>
#include <memory>
#include <cassert>


namespace Resources
{

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    void                             load(Identifier id, const std::string& filename);

    template <typename Parameter>
    void                             load(Identifier id, const std::string& filename, const Parameter& parameter);

    Resource&                        get(Identifier id);
    const Resource&                  get(Identifier id) const;
private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;

};

#include "headers/resourcemanagement/resourceholder.inl"

}

#endif // HEADERSESOURCEMANAGEMENTESOURCEHOLDER_HPP
