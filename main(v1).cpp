#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>

// using namespace std;

class Task1 {
    private:
    std::vector<int> vec;
    // long int res=0;
    public:
    void rand_vec(int n) {
        srand(time(0));
        vec.resize(n);
        for (int i = 0; i < n; i++) {
            vec[i] = rand() % 100;
        }    }
    long int sum_vec(int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += vec[i];
                    }
        // res=sum;
        return sum;
        }

    long int sum_part(int a, int b, long int* = nullptr) {
        long int sum = 0;
        for (int i = a; i < b; i++) {
            sum += vec[i];
        }
        // *res=sum;
        return sum;
    }
    long int sum_th() {
        int k = vec.size()/4;
        long int sum1 = 0, sum2=0, sum3=0, sum4=0;

        std::thread t1([&]() {sum1 = sum_part(0,k, nullptr);});
        std::thread t2([&]() {sum2 = sum_part(k,k*2, nullptr);});
        std::thread t3([&]() {sum3 = sum_part(k*2,k*3, nullptr);});
        std::thread t4([&]() {sum4 = sum_part(k*3,k*4, nullptr);});
        // std::thread t1(&Task1::sum_part, this, 0, k, &sum1);
        // std::thread t2(&Task1::sum_part, this, k,k*2 ,&sum2);
        // std::thread t3(&Task1::sum_part, this, k*2,k*3 ,&sum3);
        // std::thread t4(&Task1::sum_part, this, k*3, k*4 ,&sum4);

        t1.join(); t2.join(); t3.join(); t4.join();
        // res=sum1+sum2+sum3+sum4;
        return sum1 + sum2 + sum3 + sum4;
    }
    // void result() {
    //     std::cout <<"Result: "<<res << std::endl;
    // }

    
};

int main()
{
    int n=1000000;
    Task1 task1;
    task1.rand_vec(n);

    clock_t begin = clock();
    task1.sum_th();
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout <<"Time 4:"<< time_spent << std::endl;
    std::cout << task1.sum_th() << std::endl;

    // task1.result();

    std::cout<<std::endl;
    std::cout<<std::endl;

    begin = clock();
    task1.sum_vec(1000000);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout <<"Time 1:"<< time_spent << std::endl;
    std::cout << task1.sum_vec(n) << std::endl;
    // task1.result();

    return 0;}


