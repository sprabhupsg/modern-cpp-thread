#include<iostream>
#include<thread>

using namespace std;

void foo(){
cout<<"foo() :" <<this_thread::get_id()<<endl;
}

class callable_thread{
public:
  void operator()(){
    cout<<"callable_thread :"<<this_thread::get_id()<<endl;
  }
};


int main(){
  cout<<"main() start :"<<this_thread::get_id()<<endl;


  thread th_1(foo);
  
  callable_thread obj;
  thread th_2(obj);

  thread th_3([]{
    cout<<"lambda func :"<<this_thread::get_id()<<endl;
  });

  th_1.join();
  th_2.join();
  th_3.join();

  cout<<"main() end \n";


  return 0;
}


/*
prabhu@prabhu-VirtualBox:~/cpp$ g++ -pthread thread-create-3.cpp
prabhu@prabhu-VirtualBox:~/cpp$ ./a.out
main() start :140104063727424
foo() :140104063723264
lambda func :140103972284160
callable_thread :140103980676864
main() end

prabhu@prabhu-VirtualBox:~/cpp$ ./a.out
main() start :139865295664960
callable_thread :139865287268096
foo() :139865295660800
lambda func :139865278875392
main() end
prabhu@prabhu-VirtualBox:~/cpp$
*/
