#ifndef FIFTHELEMENT_H
#define FIFTHELEMENT_H

#include "LinkedList.h"
#include <stdexcept>

template <typename Type>
class FifthElement : public LinkedList<Type>
{
public:
    FifthElement() = default;

    Type getFifthElement()
    {
        if (this->cou < 5)
        {
            throw std::runtime_error("no fifth element");
        }

        auto curr = this->front;
        int cou = 1;

        while (cou < 5 && curr != nullptr)
        {

            curr = curr->next;

            cou++;
        }

        return curr->data;
    }

    void insertNewFifthElement(const Type &value)
    {
        if (this->cou < 4)
        {

            this -> insert(value);
            return;
        }

        auto curr = this -> front;
        int cou = 1;

        while (cou < 4 && curr != nullptr)
        {
            curr = curr->next;
            cou++;
        }

        auto nNode = make_shared<Node<Type>>();

        nNode -> data = value;
        nNode -> next = curr->next;

        curr -> next = nNode;


        if (nNode->next == nullptr)
        {
            this->back = nNode;
        }

        this->cou++;
    }

    void deleteFifthElement()
    {
        if (this->cou < 5)
        {
            throw std::runtime_error("no fifth element");
        }

        auto curr = this->front;
        int cou = 1;

        while (cou < 4 && curr != nullptr)
        {
            curr = curr ->next;
            cou++;
        }

        auto toDel = curr->next;
        curr->next = toDel->next;

        if (toDel->next == nullptr)
        {
            this->back = curr;
        }

        this->cou--;
    }

    void swapFourthAndFifthElement()
    {
        if (this->cou < 5)
        {
            throw std::runtime_error("not enough elements to swap");
        }

        auto curr = this -> front;
        int cou = 1;

        while (cou < 3 && curr != nullptr)
        {
            curr = curr->next;
            cou++;
        }

        auto fourth = curr -> next;
        auto fifth = fourth -> next;

        curr -> next = fifth;
        fourth -> next = fifth -> next;
        fifth -> next = fourth;

        if (fifth == nullptr)
        {
            return;
        }

        if (fourth->next == nullptr)
        {
            this->back = fourth;
        }
    }
};

#endif
