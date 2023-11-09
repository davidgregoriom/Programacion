#ifndef PRINTJOB_H
#define PRINTJOB_H
#include <iostream>



class PrintJob {
    public:
        PrintJob(int timestamp, int pages, const std::string& title);
        int getPages() const;
        bool operator<(const PrintJob& Printer) const;
        bool operator>(const PrintJob& Printer) const;
        bool operator==(const PrintJob& Printer) const;
        friend std::ostream &operator<<(std::ostream& os, const PrintJob& job);
    private:
        int nPages;
        int timestamp;
        std::string title;
};
std::ostream& operator<<(std::ostream& os, const PrintJob& job);
#endif // PRINTJOB_H
