/* Implement stack */

#include<iostream>
#include <cstring>

#define MAX_STACK_SIZE 50


template <typename T> class stack
{
private:
    T* resource;
    int topVal;
public:
    stack()
    {
        resource = new T[MAX_STACK_SIZE];
        topVal = -1;
    }

    stack(stack<T>& st)
    {
        if (this->resource != nullptr)
        {
            this->resource = nullptr;
        }
        this->topVal = st.topVal;
        this->resource = new T[MAX_STACK_SIZE * sizeof(T)];
        std::memcpy(this->resource, st.resource, MAX_STACK_SIZE * sizeof(T));
    }
    stack& operator = (stack<T>& st)
    {
        if (this != &st)
        {
            if (this->resource != nullptr)
            {
                this->resource = nullptr;
            }
            this->topVal = st.topVal;
            this->resource = new T[MAX_STACK_SIZE * sizeof(T)];
            std::memcpy(this->resource, st.resource, MAX_STACK_SIZE * sizeof(T));
        }
        return *this;
    }

    void push(T value)
    {
        if (topVal < MAX_STACK_SIZE)
        {
            resource[++topVal] = value;
        }
    }
    void pop()
    {
        if (!this->empty())
        {
            if (!this->empty())
            {
                --topVal;
            }
        }
    }

    T& top()
    {
        return resource[topVal];
    }
    int size()
    {
        return topVal + 1;
    }
    bool empty()
    {
        if (topVal == -1)
        {
            return true;
        }
        return false;
    }
    ~stack()
    {
        delete resource;
    }
};

int main()
{
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(3);
    st.push(5);
    stack<int> st2 = st;
    std::cout << "Top Element of the stack is : " << st.top();
    std::cout << std::endl;
    st.pop();
    std::cout << "Top Element is : " << st.top();
    std::cout << std::endl;
    std::cout << "Size of the stack is :";
    std::cout << st.size();
    if (st.empty())
    {
        std::cout << "stack is empty";
    }
    return 0;
}