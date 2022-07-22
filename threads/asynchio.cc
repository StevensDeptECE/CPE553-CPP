#include <aio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

#include <condition_variable>
#include <cstring>
#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono_literals;

constexpr uint32_t blockSize = 512;

mutex readMutex;
mutex procMutex;
condition_variable cv;
int fh;
int bytesRead;

void process(char* buf, uint32_t bytesRead) {
  cout << "processing..." << endl;
  usleep(100000);
}

void aio_completion_handler(sigval_t sigval) {
  struct aiocb* req = (struct aiocb*)sigval.sival_ptr;

  // check whether asynch operation is complete
  if (aio_error(req) == 0) {
    int ret = aio_return(req);
    cout << "ret == " << ret << endl;
    cout << (char*)req->aio_buf << endl;
  }
  cv.notify_one();
}

void thready() {

  char*  buf1 = new char[blockSize];
  char* buf2 = new char[blockSize];
  aiocb cb;
  char* processbuf = buf1;
  char* readbuf = buf2;
  fh = open("smallfile.dat", O_RDONLY);
  if (fh < 0) {
    throw std::runtime_error("cannot open file!");
  }

  memset(&cb, 0, sizeof(aiocb));
  cb.aio_fildes = fh;
  cb.aio_nbytes = blockSize;
  cb.aio_offset = 0;

  // Fill in callback information
  /*
  Using SIGEV_THREAD to request a thread callback function as a notification
  method
  */
  cb.aio_sigevent.sigev_notify_attributes = nullptr;
  cb.aio_sigevent.sigev_notify = SIGEV_THREAD;
  cb.aio_sigevent.sigev_notify_function = aio_completion_handler;
  /*
  The context to be transmitted is loaded into the handler (in this case, a
  reference to the aiocb request itself). In this handler, we simply refer to
  the arrived sigval pointer and use the AIO function to verify that the request
  has been completed.
  */
  cb.aio_sigevent.sigev_value.sival_ptr = &cb;

  int currentBytesRead = read(fh, buf1, blockSize);  // read the 1st block

  unique_lock<mutex> readLock(readMutex);
  while (true) {
    cb.aio_buf = readbuf;
    aio_read(&cb);  // each next block is read asynchronously
    process(processbuf, currentBytesRead);  // process while waiting
    cv.wait(readLock);
    if (currentBytesRead < blockSize) {
      break;  // last time, get out
    }
    cout << "back from wait" << endl;
    swap(processbuf, readbuf);     // switch to other buffer for next time
    currentBytesRead = bytesRead;  // create local copy
  }

  delete[] buf1;
  delete[] buf2;
}

int main() {
  try {
    thready();
  } catch (std::exception& e) {
    cerr << e.what() << '\n';
  }
  return 0;
}