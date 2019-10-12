#include<iostream>
#include<cmath>
#include"RPNCalculator.hpp"

using namespace std;

RPNCalculator::RPNCalculator(){
  stackHead = NULL;
}

RPNCalculator::~RPNCalculator(){
  Operand *crawler = stackHead;
  while(crawler->next != NULL){
    delete crawler->next;
  }
  delete crawler;
}

bool RPNCalculator::isEmpty(){
  if(stackHead == NULL)return true;
  return false;
}

void RPNCalculator::push(float num){
  Operand *temp = new Operand;
  temp->number = num;
  temp->next = stackHead;
  stackHead = temp;
}

void RPNCalculator::pop(){
  if(RPNCalculator::isEmpty()){
    cout<<"Stack empty, cannot pop an item."<<endl;
    return;
  }
  Operand *temp = stackHead->next;
  delete stackHead;
  stackHead = temp;
}

Operand* RPNCalculator::peek(){
  if(RPNCalculator::isEmpty()){
    cout<<"Stack empty, cannot peek."<<endl;
    return NULL;
  }
  return stackHead;
}

bool RPNCalculator::compute(std::string symbol){
  float num1, num2, sol;
  if(symbol != "+" && symbol != "*"){
    cout<<"err: invalid operation"<<endl;
    return false;
  }
  if(stackHead == NULL || stackHead->next == NULL){
    cout<<"err: not enough operands"<<endl;
    return false;
  }
  num1 = stackHead->number;
  num2 = stackHead->next->number;
  if(symbol == "+"){
    sol = num1+num2;
    RPNCalculator::pop();
    RPNCalculator::pop();
    RPNCalculator::push(sol);
  }
  if(symbol == "*"){
    sol = num1*num2;
    RPNCalculator::pop();
    RPNCalculator::pop();
    RPNCalculator::push(sol);
  }
  return true;
}
