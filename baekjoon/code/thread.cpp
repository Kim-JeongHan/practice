#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;
class A
{
public:
    A()
    {
        // f=p.get_future();
        i=0;
        t1 = thread(&A::function1, this);
        t2 = thread(&A::function2, this);
    }
    ~A()
    {
        t1.join();
        t2.join();
    }

    void function1()
    {
        int j = 0;
        while(j<10)
        {
            auto f = p.get_future();
            auto status = f.wait_for(std::chrono::seconds(10));
            auto result = f.get();
            std::cout << result << std::endl;
            if(status == std::future_status::ready)
            {
                isCheck();
                std::cout << "Future is ready!" << std::endl;
            }
            else if(status == std::future_status::timeout)
            {
                std::cout << "Future is not ready!" << std::endl;
            }
            else if(status == std::future_status::deferred)
            {
                std::cout << "Future is deferred!" << std::endl;
            }
            j++;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    void function2()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        while(true)
        {
            i++;
            p.set_value(i);
            cout << "Set value: " << i << "\n";
            p=promise<int>();
            // f=p.get_future();
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
    void isCheck()
    {
        auto f = p.get_future();
        auto result = f.get();
        std::cout << "Check: " << result << std::endl;
    }

private:
    thread t1, t2;
    promise<int> p;
    // future<int> f;
    int i;
};


int main()
{
    A a;

    return 0;
}



