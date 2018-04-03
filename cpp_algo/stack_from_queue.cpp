#include <queue>
#include <iostream>

struct QueueFromStack{
  std::queue<int> in_q;
  std::queue<int> out_q;
  
  size_t totalSize = 0;
  
  void push(int i){
    in_q.push(i);
    
    totalSize++;
  }
  
  int pop(){
    if(isEmpty())
      return -1;

    while(in_q.size() > 1){
      out_q.push(in_q.front());
      in_q.pop();
    }
    
    int el = in_q.front();
    in_q.pop();
    
    while(out_q.size() > 0){
      in_q.push(out_q.front());
      out_q.pop();
    }
    
    totalSize--;
    
    return el;      
  }
  
  int top(){
    if(isEmpty())
      return -1;

    while(in_q.size() > 1){
      out_q.push(in_q.front());
      in_q.pop();
    }
    
    int el = in_q.front();
    in_q.pop();
    
    while(out_q.size() > 0){
      in_q.push(out_q.front());
      out_q.pop();
    }
    
    in_q.push(el);
    
    return el;
  }
  
  bool isEmpty(){
      return totalSize == 0;
  }
  
};

int main(){
  QueueFromStack q;
  q.push(1);
  q.push(2);
  std::cout << "Current Top: " << q.top() << std::endl;
  q.push(3);
  q.pop();
  std::cout << "Current Top: " << q.top() << std::endl;
  q.push(4);
  std::cout << "Current Top: " << q.top() << std::endl;
  q.push(5);
  q.pop();
  q.push(6);
  std::cout << "Current Top: " << q.top() << std::endl;
  return 0;
}