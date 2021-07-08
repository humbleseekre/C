/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
#include<thread>
#include<queue>
#include<mutex>
#include<chrono>
#include<condition_variable>

using namespace std;

mutex m, t;
condition_variable cv;

class Buffer{
private:
    queue<int> _buff;
    int _sz;
public:
    Buffer(int sz): _sz(sz){}
    Buffer(){}
    void add(int num){
        while(true){
            unique_lock<mutex> ul(m);
            while(_buff.size() >= _sz){
                cv.wait(ul);
            }
            _buff.push(num);
            ul.unlock();
            cv.notify_all();
            return;
        }
    }
    
    int remove(){
        while(true){
            unique_lock<mutex> ul(m);
            while(_buff.size() == 0){
                cv.wait(ul);
            }
            int temp = _buff.front();
            _buff.pop();
            ul.unlock();
            cv.notify_all();
            return temp;
        }       
    }
};

class Producer{
private:
    Buffer& _buff;
public:
    Producer(Buffer& buff): _buff(buff) {}
    void run(){
        while(true){
            int num = rand()%100;
            _buff.add(num);
            t.lock();
            cout << "Produced: " << num << "\n";
            t.unlock();
            this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
};

class Consumer{
private:
    Buffer& _buff;
public:
    Consumer(Buffer& buff): _buff(buff){}
    
    void run(){
        while(true){
            int num = _buff.remove();
            t.lock();
            cout << "Consumed: " << num << "\n";
            t.unlock();
            this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
};

int main(){
    Buffer b;
    Producer p(b);
    Consumer c(b);
    thread producer_thread(&Producer::run, &p);
    thread consumer_thread(&Consumer::run, &c);
    producer_thread.join();
    consumer_thread.join();
    getchar();
    return 0;
}
            
            
