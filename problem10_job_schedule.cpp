#include <thread>
#include <queue>
#include <unistd.h>
#include <iostream>
typedef std::pair <unsigned long long int, void *>  timefunc;
bool is_job_monitor_executing = false;

struct comparer
{
    bool operator()( 
        timefunc const& a, 
        timefunc const& b) 
        const
    { 
        return a.second > b.second; 
    } 
};

std::priority_queue<timefunc, std::vector<timefunc>, comparer> task_queue;

void add_task(void * function, unsigned long long int delaySeconds)
{
    std::pair<unsigned long long int, void *>  functionPair;
    functionPair.second = function;
    functionPair.first = clock() + delaySeconds * CLOCKS_PER_SEC;

    task_queue.push(functionPair);
    
}
void job_monitor()
{
    is_job_monitor_executing = true;
    while(true)
    {
       if(task_queue.empty())
       {
           usleep(100000); //100 ms
           continue;
       }

       if(clock() > task_queue.top().first)
       {
           
           typedef void (*func) ();
           func task= (func)(task_queue.top().second);
           task();
           task_queue.pop();
       }
       else
       {
           usleep(task_queue.top().first - clock());
       }
       
    }
    is_job_monitor_executing = false;
}
void begin_scheduler()
{
    std::thread schedule(job_monitor);
    schedule.detach();
}
void hello()
{
    std::cout << "Hello World!" << std::endl;
}
void goodbye()
{
    std::cout << "Good bye! 'til next time!" << std::endl;
}
void end()
{
    is_job_monitor_executing = false;
}
int main()
{
    begin_scheduler();
    add_task((void *) &hello, 5);
    add_task((void *) &goodbye, 30); 
    add_task((void *) &end, 60); 

    is_job_monitor_executing = true;
    while(is_job_monitor_executing) ;

}