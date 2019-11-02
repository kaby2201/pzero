#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <memory>
#include <unordered_map>

template<typename RESOURCE, typename IDENTIFIER = int>
class AssetManager {
public:
    // Makes it impossible to copy the asset manager
    AssetManager(const AssetManager&) = delete;

    AssetManager &operator=(const AssetManager &) = delete;

    AssetManager() = default;

    template<typename ... Args>
    void load(const IDENTIFIER &identifier, Args &&... args){
        // Check to see if the file can load, then moves it into the map
        std::unique_ptr<RESOURCE> ptr(new RESOURCE);

        if(not ptr->loadFromFile(std::forward<Args>(args)...)){
            throw std::runtime_error("The the file can't load ");
        }

        this->map.emplace(identifier, std::move(ptr));
    }

    RESOURCE &get(const IDENTIFIER &identifier) const {
        return *this->map.at(identifier);
    }

private:
    std::unordered_map<IDENTIFIER, std::unique_ptr<RESOURCE>> map;
};

#endif //ASSET_MANAGER_H
