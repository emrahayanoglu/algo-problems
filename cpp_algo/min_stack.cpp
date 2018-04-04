#include <iostream>
#include <stack>

struct MinStack{
    std::stack<int> m_stack;
    std::stack<int> m_maxStack;
    
    void push(int i){
        m_stack.push(i);
        
        if(m_maxStack.empty() || 
            (!m_maxStack.empty() && m_maxStack.top() > i))
        {
            m_maxStack.push(i);
        }
        else{
            m_maxStack.push(m_maxStack.top());            
        }
    }
    
    int min(){
        if(m_stack.empty())
            throw std::exception();
            
        return m_maxStack.top();
    }
    
    void pop(){
        if(m_stack.empty())
            throw std::exception();    
        
        m_maxStack.pop();
        m_stack.pop();
    }
};

int main(){
    MinStack ms;
    ms.push(10);
    ms.push(5);
    ms.push(7);
    
    std::cout << ms.min() << std::endl;
    
    ms.pop();
    ms.pop();
    
    std::cout << ms.min() << std::endl;
    
    return 0;
}