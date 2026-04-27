#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #include <sys/wait.h>
#endif
using namespace std;

void fileManagement()
{
    cout << "File Management Selected\n";
}

void directoryManagement()
{
    cout << "Directory Management Selected\n";
}

void processManagement()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        cout << "Fork failed!\n";
        return;
    }
    else if (pid == 0)
    {
        cout << "Child Process Running\n";
        cout << "Child PID: " << getpid() << endl;

        execl("/bin/ls", "ls", NULL);

        cout << "Execution failed!\n";
    }
    else
    {
        wait(NULL);

        cout << "Parent Process Running\n";
        cout << "Parent PID: " << getpid() << endl;
    }
}

int main()
{
    int choice;

    cout << "\n===== LINUX SYSTEM CALLS PROGRAM =====\n";
    cout << "1. File Management\n";
    cout << "2. Directory Management\n";
    cout << "3. Process Management\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            fileManagement();
            break;

        case 2:
            directoryManagement();
            break;

        case 3:
            processManagement();
            break;

        default:
            cout << "Invalid Choice!\n";
    }

    cout << "\nProgram Completed Successfully.\n";

    return 0;
}