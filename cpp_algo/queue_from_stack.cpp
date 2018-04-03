#include <stack>
#include <iostream>

struct StackFromQueue{
  std::stack<int> in_s;
  std::stack<int> out_s;
  
  size_t totalSize = 0;
  
  void push(int i){
    in_s.push(i);
    
    totalSize++;
  }
  
  int pop(){
    if(isEmpty())
      return -1;

    while(in_s.size() > 1){
      out_s.push(in_s.top());
      in_s.pop();
    }
    
    int el = in_s.top();
    in_s.pop();
    
    while(out_s.size() > 0){
      in_s.push(out_s.top());
      out_s.pop();
    }
    
    totalSize--;
    
    return el;      
  }
  
  int top(){
    if(isEmpty())
      return -1;

    while(in_s.size() > 1){
      out_s.push(in_s.top());
      in_s.pop();
    }
    
    int el = in_s.top();
    
    while(out_s.size() > 0){
      in_s.push(out_s.top());
      out_s.pop();
    }
    
    return el;
  }
  
  bool isEmpty(){
      return totalSize == 0;
  }
  
};

int main(){
  StackFromQueue s;
  s.push(1);
  s.push(2);
  std::cout << "Current Top: " << s.top() << std::endl;
  s.push(3);
  s.pop();
  std::cout << "Current Top: " << s.top() << std::endl;
  s.push(4);
  std::cout << "Current Top: " << s.top() << std::endl;
  s.push(5);
  s.pop();
  s.push(6);
  std::cout << "Current Top: " << s.top() << std::endl;
  return 0;
}