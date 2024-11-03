#pragma once

#include <vector>
#include "Action.hpp"
#include "Transition.hpp"

template<typename T>
class Behaviour
{
	std::vector<Action<T>*> mActions;
	std::vector<Transition<T>*> mTransitions;
	T* mOwner;

public:
    Behaviour(T* owner);
    ~Behaviour();

    void Start();
    void Update();
    void End();

    void AddAction(Action<T>* value);
    void AddTransition(Transition<T>* value);
};


template<typename T>
Behaviour<T>::Behaviour(T* owner)
{
    mOwner = owner;
}

template<typename T>
Behaviour<T>::~Behaviour()
{
    for (auto it : mActions)
    {
        delete it;
    }

    for (auto it : mTransitions)
    {
        delete it;
    }
}

template<typename T>
void Behaviour<T>::AddTransition(Transition<T>* pTransition)
{
    mTransitions.push_back(pTransition);
}

template<typename T>
void Behaviour<T>::AddAction(Action<T>* pAction)
{
    mActions.push_back(pAction);
}

template<typename T>
void Behaviour<T>::Start()
{
    for (const auto& a : mActions)
    {
        a->Start(mOwner);
    }
}

template<typename T>
void Behaviour<T>::Update()
{
    for (const auto& a : mActions)
    {
        a->Update(mOwner);
    }

    for (const auto& t : mTransitions)
    {
        if (t->Try(mOwner))
            break;
    }
}


template<typename T>
void Behaviour<T>::End()
{
    for (const auto& a : mActions)
    {
        a->End(mOwner);
    }
}