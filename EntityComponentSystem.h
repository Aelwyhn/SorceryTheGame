#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

inline size_t getComponentTypeId()
{
    static size_t lastId = 0;
    lastId++;
    return lastId;
}

template <typename T>
inline size_t getComponentTypeId() noexcept
{
    static size_t typeId = getComponentTypeId();
    return typeId;
}

// max components an entity is able to hold
constexpr size_t maxComponents = 32;

// using ComponentBitSet = std::bitset<maxComponents>;
// using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
    // entity is the owner of a component
    Entity* entity;

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    virtual ~Component() {}
};

class Entity
{

    private:
        // if the isActive is false, then we can remove entity from the game
        bool isEntityActive = true;

        std::vector<std::unique_ptr<Component>> components;

        std::bitset<maxComponents> componentBitSet; 
        std::array<Component*, maxComponents> componentArray;

    public:

        void update() {
            for (auto& c: components)
            {
                c->update();
            }
        }
    
        void draw()
        {
            for (auto& c: components)
            {
                c->draw();
            }
        }

        bool isActive() const { return isEntityActive; }
        void destroy() { isEntityActive = false; }

        template <typename T>
        bool hasComponent() const
        {
            return componentBitSet[getComponentTypeId<T>()];
        }

        template <typename T, typename... TArgs>
        T& addComponent(TArgs&&... mArgs)
        {
            T* c(new T(std::forward<TArgs>(mArgs)...));
            c->entity = this;
        
            std::unique_ptr<Component> component{ c };
            components.emplace_back(std::move(component));

            componentArray[getComponentTypeId<T>()] = c;
            componentBitSet[getComponentTypeId<T>()] = true;

            c->init();
            return *c;
        }

        template <typename T>
        T& getComponent() const
        {
            // set a pointer to the position in our componentArray
            auto ptr(componentArray[getComponentTypeId<T>()]);
            return *static_cast<T*>(ptr);
        }

};

class Manager
{
private:
    std::vector<std::unique_ptr<Entity>> entities;

public:
    void update()
    {
        for (auto& e: entities)
        {
            e->update();
        }
    }

    void draw()
    {
        for (auto& e: entities)
        {
            e->draw();
        }
    }

    // removes entities if they are not active
    void refresh()
    {
        entities.erase(
            std::remove_if(std::begin(entities), std::end(entities),
            [](const std::unique_ptr<Entity> &mEntity)
                {
                    return !mEntity->isActive();
                }),
                std::end(entities)
        ); 
    }

    Entity& addEntity()
    {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr{ e };

        entities.emplace_back(std::move(uPtr));
        return *e;
    }
};