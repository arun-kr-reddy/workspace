#include <sstream>

#include "common_defs.h"
#include "map"

int main(void)
{
    std::map<int, int> mp;

    mp[10] = 20;
    mp[30] = 60;
    mp.insert({30, 70});

    auto posItr = mp.find(40);

    if (mp.count(40) > 0)
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }

    // create string
    std::stringstream out_sstream;
    out_sstream << "pi" << 3.14;
    std::string str_out = out_sstream.str();
    std::cout << str_out << std::endl;  // pi: 3.14

    std::stringstream in_sstream(str_out);
    std::string str;
    float val;
    in_sstream >> str >> val;  // str: 'pi ', val: 3.14

    return 0;
}

int main(int argc, char *argv[])
{
    int ret = fork();  // ret is child process PID

    if (ret < 0)  // fork failed
    {
        printf("fork failed\n";)
    }
    else if (ret == 0)  // child process
    {
        printf("child process %d\n", getpid());
    }
    else  // parent process
    {
        printf("parent process %d of child %d\n", getpid(), ret);
    }
}