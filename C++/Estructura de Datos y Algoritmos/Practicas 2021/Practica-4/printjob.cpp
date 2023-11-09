#include "printjob.h"
#include <iostream>


using namespace std;

PrintJob::PrintJob(int timestamp, int pages, const string &title)
{
    timestamp = timestamp;
    pages = nPages;
    title == title;
}

int PrintJob::getPages() const
{
    return nPages;
}

bool PrintJob::operator<(const PrintJob & other) const
{
    if(getPages() < other.getPages()){
        return true;
    }else{
        return false;
    }
}

bool PrintJob::operator>(const PrintJob &other) const
{
    if(getPages() > other.getPages()){
        return true;
    }else{
        return false;
    }
}

bool PrintJob::operator==(const PrintJob &other) const
{

    if(getPages() == other.getPages()){
        return true;
    }else{
        return false;
    }
}

ostream & operator<<(ostream &os, const PrintJob &job)
{
    os << job.timestamp << "-"<<job.nPages<<"-"<<job.title ;
    return os;
}

