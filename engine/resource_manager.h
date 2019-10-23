#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <memory>
#include <unordered_map>

template<typename RESOURCE, typename IDENTIFIER = int>
class ResourceManager {
public:
    // Makes it impossible to copy the resource manager
    ResourceManager(const ResourceManager &) = delete;

    ResourceManager &operator=(const ResourceManager &) = delete;

    ResourceManager() = default;

    template<typename ... Args>
    void load(const IDENTIFIER &id, Args &&... args) {
        // Check to see if the file can load, then moves it into the map
        std::unique_ptr<RESOURCE> ptr(new RESOURCE);

        if(not ptr->loadFromFile(std::forward<Args>(args)...)) {
            throw std::runtime_error("Impossible to load file");
        }

        this->map.emplace(id, std::move(ptr));
    }

    RESOURCE &get(const IDENTIFIER &id) const {
        return *this->map.at(id);
    };

private:
    std::unordered_map<IDENTIFIER, std::unique_ptr<RESOURCE>> map;
};

#endif
