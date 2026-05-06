#include <iostream>
#include <fcntl.h>   
#include <unistd.h>  
#include <cstring>    

using namespace std;

int main() {
    int fd;
    char buffer[100]; 
    const char* data = "OS Learning Made Easy";

    fd = open("demo.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    
    if (fd < 0) {
        perror("Error opening file for writing"); 
        return 1;
    }

    write(fd, data, strlen(data));
    close(fd);
    cout << "1. File 'demo.txt' created and data written." << endl;

    fd = open("demo.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file for reading");
        return 1;
    }

    int bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    
    if (bytesRead >= 0) {
        buffer[bytesRead] = '\0'; 
        cout << "2. Data read from file: " << buffer << endl;
    }
    
    close(fd);

    if (unlink("demo.txt") == 0) {
        cout << "3. File 'demo.txt' deleted successfully using unlink()." << endl;
    } else {
        perror("Error deleting file");
    }

    return 0;
}