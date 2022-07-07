#define _CRT_SECURE_NO_WARNINGS
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <cassert>
#include <cstdio>
#include <chrono>
#include <cstdlib>
#include <memory>
#define RING_BUFFER
#ifdef RING_BUFFER
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <memory>
#include <fstream>
using namespace std;

template <class Data>
class InternalDataStorage
{
    struct Information
    {
        uint32_t head = 0;
        uint32_t tail = 0;
    } information;

    std::string path;
    std::ofstream dataSaved;
    std::ifstream dataRead;
    size_t size = 0;
public:
    InternalDataStorage(const std::string& path, size_t size);
    bool push(const Data& data);
    bool pop();
    std::vector<std::shared_ptr<Data>> readBlock(size_t blockSize);
    bool deleteBlock(size_t blockSize);
private:
    bool saveInformation();
    bool openFileToSave();
    bool openFileToRead();
    size_t getCount();
    inline uint32_t getOffset() { return sizeof(Information); }
};

template<class Data>
InternalDataStorage<Data>::InternalDataStorage(const std::string& path, size_t size)
 : path(path), size(size)
{
    if (openFileToRead())
    {
        (void)dataRead.seekg(0, std::ios::beg);
        (void)dataRead.read((char*)(&information), sizeof(Information));
        if (!dataRead.good())
        {
            saveInformation();
        }
    }
}

template<class Data>
bool InternalDataStorage<Data>::push(const Data& data)
{
    if (!openFileToSave())
    {
        return false;
    }
    try
    {
        (void)dataSaved.seekp(getOffset() + information.head * sizeof(Data), std::ios::beg);
        (void)dataSaved.write(reinterpret_cast<const char*>(&data), sizeof(sizeof(Data)));
        if (++information.head >= size) information.head = 0;
        if (information.head == information.tail)
        {
            if (++information.tail >= size) information.tail = 0;
        }
    }
    catch(...)
    {
        return false;
    }
    return saveInformation();//save head-tail to file
}

template<class Data>
bool InternalDataStorage<Data>::pop()
{
    if (information.head == information.tail)
    {
        return true;
    }
    if (++information.tail >= size) information.tail = 0;
    return saveInformation();//save head-tail to file
}

template<class Data>
std::vector<std::shared_ptr<Data>> InternalDataStorage<Data>::readBlock(size_t blockSize)
{
    std::vector<std::shared_ptr<Data>> dataList;
    const auto currentSize = getCount();
    blockSize = blockSize > currentSize ? currentSize : blockSize;
    if (!openFileToRead())
    {
        return dataList;
    }
    try
    {
        auto currentIndex = information.tail;
        dataList.reserve(blockSize);
        for (size_t i = 0; i < blockSize; i++)
        {
            dataList.push_back(std::make_shared<Data>());
            (void)dataRead.seekg(getOffset() + currentIndex * sizeof(Data), std::ios::beg);
            (void)dataRead.read((char*)(dataList.back().get()), sizeof(Data));
            if (++currentIndex >= size) currentIndex = 0;
        }
    }
    catch (const std::bad_alloc& e)
    {
        dataList.resize(dataList.size() > 0 ? dataList.size() - 1 : 0);
    }
    catch (...)
    {
        dataList.resize(dataList.size() > 0 ? dataList.size() - 1 : 0);
    }

    return dataList;
}

template<class Data>
bool InternalDataStorage<Data>::deleteBlock(size_t blockSize)
{
    const auto currentSize = getCount();
    if (blockSize >= currentSize)
    {
        information.head = information.tail;
    }
    else if (information.head > information.tail)
    {
        information.tail += blockSize;
    }
    else
    {
        const auto length = information.tail + blockSize;
        information.tail = length < size ? length : length - size;
    }
    return saveInformation();
}

template<class Data>
bool InternalDataStorage<Data>::saveInformation()
{
    try
    {
        if (openFileToSave())
        {
            if (dataSaved.good()) dataSaved.flush().setf(ios_base::unitbuf);
            (void)dataSaved.seekp(0, std::ios::beg);
            (void)dataSaved.write(reinterpret_cast<char*>(&information), sizeof(information));
            if (dataSaved.good())dataSaved.unsetf(std::ios_base::unitbuf);
            return true;
        }
    }
    catch (...)
    {
    }
    return false;
}

template<class Data>
bool InternalDataStorage<Data>::openFileToSave()
{
    try
    {
        dataSaved.clear();
        if (!dataSaved.is_open())
        {
            dataSaved.exceptions(~ios::goodbit);
            dataSaved.open(path, ios::app | ios::ate);
            dataSaved.close();
            dataSaved.open(path, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
        }
    }
    catch (...)
    {
        return false;
    }
    return  dataSaved.is_open();
}

template<class Data>
bool InternalDataStorage<Data>::openFileToRead()
{
    (void)openFileToSave();
    dataRead.clear();
    if (!dataRead.is_open())
    {
        dataRead.open(path, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
    }
    return dataRead.is_open();
}

template<class Data>
size_t InternalDataStorage<Data>::getCount()
{
    return information.head >= information.tail ? information.head - information.tail : size - information.tail + information.head;
}

int main(void) {
    InternalDataStorage<int> ringBuffer("test.txt", 20);
    for (size_t i = 0; i < 30; i++)
    {
        ringBuffer.push(i);
    }
    auto buffer = ringBuffer.readBlock(50);
    for  ( auto data : buffer)
    {
        std::cout << *data <<" ";
    }
    ringBuffer.deleteBlock(5);
    auto buffer1 = ringBuffer.readBlock(50);
    std::cout << std::endl;
    for (auto data : buffer1)
    {
        std::cout << *data << " ";
    }
    return 0;
}
#endif // RING_BUFFER
#ifdef DEBUG1

struct Data
{
    char value[1024];
};

int main()
{
    // Max size RAM 32 bits = 4GB = 4 * 1024 * 1024 * 1024
    std::vector<Data> buffer;
    try
    {
        buffer.reserve(2 * 1024 * 1024);
    }
    catch (std::bad_alloc & e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "Do nothing" << std::endl;
    }
    std::cout << "buffer size = " << buffer.size() << std::endl;
    return 0;
}
#endif // DEBUG1
#ifdef DEBUG2

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <memory>
#include <fstream>

struct Data
{
    char value[1024];
};

int main()
{
    // Max size RAM 32 bits = 4GB = 4 * 1024 * 1024 * 1024
    std::vector<std::shared_ptr<Data>> buffer;
    try
    {
        constexpr size_t size = 2 * 1024 * 1024;
        buffer.reserve(size);
        for (size_t i = 0; i < size; i++)
        {
            buffer.push_back(std::make_shared<Data>());
        }
    }
    catch (std::bad_alloc& e)
    {
        std::cout << e.what() << std::endl;
        buffer.resize(buffer.size()*1/2); // resize buffer to have more memory for other actions
    }
    std::cout << "buffer size = " << buffer.size()*sizeof(Data) << std::endl;
    return 0;
}
#endif // DEBUG2




