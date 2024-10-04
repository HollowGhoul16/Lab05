#include <iostream>
#include <ostream>
#include <string>
#include "StringData.h"
#include <vector>

static int linear_search(std::vector<std::string> container, std::string element){

    for (int i = 0; i < container.size();i++) {
        if (element == container[i]) {
            return i;
        }
    }

    return -1;
}


static int binary_search(std::vector<std::string> container, std::string element){
    int length = container.size()-1;
    int lowbound = 0;

    while(lowbound <= length) {
        int mid = ((lowbound + length) / 2);
        if (element == container[mid]) {
            return mid;
        }
        if (element.compare(container[mid]) > 0) {
            lowbound = mid + 1;
        }
        else {
            length=mid-1;
        }
    }
    return -1;
}

int main() {
    std::vector dataset = getStringData();

    //Searches for "not_here"
    //Linear Search
    std::cout << "Finding 'not_here'" << std::endl;
    long long time = systemTimeNanoseconds();
    std::cout << "Index found with the linear search method: " + std::to_string(linear_search(dataset, "not_here")) << std::endl;
    long long time2 = systemTimeNanoseconds();
    std::cout << "Time for this method was: " + std::to_string(time2 - time) << std::endl;
    //Binary Search
    time = systemTimeNanoseconds();
    std::cout << "Index found with the binary search method: " + std::to_string(binary_search(dataset, "not_here")) << std::endl;
    time2 = systemTimeNanoseconds();
    std::cout << "Time for this method was: " + std::to_string(time2 - time) << std::endl;


    //Searches for "mzzzz"
    //Linear Search
    std::cout << "\n\nFinding 'mzzzz'" << std::endl;
    time = systemTimeNanoseconds();
    std::cout << "Index found with the linear search method: " + std::to_string(linear_search(dataset, "mzzzz")) << std::endl;
    time2 = systemTimeNanoseconds();
    std::cout << "Time for this method was: " + std::to_string(time2 - time) << std::endl;
    //std::cout << "test" << std::endl;
    //Binary Search
    time = systemTimeNanoseconds();
    std::cout << "Index found with the binary search method: " + std::to_string(binary_search(dataset, "mzzzz")) << std::endl;
    time2 = systemTimeNanoseconds();
    std::cout << "Time for this method was: " + std::to_string(time2 - time) << std::endl;

    //Searches for "aaaaa"
    //Linear Search
    std::cout << "\n\nFinding 'aaaaa'" << std::endl;
    time = systemTimeNanoseconds();
    std::cout << "Index found with the linear search method: " + std::to_string(linear_search(dataset, "aaaaa")) << std::endl;
    time2 = systemTimeNanoseconds();
    std::cout << "Time for this method was: " + std::to_string(time2 - time) << std::endl;
    //Binary Search
    time = systemTimeNanoseconds();
    std::cout << "Index found with the binary search method: " + std::to_string(binary_search(dataset, "aaaaa")) << std::endl;
    time2 = systemTimeNanoseconds();
    std::cout << "Time for this method was: " + std::to_string(time2 - time) << std::endl;
}

