#ifndef PRINTER_H
#define PRINTER_H
#include "printjob.h"
#include <vector>


using namespace std;

class Printer {
    public:
        Printer(int maxNumJobs, int maxNumPages);

        int queueLength() const;
        int queuePages() const;
        bool isEmpty() const;
        bool isFull() const;

        PrintJob next();
        bool push(const PrintJob& dato, bool force = false);

        int getMaxNumPages() const{
            return maxNumPages;
        }
        void setMaxNumPages(int value){
            maxNumPages = value;
        }


private:
        vector<PrintJob> v1;
        int maxNumJobs;
        int maxNumPages;
        int _maxNumJobs;
        int _maxNumPages;
          vector<PrintJob>_maxNumPagesv1;

        int plusPages;
        int plusJobs;
};
#endif // PRINTER_H
