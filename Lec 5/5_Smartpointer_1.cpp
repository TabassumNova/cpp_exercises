/*
 * cycle.cpp
 *
 *  Created on: 16.07.2011
 *      Author: Rainer Grimm
 *      Book  : C++0x
 */
#include <iostream>
#include <memory>

class Node{
public:
  Node(const std::string& n):name(n){
    std::cout << "Object created"<< std::endl;
  }
  /*
  Node(){
    name = "hi nova";
    std::cout << "hi nova Object created"<< std::endl;
  }*/

  ~Node(){
    std::cout << "destructor invoked " << getName() << std::endl;
  }

  void setNext( std::shared_ptr<Node>n ){
    next= n;
  }

  std::string getName() const { return name; }

  void getCycle() const{
     std::cout << "this" << std::endl;
     std::cout << "     (" << getName() << ":" << (void*)this << ")" << std::endl;
     std::cout << "this->next" << std::endl;
     std::cout << "     (" << next->getName() << ":" << (void*)next.get() << ")" << std::endl;
     std::cout << "this->next->next" << std::endl;
     std::cout << "     (" << next->next->getName() << ":" << (void*)next->next.get() << ")" << std::endl;
  }

private:
  std::string name;
  std::shared_ptr<Node> next;
};



int main(){

  std::cout << std::endl;
  std::shared_ptr<Node> spForHead1;
  {

    // create the Nodes and give them names
    Node* head= new Node("head");
    Node* tail= new Node("tail");
    //Node n("nova");
    //int *i = new int(5);
    //std::cout << "i= "<< *i<< std::endl;
    std::cout << "head->getName(): " << head->getName() << std::endl;
    std::cout << "tail->getName(): " << tail->getName() << std::endl;

    std::cout << std::endl;

    // create the shared pointer
    std::shared_ptr<Node> spForHead(head);
    //std::cout << "head: " << spForHead << std::endl;
    head->setNext(std::shared_ptr<Node>(tail));
    //std::cout << "shared tail: " << tail<< std::endl;
    //std::cout << "shared: " << std::shared_ptr<Node>(tail)<< std::endl;
    //spForHead1 = spForHead;
    // close the cycle
    tail->setNext(spForHead);

    // show the cycle
    spForHead->getCycle();
    //std::cout << "count: " << spForHead.use_count() << std::endl;
  }

  //std::cout << "count: " << spForHead1.use_count() << std::endl;

  //std::cout << std::endl;

}
