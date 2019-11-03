#include <fstream>
//#include <sys/stat.h>

#define N_SIZE 8    // size of a frame
int main()
{
    const char *fifo_name = "fifo";
    //mknod(fifo_name, S_IFIFO | 0666, 0);
    std::ifstream  pipe(fifo_name, std::ios::binary);  // Open the pipe
    if (!pipe)
    {
        printf("failed to open the named pipe\n");
        return -1;
    }

    unsigned char* buffer = new unsigned char[N_SIZE];
    
    while(1)  // TODO: a proper condition to leave the loop
    {
        pipe.read((char*)buffer, N_SIZE);
        for(int i=0; i<N_SIZE; i++)
            printf("%d ", buffer[i]);

        printf("\n");
        // TODO: check whether pipe write close or not
    }

    delete [] buffer;
    pipe.close();
    return 0;
}